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
	for (std::deque<ClientBase*>::iterator it = _base.begin(); it != _base.end(); ++it)
		if ((*it)->getLogin() == str)
		{
			runtime->setBase((*it));
			break;
		}
	runtime->setLogin(str);
}

bool ClientDataHandler::IsRightPassword(std::string const & str, ClientRuntime* runtime)
{
	if (runtime->getLogin() == "" || (runtime->getBase() != NULL && str != runtime->getBase()->getPassword()))
		return false;
	if (runtime->getBase() == NULL)
	{
		_base.push_front(new ClientBase(CONNECTED, _id++, runtime->getLogin(), runtime->getLogin(), str, std::list<int>()));
		runtime->setBase(_base.front());
	}

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
