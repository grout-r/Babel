#ifndef SERVER_H_
# define SERVER_H_

# include <string>
# include <deque>
# include <map>
# include <vector>
# include <sys/types.h>
# include "Network.h"
# include "ClientBase.h"
# include "ClientDataHandler.h"
# include "ClientRuntime.h"

class Server;

typedef void (Server::*FPTR)(ClientRuntime* client, std::string& command);

class Server
{

public:
	Server(std::string const& ip, std::string const& port);
	~Server();

private:
	Network*						_network;
	ClientDataHandler*				_dataHandler;
	std::deque<ClientBase*>			_dataBase;
	std::deque<ClientRuntime*>		_dataRuntime;
	int								_baseID;
	std::map<std::string, FPTR>		_funcMap;
	std::vector<std::string>		_keyVector;
	std::string						_ip;
	std::string						_port;
	MySocket						_listen;
	MySocket						_maxFd;
	fd_set							_readSet;

private:
	void							InitFuncMap();
	bool							InitNetwork();
	void							Start();
	void							SetClientFD();
	MySocket						TryAcceptClient();
	bool							CheckCommand(std::string& str);
	void							CheckClientQueue();
	void							CloseClient(ClientRuntime* c);
	void							StartNewClient();
	void							CommandParser(ClientRuntime* client, std::string& input);

	void							GetCInfo(ClientRuntime* client);


	/* BUILTIN */
	void							Login(ClientRuntime* client, std::string& command);
	void							Password(ClientRuntime* client, std::string& command);
	void							Nick(ClientRuntime* client, std::string& command);
	void							GetCList(ClientRuntime* client, std::string& command);
	void							RequestCall(ClientRuntime* client, std::string& command);
	void							AcceptCall(ClientRuntime* client, std::string& command);
	void							RefuseCall(ClientRuntime* client, std::string& command);
};

#endif