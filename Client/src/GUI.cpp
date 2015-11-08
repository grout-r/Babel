#include "GUI.h"
#ifdef _WIN32
#include "Windows.h"
#endif
#include <iostream>

GUI::GUI()
{
	_mainLayout = new QGridLayout;
	_ipAddress = new QLineEdit;
	_port = new QLineEdit;
	_nickname = new QLineEdit;
	_userName = new QLineEdit;
	_passwd = new QLineEdit;
	_connectServer = new QPushButton("Connect");
	_changeNickname = new QPushButton("Set nick");
	_contactListArea = new QScrollArea(this);
	_contactListLayout = new QVBoxLayout;

	_nickname->setPlaceholderText("Default");
	_ipAddress->setPlaceholderText("Host");
	_port->setPlaceholderText("Port");

	_passwd->setEchoMode(QLineEdit::Password);

	_contactListArea->setWidget(new QWidget);
	_contactListArea->setWidgetResizable(true);
	_contactListArea->widget()->setLayout(_contactListLayout);
	_contactListArea->setFixedHeight(200);

	_mainLayout->addWidget(new QLabel("Server IP :"), 0, 0);
	_mainLayout->addWidget(_ipAddress, 0, 1);
	_mainLayout->addWidget(new QLabel("Server port :"), 0, 2);
	_mainLayout->addWidget(_port, 0, 3);
	_mainLayout->addWidget(new QLabel("Username"), 1, 0);
	_mainLayout->addWidget(_userName, 1, 1);
	_mainLayout->addWidget(new QLabel("Password:"), 1, 2);
	_mainLayout->addWidget(_passwd, 1, 3);
	_mainLayout->addWidget(_connectServer, 1, 4);
	_mainLayout->addWidget(new QLabel("Nickname :"), 2, 0);
	_mainLayout->addWidget(_nickname, 2, 1, 1, 3);
	_mainLayout->addWidget(_changeNickname, 2, 4);
	_mainLayout->addWidget(_contactListArea, 3, 0, 1, 4);

	this->setLayout(_mainLayout);
}

GUI::~GUI()
{

}

QPushButton				*GUI::insertNewContact(std::string name, int id)
{
	name = "Call " + name;
	QPushButton *button = new QPushButton(name.c_str());

	if (_contactList.find(id) != _contactList.end())
		return NULL;
	_contactList.emplace(id, button);
	_contactListLayout->addWidget(button);
	return button;
}

void					GUI::deleteContact(int id)
{
	std::map<int, QPushButton*>::iterator	it;

	if (_contactList.find(id) != _contactList.end())
	{
		delete _contactList[id];
		_contactList.erase(id);
	}
}

QPushButton			*GUI::getConnectServerButton()
{
	return (_connectServer);
}

QPushButton * GUI::getNicknameButton()
{
	return (_changeNickname);
}

std::string			GUI::getIp()
{
	return (_ipAddress->text().toStdString());
}


std::string			GUI::getPort()
{
	return (_port->text().toStdString());
}

std::string			GUI::getUsername()
{
	return (_userName->text().toStdString());
}

std::string			GUI::getPasswd()
{
	return (_passwd->text().toStdString());
}

std::string			GUI::getNickname()
{
	return (_nickname->text().toStdString());
}
