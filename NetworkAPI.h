#pragma once

#ifdef _WIN32
#include "WindowsNetworkDefines.h"
#endif

class Network
{
public:
	virtual bool						initNetwork() = 0;
	virtual MyConnectionData*			getAddr(char* ip, char* port, int mode) = 0;
	virtual MySocket					MySocketFunc(MyConnectionData*) = 0;
	virtual bool						MyConnectFunc(MySocket, MyConnectionData*) = 0;
	virtual bool						MyBindFunc(MySocket, MyConnectionData*) = 0;
	virtual bool						MyListenFunc(MySocket) = 0;
	virtual MySocket					MyAcceptFunc(MySocket) = 0;
	virtual bool						sendMessage(const char *msg, MySocket) = 0;
	virtual std::string					rcvMessage(MySocket) = 0;
	virtual bool						closeConnection() = 0;
};

Network*								getNetworkInstance();
