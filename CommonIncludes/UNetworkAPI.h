#ifndef UNETWORKAPI_H_
# define UNETWORKAPI_H_

# ifdef __linux__


# include "NetworkAPI.h"

class							UNetworkAPI : public Network
{

public:
	UNetworkAPI();
	~UNetworkAPI();

	bool						initNetwork();
	MyConnectionData*			getAddr(const char * ip, const char * port, int family, int socktype, int protocol, int flags);
	MySocket					MySocketFunc(MyConnectionData*);
	bool						MyConnectFunc(MySocket, MyConnectionData*);
	bool						MyBindFunc(MySocket, MyConnectionData*);
	bool						MyListenFunc(MySocket);
	MySocket					MyAcceptFunc(MySocket);
	bool						sendMessage(const void *, int,  MySocket);
	void						MySelectFunc(MySocket socket, fd_set& readSet, struct timeval *to);
	void						ZeroFD(fd_set& fdSet);
	void						SetFD(MySocket socket, fd_set &fdSet);

	bool						CheckFdIsSet(MySocket sSocket, fd_set &readSet);
	int					rcvMessage(MySocket socket, void* buffer, int size);
	bool						CloseConnection(MySocket socket);
};

# endif

#endif
