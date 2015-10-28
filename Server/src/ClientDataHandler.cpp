#include "ClientDataHandler.h"

ClientDataHandler::ClientDataHandler(std::string const& filename, int id)
	: _filename(filename), _id(id)
{
}

ClientDataHandler::~ClientDataHandler()
{
}

void ClientDataHandler::LoginIsSet(std::string const & str, ClientRuntime* runtime, std::deque<ClientBase*>& base)
{
	for (std::deque<ClientBase*>::iterator it = base.begin(); it != base.end(); ++it)
		if ((*it)->getLogin() == str)
		{
			runtime->setBase((*it));
			break;
		}
	runtime->setLogin(str);
}

bool ClientDataHandler::IsRightPassword(std::string const & str, ClientRuntime* runtime, std::deque<ClientBase*>& base)
{
	if (runtime->getLogin() == "" || (runtime->getBase() != NULL && str != runtime->getBase()->getPassword()))
		return false;
	if (runtime->getBase() == NULL)
	{
		base.push_front(new ClientBase(_id++, runtime->getLogin(), runtime->getLogin(), str));
		std::cout << base.front()->getStatus() << std::endl;
		runtime->setBase(base.front());
	}

	return true;
}
