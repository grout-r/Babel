#include "Core.h"

Core::Core()
{
	_GUImap.emplace(CONNECT, &Core::connectToServer);
	_GUImap.emplace(NICK, &Core::changeNick);
	_GUImap.emplace(CALL, &Core::outcomeCall);
}

Core::~Core()
{

}

void Core::start()
{
	_uictrl = new UserInterfaceController;

	QTimer *timer = new QTimer;
	connect(timer, &QTimer::timeout,
		[=]() { this->events(); });
	timer->start(0);
	
	_uictrl->insertNewContact("Bobby", 1217);
	_uictrl->insertNewContact("Bobbu", 1219);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbette", 1220);
	_uictrl->insertNewContact("Bobbo", 1221);
	//_uictrl->callRequest("Jean jacques");

	_uictrl->run();
}

/* ACCESS TO THE QT LOOP, THIS CODE WILL BE EXECUTED AT ALL ITERATION OF THE PROG*/
void			Core::events()
{
	treatGuiEvents();
}

void Core::treatGuiEvents()
{
	std::queue<GUIEvent>	*queue = _uictrl->getEvents();
	GUIEvent				current;

	while (!queue->empty())
	{
		current = queue->front();
		queue->pop();
		(this->*_GUImap[current.command])(current);
	}
}

void Core::outcomeCall(GUIEvent event)
{
	std::cout << "call" << std::endl;
}

void Core::changeNick(GUIEvent event)
{
	std::cout << "nick" << std::endl;
}

void Core::connectToServer(GUIEvent event)
{
	if (slink.connect(event.ip, event.port) == false)
		_uictrl->connectionError();
	slink.login(event.username);
}
