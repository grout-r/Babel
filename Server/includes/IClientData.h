#ifndef ICLIENTDATA_H_
# define ICLIENTDATA_H_

# include <string>

class IClientBase
{
public:
	~IClientBase() {}

private:
	int							_id;
	std::string					_nick;
	std::string					_login;
	
public:
};

#endif