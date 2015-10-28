#include "UserInterfaceController.h"

UserInterfaceController::UserInterfaceController()
{
	int i = 1;
	_app = new QApplication(i, NULL);
	_gui = new GUI();
	_eventQueue = new std::queue<GUIEvent>;
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

void UserInterfaceController::insertNewContact(std::string name, int id)
{
	QPushButton* button;
	button = _gui->insertNewContact(name, id);
	connect(button, &QPushButton::clicked, 
		[=]() { this->callSlot(id); });
}

void					UserInterfaceController::deleteContact(int id)
{
	_gui->deleteContact(id);
}

void UserInterfaceController::connectionError()
{
	QMessageBox::information(NULL, 
		"Error", "Server can't be reached \\ invalid credentials");
}

bool UserInterfaceController::callRequest(std::string name)
{
	int ret = QMessageBox::question(NULL, 
		"Incoming call", 
		QString(std::string(name + " is calling!\nHang out ?").c_str()),
		QMessageBox::Yes | QMessageBox::No);
	if (ret == QMessageBox::Yes)
		return true;
	return false;
}

std::queue<GUIEvent>* UserInterfaceController::getEvents()
{
	return _eventQueue;
}

void					UserInterfaceController::connectSlots()
{
	connect(_gui->getConnectServerButton(), SIGNAL(clicked()), 
			this, SLOT(connectServerSlot()));
	connect(_gui->getNicknameButton(), SIGNAL(clicked()),
		this, SLOT(changeNicknameSlot()));
}

void UserInterfaceController::changeNicknameSlot()
{
	std::string nickname = _gui->getNickname();

	_eventQueue->emplace(GUIEvent{ NICK, -1, nickname });

}

void UserInterfaceController::callSlot(int id)
{
	_eventQueue->emplace(GUIEvent {CALL, id} );
}

void			UserInterfaceController::connectServerSlot()
{
	std::string	username = _gui->getUsername();
	std::string	passwd = _gui->getPasswd();
	std::string	ip = _gui->getIp();
	std::string port = _gui->getPort();

	_eventQueue->emplace(GUIEvent{ CONNECT, -1, "", username, passwd, ip, port });
}
