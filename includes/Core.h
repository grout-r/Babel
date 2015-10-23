#ifndef CORE
# define CORE


#include "UserInterfaceController.h"

class			Core : public QObject
{
public:
	Core();
	~Core();

public:
	void		start();
	void		events();

private:
	UserInterfaceController *uictrl;
};

#endif