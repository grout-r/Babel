#include "Core.h"

Core::Core()
{
}

Core::~Core()
{

}

void Core::start()
{
	uictrl = new UserInterfaceController;

	QTimer *timer = new QTimer;
	connect(timer, &QTimer::timeout, 
		[=]() { this->events(); });
	timer->start(0);
	uictrl->run();
}

/* ACCESS TO THE QT LOOP, THIS CODE WILL BE EXECUTED AT ALL ITERATION OF THE PROG*/
void			Core::events()
{

}
