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

	std::string			_login;
	ClientBase*			_base;

public:
	ClientBase*			getBase() const;
	void				setBase(ClientBase* base);
	MySocket			getSocket() const;
	std::string	const&	getLogin() const;
	void				setLogin(std::string const& login);
};

#endif