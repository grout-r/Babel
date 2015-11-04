#include "ClientDataHandler.h"

ClientDataHandler::ClientDataHandler(std::string const& filename, int id, std::deque<ClientBase*>& base)
	: _filename(filename), _id(id), _base(base), _bddHandler(new XMLParser(filename, base))
{/*
	_id = _bddHandler->Parser();*/
}

ClientDataHandler::~ClientDataHandler()
{
}

void ClientDataHandler::LoginIsSet(std::string const & str, ClientRuntime* runtime)
{
	std::cout << "queue length : " << _base.size() << std::endl;
	for (std::deque<ClientBase*>::iterator it = _base.begin(); it != _base.end(); ++it)
	{
		std::cout << "login : " << (*it)->getLogin() << std::endl;
		if ((*it)->getLogin() == str)
		{
			(*it)->setClientStatus(CONNECTED);
			//break;
		}
	}
	runtime->setLogin(str);
}

bool ClientDataHandler::IsRightPassword(std::string const & str, ClientRuntime* runtime)
{
	if (runtime->getLogin() == "" || (GetBaseClient(runtime) != NULL && str != GetBaseClient(runtime)->getPassword()))
		return false;
	if (GetBaseClient(runtime) == NULL)
	{
		_base.push_front(new ClientBase(CONNECTED, ++_id, runtime->getLogin(), runtime->getLogin(), str, std::list<int>()));
	}
	runtime->setLoggedIn(true);
	return true;
}

ClientBase * ClientDataHandler::GetBaseClient(std::string login)
{
	for (std::deque<ClientBase*>::iterator it = _base.begin(); it != _base.end(); ++it)
	{
		if ((*it)->getLogin() == login)
			return (*it);
	}
	return NULL;
}

ClientBase*					ClientDataHandler::GetBaseClient(ClientRuntime* runtime)
{
	for (std::deque<ClientBase*>::iterator it = _base.begin(); it != _base.end(); ++it)
	{
		if ((*it)->getNickname() == runtime->getLogin())
			return (*it);
	}
	return NULL;
}

void ClientDataHandler::RefreshBase()
{
	_bddHandler->Generator(_id);
}

MySocket ClientDataHandler::GetSocketById(std::deque<ClientRuntime*>& runtime, int id)
{
	for (std::deque<ClientRuntime*>::iterator it = runtime.begin(); it != runtime.end(); ++it)
	{
		if (GetBaseClient((*it))->getId() == id)
			return (*it)->getSocket();
	}
	return -1;
}
