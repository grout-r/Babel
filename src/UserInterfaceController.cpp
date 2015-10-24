#include "UserInterfaceController.h"

UserInterfaceController::UserInterfaceController()
{
	

	int i = 1;
	_app = new QApplication(i, NULL);
	_gui = new GUI();
	connectSlots();
	_gui->show();
}

UserInterfaceController::~UserInterfaceController()
{
}

void UserInterfaceController::run()
{
	_app->exec();
}

void UserInterfaceController::insertNewContact(std::string, int id)
{
	QPushButton* button;
	button = _gui->insertNewContact("bob");
	connect(button, &QPushButton::clicked, 
		[=]() { this->call(id); });
}

void					UserInterfaceController::connectSlots()
{
	connect(_gui->getConnectServerButton(), SIGNAL(clicked()), 
			this, SLOT(connectServerSlot()));
}

void UserInterfaceController::call(int id)
{
	std::cout << "CALLING ID #"<< id << std::endl;
}

void			UserInterfaceController::connectServerSlot()
{
	std::string	ip = _gui->getIp();
	std::string port = _gui->getPort();

	std::cout << "CONNECT TO SERVER WITH IP "<< ip << " AND PORT " << port << std::endl;
}
