#ifndef XMLPARSER_H_
# define XMLPARSER_H_

# include <fstream>
# include <deque>
# include <list>
# include <map>
# include "ClientBase.h"

# define EOL std::string::npos

class XMLParser
{

public:
	XMLParser(std::string const& filename, std::deque<ClientBase*>& queue);
	~XMLParser();

	int						Parser();
	bool						Generator(int maxID);

private:
	std::string					_filename;
	std::ifstream				_file;
	std::deque<ClientBase*>&	_queue;
	std::list<int>				_contact;

	std::string					_buffer;
	int							_maxFD;
	std::string					_nick;
	std::string					_login;
	std::string					_pass;
	int							_id;

private:
	std::string					GetFullPath(std::string const& filename);

	/* PARSER */
	void						EmptyContactList();
	void						GetMaxFd();
	bool						GetClient();
	bool						GetContactList();
	void						getID();
	void						getNickname();
	void						getLogin();
	void						getPassword();

	/* GENERATOR */
	void						WriteMaxID(int maxID, std::ofstream& file);
	void						WriteID(int maxID, std::ofstream& file);
	void						WriteNewClient(ClientBase* data, std::ofstream& file);
	void						WriteNickname(std::string const& nickname, std::ofstream& file);
	void						WriteLogin(std::string const& login, std::ofstream& file);
	void						WritePassword(std::string const& password, std::ofstream& file);
	void						WriteContactList(std::list<int>& cList, std::ofstream& file);

};

#endif
