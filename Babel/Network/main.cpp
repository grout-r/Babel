#include	"NetworkAPI.h"


void		startClient()
{
	Network* net = getNetworkInstance();
	MySocket			socket;
	MyConnectionData	*conData;

	net->initNetwork();
	conData = net->getAddr("127.0.0.1", "4242", MODE_CLIENT);
	socket = net->MySocketFunc(conData);
	net->MyConnectFunc(socket, conData);
	net->sendMessage("salut", socket);
	std::cout << net->rcvMessage(socket) << std::endl;

}

void		startServer()
{
	Network* net = getNetworkInstance();

	MySocket			ListenSocket;
	MySocket			ClientSocket;
	MyConnectionData	*conData;

	net->initNetwork();
	conData = net->getAddr("127.0.0.1", "4242", MODE_SERVER);
	ListenSocket = net->MySocketFunc(conData);
	net->MyBindFunc(ListenSocket, conData);
	net->MyListenFunc(ListenSocket);
	ClientSocket = net->MyAcceptFunc(ListenSocket);
	net->sendMessage("salut", ClientSocket);
	std::cout << net->rcvMessage(ClientSocket) << std::endl;
}

int			main()
{
	startServer();
}