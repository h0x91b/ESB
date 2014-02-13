var extend = require('extend');
var zmq = require('zmq');
var uuid = require('uuid');
var fs = require("fs")
var proto = require("node-protobuf").Protobuf;
var pb = new proto(fs.readFileSync(__dirname+"/../../proxy-server/src/command.desc"));
var util = require("util");
var events = require("events");
var Redis = require('redis');


var _config = {
	publisherHost: 'h0x91b.il.paragonex.com',
	publisherPort: 7780,
	redisHost: 'esb-redis',
	redisPort: 6379
};

function ESB(config) {
	events.EventEmitter.call(this);
	this.config = extend(true, {}, _config, config);
	this.guid = ('{'+uuid.v4()+'}').toUpperCase();
	this.proxyGuid = '';
	console.log('new ESB %s', this.guid);
	this.responseCallbacks = [];
	this.invokeMethods = [];
	var socket = zmq.socket('req');
	var self = this;
	this.requestSocket = socket;
	this.requestSocket.on('error', function(err){
		console.log('requestSocket error', err);
		self.emit('error', err);
	});
	this.subscribeSocket = zmq.socket('sub');
	this.subscribeSocket.on('error', function(err){
		console.log('subscribeSocket error', err);
		self.emit('error', err);
	});
	this.publisherSocket = zmq.socket('pub');
	this.publisherSocket.on('error', function(err){
		console.log('publisherSocket error', err);
		self.emit('error', err);
	});
	console.log('try to bind', 'tcp://*:'+this.config.publisherPort)
	this.publisherSocket.bindSync('tcp://*:'+this.config.publisherPort);
	
	this.redis = Redis.createClient(this.config.redisPort, this.config.redisHost);
	this.redis.on('error', function(err){
		console.log('redis error', err);
		self.emit('error', err);
	});
	this.connect();
}

util.inherits(ESB, events.EventEmitter);

ESB.prototype.connect= function(){
	var self = this;
	this.redis.zrevrange('ZSET:PROXIES','0', '1', function(err, resp){
		if(err){
			console.log('Cannot get data from registry', err);
			self.emit('error', err);
			return;
		}
		console.log('available proxies: %s',resp.length);
		if(resp.length<1){
			console.log('currently no proxies can be found, wait 1 sec');
			setTimeout(function(){
				self.connect();
			}, 1000);
			return;
		}
		var d = resp.pop().split('#');
		var connectStr = d[1];
		self.proxyGuid = d[0];
		console.log('ESB Node %s connecting to: %s (%s)', self.guid, connectStr, self.proxyGuid);
		self.requestSocket.connect(connectStr);
		console.log('ESB Node %s connected', self.guid);
		self.sendHello();
	});
};

ESB.prototype.sendHello= function() {
	var cmdGuid = ('{'+uuid.v4()+'}').toUpperCase();
	
	var obj = {
		cmd: 'NODE_HELLO',
		payload: this.guid+'#tcp://'+this.config.publisherHost+':'+this.config.publisherPort,
		guid_from: cmdGuid,
		source_proxy_guid: this.guid,
		target_proxy_guid: ''
	}
	var buf = pb.Serialize(obj, "ESB.Command");
	var self = this;
	this.requestSocket.once('message', function(data){
		self.requestSocket.close();
		var respObj = pb.Parse(data, "ESB.Command");
		console.log('got response from Proxy', respObj.payload);
		if(respObj.cmd === 'ERROR') {
			throw new Error(respObj.payload);
		}
		var t = respObj.payload.split('#');
		t = 'tcp://'+t[0]+':'+t[1];
		console.log('connecting to: '+t);
		self.subscribeSocket.on('message', function(data){
			self.onMessage.call(self, data);
		});
		self.subscribeSocket.connect(t);
		console.log('ESB Node %s connected to publisher of ESB Proxy %s', self.guid, self.proxyGuid);
		self.subscribeSocket.subscribe(self.guid);
		//self.proxyGuid = respObj.source_proxy_guid;
		self.emit('ready');
		setInterval(function(){
			self.sendRegistry();
		},1000);
	});
	this.requestSocket.send(buf);
	console.log('NODE_HELLO sended');
};

ESB.prototype.onMessage= function(data) {
	try {
		//console.log('ESB.prototype.onMessage', data);
		data = data.slice(38); //38 sizeof guid in bytes
		var respObj = pb.Parse(data, "ESB.Command");
		//console.log('suscriber got message: ', respObj);
		switch(respObj.cmd)
		{
		case 'INVOKE':
			//console.log('got INVOKE request', respObj);
			var fn = this.invokeMethods[respObj.guid_to].method;
			if(!fn) {
				console.log('can not find such invoke method', respObj, Object.keys(this.invokeMethods));
				break;
			}
			fn(respObj);
			break;
		case 'RESPONSE':
			//console.log('got RESPONSE', respObj);
			var fn = this.responseCallbacks[respObj.guid_to];
			if(fn){
				delete this.responseCallbacks[respObj.guid_to];
				fn(null, JSON.parse(respObj.payload), null);
			} else {
				console.log('callback %s for response not found', respObj.guid_to);
			}
			break;
		case 'PING':
			console.log('got PING request');
			//
			var obj = {
				cmd: 'PONG',
				payload: +new Date,
				guid_to: respObj.guid_from,
				guid_from: this.guid,
			}
			var buf = pb.Serialize(obj, "ESB.Command");
			this.publisherSocket.send(this.guid+buf);
			break;
		case 'ERROR':
			console.log('got ERROR response: ', respObj.payload);
			if(this.responseCallbacks[respObj.guid_to]){
				var fn = this.responseCallbacks[respObj.guid_to];
				fn(respObj.cmd, null, respObj.payload);
			}
			break;
		case 'REGISTER_INVOKE_OK':
			//console.log("REGISTER_INVOKE_OK for %s from Proxy %s", respObj.payload, respObj.source_proxy_guid);
			break;
		default:
			console.log("unknown operation", respObj);
		}
	} catch(e){
		console.log('ERROR while processing message', e);
		console.log(data.toString());
	}
};

ESB.prototype.invoke = function(identifier, data, cb, options){
	options = extend(true, {
		version: 1,
		timeout: 3000
	}, options);
	identifier = identifier+'/v'+options.version;
	//console.log('invoke()', identifier, options, data);
	var isCalled = false;
	var id = null;
	var self = this;
	if(options.timeout>0){
		id = setTimeout(timeoutCb, options.timeout);
		function timeoutCb(){
			if(isCalled) return;
			isCalled = true;
			delete self.responseCallbacks[cmdGuid];
			cb('Timeout', null, 'Timeout triggered by nodeConnector');
		};
	} else
		options.timeout = 0;
	
	var cmdGuid = ('{'+uuid.v4()+'}').toUpperCase();
	//console.log('invoke guid for response', cmdGuid);
	
	this.responseCallbacks[cmdGuid] = function(err, data, errString){
		//console.log('invoke %s get response', cmdGuid, data);
		if(isCalled){
			console.log('got response from Proxy, but callback already was called');
			return;
		}
		isCalled = true;
		if(id) clearTimeout(id);
		delete self.responseCallbacks[cmdGuid];
		//console.log('call response callback');
		cb(err, data, errString);
	}
	
	try {
		var obj = {
			cmd: 'INVOKE',
			identifier: identifier,
			payload: JSON.stringify(data),
			guid_from: cmdGuid,
			target_proxy_guid: this.proxyGuid,
			source_proxy_guid: this.guid,
			start_time: +new Date,
			timeout_ms: options.timeout
		}
		console.log(obj, this.proxyGuid);
		var buf = pb.Serialize(obj, "ESB.Command");
		this.publisherSocket.send(new Buffer(this.proxyGuid+buf));
	} catch(e){
		isCalled = true;
		if(id) clearTimeout(id);
		delete self.responseCallbacks[cmdGuid];
		cb('Exception', null, 'Exception while encoding/sending message: '+e.toString());
	}
	
	return cmdGuid;
};

ESB.prototype.sendRegistry = function(){
	for(var g in this.invokeMethods){
		var m = this.invokeMethods[g];
		this.register(m.identifier, m.version, m.method, m.options);
	}
}

ESB.prototype.register = function(_identifier, version, cb, options) {
	//console.log('register', _identifier, version);
	options = extend(true, {
		version: 1,
		timeout: 3000,
		guid: ('{'+uuid.v4()+'}').toUpperCase()
	}, options);
	var identifier = _identifier+'/v'+options.version;
	
	var cmdGuid = options.guid;
	//console.log('registerInvoke guid:', cmdGuid);
	var self = this;
	if(!this.invokeMethods[cmdGuid])
	{
		//console.log('register', _identifier, version, cmdGuid);
		var invokeMethod = {
			identifier: _identifier,
			guid: cmdGuid,
			version: version,
			options: options
		};
		invokeMethod.method = function(data){
			//console.log('invoke method ', data);
			cb(JSON.parse(data.payload), function(err, resp){
				//console.log('got response from method...', err, resp);
				var obj = {
					cmd: 'RESPONSE',
					payload: JSON.stringify(resp, null, '\t'),
					guid_from: cmdGuid,
					guid_to: data.guid_from,
					target_proxy_guid: self.proxyGuid,
					source_proxy_guid: self.guid,
					start_time: +new Date,
				}
			
				try {
					if(err) {
						obj.cmd = 'ERROR';
						obj.payload = err;
					}
					//console.log('invoke method send response',obj);
					var buf = pb.Serialize(obj, "ESB.Command");
					self.publisherSocket.send(self.proxyGuid+buf);
				} catch(e){
					cb('Exception', null, 'Exception while encoding/sending message: '+e.toString(), resp);
				}
			
			});
		};
		this.invokeMethods[cmdGuid] = invokeMethod;
	}
	try {
		var obj = {
			cmd: 'REGISTER_INVOKE',
			identifier: identifier,
			payload: cmdGuid,
			guid_from: cmdGuid,
			target_proxy_guid: this.proxyGuid,
			source_proxy_guid: this.guid,
			start_time: +new Date,
		}
		//console.log('register',obj);
		var buf = pb.Serialize(obj, "ESB.Command");
		this.publisherSocket.send(this.proxyGuid+buf);
	} catch(e){
		cb('Exception', null, 'Exception while encoding/sending message: '+e.toString());
	}
	
	return cmdGuid;
};

module.exports = ESB;
