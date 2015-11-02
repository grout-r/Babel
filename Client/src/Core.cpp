#include "Core.h"

/*	OK = 100,
	KO = 101,
	FORBIDDEN = 102,
	STX_ERR = 103,
	AUTH_OK = 200,
	AUTH_KO = 201,
	USER_INFO = 300,
	BEG_CTLIST = 301,
	END_CTLIST = 302,
	INCOM_CALL = 400,
	CALL_RQ_ACPT = 401,
	CALL_RQ_REFU = 402*/

Core::Core()
{
	_GUImap.emplace(CONNECT, &Core::connectToServer);
	_GUImap.emplace(NICK, &Core::changeNick);
	_GUImap.emplace(CALL, &Core::outcomeCall);
	_NetMap.emplace(USER_INFO, &Core::userInfo);
	_NetMap.emplace(INCOM_CALL, &Core::incomeCall);

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
	
	//_uictrl->insertNewContact("Bobby", 1217);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbette", 1220);
	//_uictrl->insertNewContact("Bobbo", 1221);

	_uictrl->run();
}

/* ACCESS TO THE QT LOOP, THIS CODE WILL BE EXECUTED AT ALL ITERATION OF THE PROG*/
void			Core::events()
{
	treatGuiEvents();
	treatNetEvents();
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

void Core::treatNetEvents()
{
	ServerPacket		*pack;

	pack = slink.checkMessage();
	if (pack == NULL)
		return;
	if (_NetMap.find(pack->response) != _NetMap.end())
		(this->*_NetMap[pack->response])(pack);
	delete pack;
}

void Core::outcomeCall(GUIEvent event)
{
	slink.requestCall(event.id);
}

void Core::changeNick(GUIEvent event)
{
	slink.nickname(event.nickname);
}

void Core::connectToServer(GUIEvent event)
{
	if (slink.connect(event.ip, event.port) == false)
		_uictrl->connectionError();
	slink.login(event.username);
	slink.getContactList();
}

void Core::userInfo(ServerPacket *pack)
{
	std::cout << "USER INFO  "  << pack->data.UserInfo.nickname << "   "  << pack->data.UserInfo.status << std::endl;
	if (pack->data.UserInfo.status == CONNECTED)
		_uictrl->insertNewContact(pack->data.UserInfo.nickname, pack->data.UserInfo.id);
	if (pack->data.UserInfo.status == OFFLINE)
		_uictrl->deleteContact(pack->data.UserInfo.id);
}

void Core::incomeCall(ServerPacket *packet)
{
	if (_uictrl->callRequest(packet->data.IncomingCall.) == true)
}

