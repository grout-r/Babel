#ifndef SERVER_H_
# define SERVER_H_

# include <string>
# include <deque>
# include <map>
# include <cstring>
# include <vector>
# include <sys/types.h>
# include "NetworkAPI.h"
# include "ClientBase.h"

# include "ClientDataHandler.h"
# include "ClientRuntime.h"
# include "ClientPacket.h"
# include "ServerPacket.h"

#ifdef __linux__
#define INVALID_SOCKET -1
#endif


class Server;

typedef void (Server::*FPTR)(ClientRuntime* client);

class Server
{

public:
	Server(std::string const& ip, std::string const& port);
	~Server();

private:
	Network*								_network;
	ClientPacket*							_cPacket;
	ServerPacket*							_sPacket;
	std::deque<ClientBase*>					_dataBase;
	std::deque<ClientRuntime*>				_dataRuntime;
	ClientDataHandler*						_dataHandler;
	int										_baseID;
	std::map<ClientNetworkCommand, FPTR>					_funcMap;
	std::vector<ClientNetworkCommand>		_keyVector;
	std::string								_ip;
	std::string								_port;
	MySocket								_listen;
	MySocket								_maxFd;
	fd_set									_readSet;

private:
	void									InitFuncMap();
	bool									InitNetwork();
	void									Start();
	void									SetClientFD();
	MySocket								TryAcceptClient();
	bool									CheckCommand(ClientNetworkCommand);
	void									CheckClientQueue();
	void									CloseClient(std::deque<ClientRuntime*>::iterator& it, ClientRuntime* c);
	void									StartNewClient();
	void									CommandParser(ClientRuntime* client);
	void									NoticeClientLeft(ClientRuntime* client);

	void									GetCInfo(ClientBase* client, MySocket socket);


	/* BUILTIN */
	void									Login(ClientRuntime* client);
	void									Nick(ClientRuntime* client);
	void									GetCList(ClientRuntime* client);
	void									RequestCall(ClientRuntime* client);
	void									AcceptCall(ClientRuntime* client);
	void									RefuseCall(ClientRuntime* client);
};

#endif
