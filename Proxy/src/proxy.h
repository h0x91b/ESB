#ifndef PROXY_H
#define PROXY_H

#include <node.h>
#include <v8.h>
#include <zmq.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
#include <unordered_map>

class Subscriber;
class Publisher;
class Responder;

#include "globals.h"
#include "deps/hiredis/hiredis.h"
#include "requester.h"
#include "responder.h"
#include "publisher.h"
#include "subscriber.h"

struct LocalInvokeMethod
{
	char *identifier;
	char nodeGuid[39];
	char methodGuid[39];
};

struct RemoteInvokeMethod
{
	char *identifier;
	char proxyGuid[39];
};

class Proxy : public node::ObjectWrap {
public:
	static void Init(v8::Handle<v8::Object> exports);
	void SubscriberCallback(ESB::Command &cmdReq, const char *guid);
	ESB::Command ResponderCallback(ESB::Command &cmdReq);
	void Invoke(ESB::Command &cmdReq);
	void RegisterInvoke(ESB::Command &cmdReq);
	void InvokeResponse(ESB::Command &cmdReq, const char *sourceNodeGuid);
	void PingRedis();
	void ConnectToAnotherProxy(const char *proxyGuid, const char *connectionString);
	
	char guid[39];
	Responder *responder;
	Publisher *publisher;
	redisContext *redisCtx;
	int responderPort;
	int publisherPort;
	char host[128];
	
	int invokeCalls = 0;
	int invokeErrors = 0;
	int registerInvoke = 0;
	int lastRedisPing = 0;

private:
	Proxy();
	~Proxy();

	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor;
	void NodeHello(ESB::Command &cmdReq, ESB::Command &cmdResp);
	void ProxyHello(ESB::Command &cmdReq, ESB::Command &cmdResp);
	
	static void *MainLoop(void *p);
	bool isWork;
	pthread_t thread;
	std::vector<std::string> nodesGuids;
	std::unordered_map<std::string,Subscriber*> subscribers;
	std::unordered_map<std::string,std::vector<LocalInvokeMethod*>> localInvokeMethods; //identifier, struct
	std::unordered_map<std::string,RemoteInvokeMethod*> remoteInvokeMethods; //identifier, struct
	std::unordered_map<std::string,std::string*> invokeResponses; //identifier, struct
};



#endif