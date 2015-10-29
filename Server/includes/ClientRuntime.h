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
	ClientBase*			_base;

public:
	bool				isLoggedIn() const;
	void				setLoggedIn(bool isLogged);
	ClientBase*			getBase();
	void				setBase(ClientBase* base);
	MySocket			getSocket() const;
	std::string	const&	getLogin() const;
	void				setLogin(std::string const& login);
};

#endif