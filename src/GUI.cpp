#include "GUI.h"

#include "Windows.h"
#include <iostream>

GUI::GUI()
{
	_mainLayout = new QGridLayout;
	_ipAddress = new QLineEdit;
	_port = new QLineEdit;
	_connectServer = new QPushButton("Connect");

	_mainLayout->addWidget(new QLabel("Server IP :"), 0, 0);
	_mainLayout->addWidget(_ipAddress, 0, 1);
	_mainLayout->addWidget(new QLabel("Server port :"), 0, 2);
	_mainLayout->addWidget(_port, 0, 3);
	_mainLayout->addWidget(_connectServer, 0, 4);

	this->setLayout(_mainLayout);
}

GUI::~GUI()
{

}

QPushButton			*GUI::getConnectServerButton()
{
	return (_connectServer);
}

std::string			GUI::getIp()
{
	return (_ipAddress->displayText().toStdString());
}

std::string			GUI::getPort()
{
	return (_port->displayText().toStdString());
}

