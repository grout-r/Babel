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
	MyConnectionData*			getAddr(char * ip, char * port, int family, int socktype, int protocol, int flags);
	MySocket					MySocketFunc(MyConnectionData*);
	bool						MyConnectFunc(MySocket, MyConnectionData*);
	bool						MyBindFunc(MySocket, MyConnectionData*);
	bool						MyListenFunc(MySocket);
	MySocket					MyAcceptFunc(MySocket);
	bool						sendMessage(const char *msg, MySocket);
	void						MySelectFunc(MySocket socket, fd_set &fdSet);
	std::string					rcvMessage(MySocket);
	bool						closeConnection();
};

# endif

#endif