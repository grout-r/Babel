#ifndef CORE
# define CORE

//#include <Windows.h>
#include <map>
#include "UserInterfaceController.h"
#include "ServerLink.h"
#include "InterClientCom.h"

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
	void		incomeCall(ServerPacket*);
	void		acceptedCall(ServerPacket*);
	void		audioCom();

private:
	UserInterfaceController *_uictrl;
	ServerLink				_slink;
	InterClientCom			_intercom;
	bool					_isCommunicate;

private:
	std::map<GUICommand, GUIFuncptr>	_GUImap;
	std::map<int, NetFuncptr>			_NetMap;
};

#endif