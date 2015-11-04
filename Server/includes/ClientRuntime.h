#ifndef CLIENTRUNTIME_H_
# define CLIENTRUNTIME_H_

# include "NetworkDefines.h"
# include "ClientBase.h"

class ClientRuntime
{
public:
	ClientRuntime(MySocket _listen);
	~ClientRuntime();

private:
	MySocket			_socket;

	bool				_loggedIn;
	std::string			_login;

public:
	bool				isLoggedIn() const;
	void				setLoggedIn(bool isLogged);
	MySocket			getSocket() const;
	std::string			getLogin() const;
	void				setLogin(std::string const& login);
};

#endif