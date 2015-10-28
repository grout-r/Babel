#ifndef CLIENTDATAHANDLER_H_
# define CLIENTDATAHANDLER_H_

# include <string>
# include <deque>
# include "ClientBase.h"
# include "ClientRuntime.h"

class ClientDataHandler
{
public:
	ClientDataHandler(std::string const& filename, int id);
	~ClientDataHandler();

private:
	std::string					_filename;
	int							_id;

public:
	void						LoginIsSet(std::string const& str, ClientRuntime* runtime, std::deque<ClientBase*>& base);
	bool						IsRightPassword(std::string const& str, ClientRuntime* runtime, std::deque<ClientBase*>& base);
	ClientRuntime*				GetClientByID(std::deque<ClientBase*>& base, int ID);
};

#endif