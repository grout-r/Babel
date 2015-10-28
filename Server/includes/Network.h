#ifndef NETWORK_H_
# define NETWORK_H_

# include "NetworkDefines.h"

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
	virtual bool						sendMessage(const char *msg, MySocket) = 0;
	virtual void						MySelectFunc(MySocket socket, fd_set& readSet) = 0;
	virtual void						ZeroFD(fd_set& fdSet) = 0;
	virtual void						SetFD(MySocket socket, fd_set &fdSet) = 0;
	virtual bool						CheckFdIsSet(MySocket sSocket, fd_set &readSet) = 0;
	virtual std::string					rcvMessage(MySocket) = 0;
	virtual bool						CloseConnection(MySocket) = 0;
};

Network*								getNetworkInstance();

#endif