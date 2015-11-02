#ifndef CORE
# define CORE

//#include <Windows.h>
#include <map>
#include "UserInterfaceController.h"
#include "ServerLink.h"

class			Core : public QObject
{

typedef void (Core::*GUIFuncptr)(GUIEvent);
typedef void (Core::*NetFuncptr)(ServerPacket*);

public:
	Core();
	~Core();

public:
	void		start();
	void		events();

private:
	void		treatGuiEvents();
	void		treatNetEvents();
	void		outcomeCall(GUIEvent);
	void		changeNick(GUIEvent);
	void		connectToServer(GUIEvent);
	void		userInfo(ServerPacket*);

private:
	UserInterfaceController *_uictrl;
	ServerLink				slink;

private:
	std::map<GUICommand, GUIFuncptr> _GUImap;
	std::map<int, NetFuncptr> _NetMap;
};

#endif