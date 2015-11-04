#include "ClientRuntime.h"

ClientRuntime::ClientRuntime(MySocket listen)
	: _socket(listen), _loggedIn(false), _login("")
{
}

ClientRuntime::~ClientRuntime()
{
	//if (GetBaseClient(_login) != NULL)
	//{
	//	_base->setClientStatus(OFFLINE);
	//	delete _base;
	//}
}

MySocket ClientRuntime::getSocket() const
{
	return _socket;
}

std::string		ClientRuntime::getLogin() const
{
	return _login;
}

void ClientRuntime::setLogin(std::string const & login)
{
	_login = login;
}

bool	ClientRuntime::isLoggedIn() const
{
	return _loggedIn;
}

void				ClientRuntime::setLoggedIn(bool isLogged)
{
	_loggedIn = isLogged;
}