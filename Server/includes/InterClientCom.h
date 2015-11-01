#ifndef INTERCLIENTCOM_H_
# define INTERCLIENTCOM_H_

# include "Network.h"
# include "InterClientPacket.h"

class InterClientCom
{
public:
	InterClientCom(std::string& ip, std::string& port);
	InterClientCom(std::string& port);
	~InterClientCom();

private:
	Network*			_network;
	InterCPacket*		_packet;
	MySocket			_socket;
	MySocket			_peerSocket;

public:
	bool				Connect(std::string& ip, std::string& port);
	bool				Accept(std::string& port);
	bool				TryAccept();
	bool				SendData(std::string& str);
	InterCPacket*		ReceiveData() const;
};


#endif