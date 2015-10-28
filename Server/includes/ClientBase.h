#ifndef CLIENTBASE_H_
# define CLIENTBASE_H_

# include <string>

class ClientBase
{
public:
	ClientBase(int id, std::string const& nick, std::string const& login, std::string const& password);
	ClientBase(std::string const& login);
	~ClientBase();

private:
	int					_status;
	int					_id;
	std::string			_nick;
	std::string			_login;
	std::string			_password;
	
public:
	void				setStatus(int status);
	int					getStatus() const;
	int					getId() const;
	std::string	const&	getNickname() const;
	std::string	const&	getLogin() const;
	std::string	const&	getPassword() const;
	void				setNickname(std::string const& nickname);
};

#endif