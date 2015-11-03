#ifndef CLIENTDATAHANDLER_H_
# define CLIENTDATAHANDLER_H_

# include <string>
# include <deque>
# include "ClientBase.h"
# include "ClientRuntime.h"
# include "XMLParser.h"

class ClientDataHandler
{
public:
	ClientDataHandler(std::string const& filename, int id, std::deque<ClientBase*>& base);
	~ClientDataHandler();

private:
	std::string					_filename;
	int							_id;
	std::deque<ClientBase*>&	_base;
	XMLParser*					_bddHandler;

public:
	void						LoginIsSet(std::string const& str, ClientRuntime* runtime);
	bool						IsRightPassword(std::string const& str, ClientRuntime* runtime);
	ClientBase*					GetClientByID(int ID);
	void						RefreshBase();
	MySocket					GetSocketById(std::deque<ClientRuntime*>& runtime, int id);
};

#endif