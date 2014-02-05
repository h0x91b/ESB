var extend = require('extend');
var zmq = require('zmq');
var uuid = require('uuid');
var fs = require("fs")
var proto = require("node-protobuf").Protobuf;
var pb = new proto(fs.readFileSync(__dirname+"/../../Proxy/src/command.desc"));


var _config = {
	host: 'localhost',
	port: 7770
};

function ESB(config) {
	this.config = extend(true, {}, _config, config);
	this.guid = uuid.v4();
	console.log('new ESB %s', this.guid);
	this.responseCallbacks = [];
	var socket = zmq.socket('req');
	this.requestSocket = socket;
	this.subscribeSocket = zmq.socket('sub');
	
	this.connect();
}

ESB.prototype = {
	connect: function(){
		var connectStr = 'tcp://'+this.config.host+':'+this.config.port
		console.log('ESB %s connecting to: %s', this.guid, connectStr);
		this.requestSocket.connect(connectStr);
		console.log('ESB %s connected', this.guid);
		this.sendHello();
	},
	sendHello: function() {
		var cmdGuid = ('{'+uuid.v4()+'}').toUpperCase();
		
		var obj = {
			cmd: 'NODE_HELLO',
			payload: 'tcp://127.0.0.1:7780',
			guid_from: cmdGuid
		}
		var buf = pb.Serialize(obj, "ESB.Command") // you get Buffer here, send it via socket.write, etc.
		var self = this;
		this.requestSocket.once('message', function(data){
			self.requestSocket.close();
			var respObj = pb.Parse(data, "ESB.Command");
			console.log('got response from Proxy', respObj);
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
			console.log('connected');
			self.subscribeSocket.subscribe('');
		});
		this.requestSocket.send(buf);
	},
	onMessage: function(data) {
		try {
			var respObj = pb.Parse(data, "ESB.Command");
			console.log('suscriber got message: ', respObj);
		} catch(e){
			console.log('ERROR while decoding message', e);
		}
	}
};

module.exports = ESB;
