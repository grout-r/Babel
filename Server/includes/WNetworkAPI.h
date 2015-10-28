#ifndef WNETWORKAPI_H_
# define WNETWORKAPI_H_

# ifdef _WIN32

# include "NetworkDefines.h"
# include "Network.h"
# pragma comment(lib, "ws2_32.lib")

class							WindowsNetworkAPI : public Network
{

public:
	WindowsNetworkAPI();
	~WindowsNetworkAPI();

	bool						initNetwork();
	MyConnectionData*			getAddr(const char * ip, const char * port, int family, int socktype, int protocol, int flags);
	MySocket					MySocketFunc(MyConnectionData*);
	bool						MyConnectFunc(MySocket, MyConnectionData*);
	bool						MyBindFunc(MySocket, MyConnectionData*);
	bool						MyListenFunc(MySocket);
	MySocket					MyAcceptFunc(MySocket);
	bool						sendMessage(const char *msg, MySocket);

	void						MySelectFunc(MySocket socket, fd_set& readSet);
	void						ZeroFD(fd_set& fdSet);
	void						SetFD(MySocket socket, fd_set &fdSet);

	bool						CheckFdIsSet(MySocket sSocket, fd_set &readSet);


	std::string					rcvMessage(MySocket);
	bool						CloseConnection(MySocket);
};

#endif

#endif