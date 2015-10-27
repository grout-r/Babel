#include "ClientRuntime.h"

ClientRuntime::ClientRuntime(MySocket listen)
	: _socket(listen), _login(""), _base(NULL)
{
}

ClientRuntime::~ClientRuntime()
{
	if (_base)
	{
		_base->setStatus(0);
		delete _base;
	}
}

ClientBase* ClientRuntime::getBase() const
{
#ifdef _WIN32
	return (_base != nullptr ? _base : nullptr);
#elif __linux__
	return (_base != NULL ? _base : NULL);
#endif
}

void ClientRuntime::setBase(ClientBase * base)
{
	_base = base;
}

MySocket ClientRuntime::getSocket() const
{
	return _socket;
}

std::string	const&	ClientRuntime::getLogin() const
{
	return _login;
}

void ClientRuntime::setLogin(std::string const & login)
{
	_login = login;
}

