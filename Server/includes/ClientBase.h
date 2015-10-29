#ifndef CLIENTBASE_H_
# define CLIENTBASE_H_

# include <string>
# include "ServerPacket.h"

class ClientBase
{
public:
	ClientBase(ClientStatus status, int id, std::string const& nick, std::string const& login, std::string const& password);
	ClientBase(std::string const& login);
	~ClientBase();

private:
	ClientStatus				_status;
	int							_id;
	std::string					_nick;
	std::string					_login;
	std::string					_password;
	
public:
	int							getId() const;
	std::string					getNickname() const;
	std::string	const&			getLogin() const;
	std::string	const&			getPassword() const;
	ClientStatus				getClientStatus() const;
	void						setClientStatus(ClientStatus status);
	void						setNickname(std::string const& nickname);
};

#endif