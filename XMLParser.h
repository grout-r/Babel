#ifndef XMLPARSER_H_
# define XMLPARSER_H_

# include <fstream>
# include <deque>
# include <map>
# include "ClientBase.h"

# define EOL std::string::npos


class XMLParser
{/*
	typedef void(XMLParser::*FCT)(void);*/

public:
	XMLParser(std::string const& filename);
	~XMLParser();

private:
	std::string					_filename;
	std::ifstream				_file;
	std::deque<ClientBase*>		_queue;/*
	std::map<std::string, FCT>	_fMap;*/

	std::string					_buffer;
	int							_maxFD;
	std::string					_nick;
	std::string					_login;
	std::string					_pass;
	int							_id;
public:
	void						InitFMap();

	/* PARSER */
	bool						Parser();
	void						GetMaxFd();
	bool						GetClient();
	void							getID();
	void			getNickname();
	void			getLogin();
	void			getPassword();

	/* LEXER */
	bool						Lexer();

};

#endif