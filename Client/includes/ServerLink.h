#ifndef SERVERLINK
# define SERVERLINK

# include "NetworkAPI.h"
# include "ClientPacket.h"
# include "ServerPacket.h"

/*
virtual bool						initNetwork() = 0;
virtual MyConnectionData*			getAddr(const char * ip, const char * port, int family, int socktype, int protocol, int flags) = 0;
virtual MySocket					MySocketFunc(MyConnectionData*) = 0;
virtual bool						MyConnectFunc(MySocket, MyConnectionData*) = 0;
virtual bool						MyBindFunc(MySocket, MyConnectionData*) = 0;
virtual bool						MyListenFunc(MySocket) = 0;
virtual MySocket					MyAcceptFunc(MySocket) = 0;
virtual bool						sendMessage(const char *msg, MySocket) = 0;
virtual void						MySelectFunc(MySocket socket) = 0;
virtual std::string					rcvMessage(MySocket) = 0;
virtual bool						closeConnection() = 0;
*/
class			ServerLink
{
public:
	ServerLink();
	~ServerLink();

public:
	bool		connect(std::string, std::string);
	bool		login(std::string);
	bool		nickname(std::string);
	bool		getContactList();
	bool		requestCall(int);
	bool		sendTestMessage(std::string);
	bool		checkResponse();
	bool		sendResponseToCall(bool);
	ServerPacket*		checkMessage();

private:
	Network		*_net;
	MySocket	_serverSocket;
	MyConnectionData	*_conData;
};

#endif