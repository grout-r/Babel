#pragma once

#include "WindowsNetworkDefines.h"
#include "NetworkAPI.h"
#pragma comment(lib, "ws2_32.lib")



class							WindowsNetworkAPI : public Network
{

public:
	WindowsNetworkAPI();
	~WindowsNetworkAPI();

	bool						initNetwork();
	MyConnectionData*			getAddr(char* ip, char* port, int mode);
	MySocket					MySocketFunc(MyConnectionData*);
	bool						MyConnectFunc(MySocket, MyConnectionData*);
	bool						MyBindFunc(MySocket, MyConnectionData*);
	bool						MyListenFunc(MySocket);
	MySocket					MyAcceptFunc(MySocket);
	bool						sendMessage(char *msg, MySocket);
	std::string					rcvMessage(MySocket);
	bool						closeConnection();
};


