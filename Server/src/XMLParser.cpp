#include <iostream>
#include "XMLParser.h"

XMLParser::XMLParser(std::string const & filename)
	: _filename(filename)
{
	std::cout << "START PARSER XML" << std::endl;
	InitFMap();
	Parser();
}

XMLParser::~XMLParser()
{
}

void XMLParser::InitFMap()
{
	/*
	_fMap.emplace("<ID:", &XMLParser::getID);
	_fMap.emplace("<NICKNAME:", &XMLParser::getNickname);
	_fMap.emplace("<LOGIN:", &XMLParser::getLogin);
	_fMap.emplace("<PASSWORD:", &XMLParser::getPassword);
	*/
}

bool XMLParser::Parser()
{
	_file = std::ifstream(_filename, std::ios::in);


	if (!_file.is_open())
		return false;
	std::cout << "SUCCEDED ifstream" << std::endl;
	GetMaxFd();
	while (GetClient());
	return true;
}

void XMLParser::GetMaxFd()
{
	if (std::getline(_file, _buffer) && _buffer.find("MAXFD=") != EOL)
	{
		std::string	str = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
		_maxFD = std::atoi(str.c_str());
	}
	std::cout << "MAX FD: " << _maxFD << std::endl;
}

bool XMLParser::GetClient()
{
	if (!std::getline(_file, _buffer) || _buffer.find("<CLIENT>") == EOL)
		return false;
	std::cout << "inside get client" << std::endl;
	getPassword();
	std::cout << "inside get client" << std::endl;
	getLogin();
	getNickname();
	getID();
	std::cout << "connected client" << std::endl;
	ClientBase *b = new ClientBase(OFFLINE, _id, _nick, _login, _pass);
	_queue.push_back(b);
	std::cout << "getting out client" << std::endl;
	if (!std::getline(_file, _buffer) || _buffer.find("</CLIENT>") == EOL)
		return false;
	return true;
}

void XMLParser::getID()
{
	if (std::getline(_file, _buffer) && _buffer.find("ID=") != EOL)
	{
		std::string	str = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
		_id = std::atoi(str.c_str());
	}
	std::cout << "ID: " << _id << std::endl;
}

void XMLParser::getNickname()
{
	if (std::getline(_file, _buffer) && _buffer.find("NICKNAME=") != EOL)
	{
		_nick = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
	}
	std::cout << "NICKNAME FD: " << _nick << std::endl;

}

void XMLParser::getLogin()
{
	if (std::getline(_file, _buffer) && _buffer.find("LOGIN=") != EOL)
	{
		_login = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
	}
	std::cout << "LOGIN FD: " << _login << std::endl;
}

void XMLParser::getPassword()
{
	if (std::getline(_file, _buffer) && _buffer.find("PASSWORD=") != EOL)
	{
		_pass = _buffer.substr(_buffer.find("=") + 1, _buffer.find("/>") - (_buffer.find("=") + 1));
	}
	std::cout << "PASSWORD FD: " << _pass << std::endl;
}
