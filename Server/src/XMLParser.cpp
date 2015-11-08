#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif
#include "XMLParser.h"

XMLParser::XMLParser(std::string const & filename, std::deque<ClientBase*>& queue)
	: _filename(GetFullPath(filename)), _queue(queue)
{
}

XMLParser::~XMLParser()
{
}

std::string XMLParser::GetFullPath(std::string const& filename)
{
	std::string ret = "";
	char buffer[1024];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	ret = buffer;
	std::string::size_type pos = ret.find_last_of("\\/");
	ret = ret.substr(0, pos);
	pos = ret.find_last_of("\\/");
	ret = ret.substr(0, pos);
	ret.append("\\Server\\Debug\\");
	ret.append(filename);
	return ret;
}

/*
	PARSER
*/

int XMLParser::Parser()
{
	_file = std::ifstream(_filename, std::ios::in);

	if (!_file.is_open())
		return 0;
	GetMaxFd();
	while (GetClient());
	return _maxFD;
}

void XMLParser::GetMaxFd()
{
	if (std::getline(_file, _buffer) && _buffer.find("MAXFD=") != EOL)
	{
		std::string	str = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
		_maxFD = std::atoi(str.c_str());
	}
}

bool XMLParser::GetClient()
{
	if (!std::getline(_file, _buffer) || _buffer.find("<CLIENT>") == EOL)
		return false;
	getID();
	getNickname();
	getLogin();
	getPassword();
	GetContactList();
	ClientBase *b = new ClientBase(OFFLINE, _id, _nick, _login, _pass, _contact);
	_queue.push_back(b);
	if (!std::getline(_file, _buffer) || _buffer.find("</CLIENT>") == EOL)
		return false;
	return true;
}

bool XMLParser::GetContactList()
{
	EmptyContactList();
	if (!std::getline(_file, _buffer) || _buffer.find("<CONTACTLIST>") == EOL)
		return false;
	while (std::getline(_file, _buffer) && _buffer.find("</CONTACTLIST>") == EOL)
	{
		_contact.push_back(std::atoi((std::string(_buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1))).c_str())));
	}
	return true;
}

void	XMLParser::EmptyContactList()
{
	if (!_contact.empty())
		_contact.clear();
}

void XMLParser::getID()
{
	if (std::getline(_file, _buffer) && _buffer.find("ID=") != EOL)
	{
		std::string	str = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
		_id = std::atoi(str.c_str());
	}
}

void XMLParser::getNickname()
{
	if (std::getline(_file, _buffer) && _buffer.find("NICKNAME=") != EOL)
	{
		_nick = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
	}
}

void XMLParser::getLogin()
{
	if (std::getline(_file, _buffer) && _buffer.find("LOGIN=") != EOL)
	{
		_login = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
	}
}

void XMLParser::getPassword()
{
	if (std::getline(_file, _buffer) && _buffer.find("PASSWORD=") != EOL)
	{
		_pass = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
	}
}

/*
	GENERATOR
*/

bool XMLParser::Generator(int maxID)
{
	std::ofstream	file(_filename);

	WriteMaxID(maxID, file);
	for (std::deque<ClientBase*>::iterator it = _queue.begin(); it != _queue.end(); ++it)
	{
		WriteNewClient((*it), file);
	}
	return true;
}

void		XMLParser::WriteMaxID(int maxID, std::ofstream& file)
{
	file << "<MAXFD=" << std::to_string(maxID) << "/>" << std::endl;
}

void		XMLParser::WriteNewClient(ClientBase * data, std::ofstream& file)
{
	file << "<CLIENT>" << std::endl;
	WriteID(data->getId(), file);
	WriteNickname(data->getNickname(), file);
	WriteLogin(data->getLogin(), file);
	WritePassword(data->getPassword(), file);
	WriteContactList(data->getContactList(), file);
	file << "</CLIENT>" << std::endl;
}

void		XMLParser::WriteID(int maxID, std::ofstream& file)
{
	file << "	<ID=" << std::to_string(maxID) << "/>" << std::endl;
}

void XMLParser::WriteNickname(std::string const & nickname, std::ofstream& file)
{
	file << "	<NICKNAME=" << nickname << "/>" << std::endl;
}

void XMLParser::WriteLogin(std::string const & login, std::ofstream& file)
{
	file << "	<LOGIN=" << login << "/>" << std::endl;
}

void XMLParser::WritePassword(std::string const & password, std::ofstream& file)
{
	file << "	<PASSWORD=" << password << "/>" << std::endl;
}

void XMLParser::WriteContactList(std::list<int>& cList, std::ofstream& file)
{
	file << "	<CONTACTLIST>" << std::endl;
	for (std::list<int>::iterator it = cList.begin(); it != cList.end(); ++it)
		file << "		<ID=" << (*it) << "/>" << std::endl;
	file << "	</CONTACTLIST>" << std::endl;
}
