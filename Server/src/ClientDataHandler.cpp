#include "ClientDataHandler.h"

ClientDataHandler::ClientDataHandler(std::string const& filename, int id, std::deque<ClientBase*>& base)
	: _filename(filename), _id(id), _base(base), _bddHandler(new XMLParser(filename, base))
{
	_id = _bddHandler->Parser();
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
			runtime->setBase((*it));/*
			break;*/
		}
	}
	runtime->setLogin(str);
}

bool ClientDataHandler::IsRightPassword(std::string const & str, ClientRuntime* runtime)
{
	if (runtime->getLogin() == "" || (runtime->getBase() != NULL && str != runtime->getBase()->getPassword()))
		return false;
	if (runtime->getBase() == NULL)
	{
		_base.push_front(new ClientBase(CONNECTED, ++_id, runtime->getLogin(), runtime->getLogin(), str, std::list<int>()));
		runtime->setBase(_base.front());
	}
	runtime->setLoggedIn(true);
	return true;
}

ClientBase * ClientDataHandler::GetClientByID(int ID)
{
	for (std::deque<ClientBase*>::iterator it = _base.begin(); it != _base.end(); ++it)
	{
		if ((*it)->getId() == ID)
			return (*it);
	}
	return nullptr;
}

void ClientDataHandler::RefreshBase()
{
	_bddHandler->Generator(_id);
}

MySocket ClientDataHandler::GetSocketById(std::deque<ClientRuntime*>& runtime, int id)
{
	for (std::deque<ClientRuntime*>::iterator it = runtime.begin(); it != runtime.end(); ++it)
	{
		if ((*it)->getBase()->getId() == id)
			return (*it)->getSocket();
	}
	return -1;
}
