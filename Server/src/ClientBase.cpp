#include "ClientBase.h"

ClientBase::ClientBase(int id, std::string const & nick, std::string const & login, std::string const & password)
	: _status(1), _id(id), _nick(nick), _login(login), _password(password)
{
}

ClientBase::ClientBase(std::string const & login)
{
}

ClientBase::~ClientBase()
{
}

void ClientBase::setStatus(int status)
{
	_status = status;
}

int ClientBase::getStatus() const
{
	return _status;
}

int				 ClientBase::getId() const
{
	return _id;
}

std::string const ClientBase::getNickname() const
{
	return _nick;
}

std::string const ClientBase::getLogin() const
{
	return _login;
}

std::string const ClientBase::getPassword() const
{
	return _password;
}

void ClientBase::setNickname(std::string const & nickname)
{
	_nick = nickname;
}
