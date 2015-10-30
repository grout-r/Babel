#ifndef NETWORK_H_
# define NETWORK_H_

# include "WindowsNetworkDefines.h"

class Network
{
public:
	virtual bool						initNetwork() = 0;
	virtual MyConnectionData*			getAddr(const char * ip, const char * port, int family, int socktype, int protocol, int flags) = 0;
	virtual MySocket					MySocketFunc(MyConnectionData*) = 0;
	virtual bool						MyConnectFunc(MySocket, MyConnectionData*) = 0;
	virtual bool						MyBindFunc(MySocket, MyConnectionData*) = 0;
	virtual bool						MyListenFunc(MySocket) = 0;
	virtual MySocket					MyAcceptFunc(MySocket) = 0;
	virtual bool						sendMessage(const void *, int,  MySocket) = 0;
	virtual int							rcvMessage(MySocket socket, void*buffer, int size) = 0;
	virtual bool						closeConnection(MySocket socket) = 0;
};

Network*								getNetworkInstance();

#endif