#ifndef INTERCLIENTCOM_H_
# define INTERCLIENTCOM_H_

# include "NetworkAPI.h"
# include "InterClientPacket.h"

class InterClientCom
{
public:
	InterClientCom(std::string& ip, std::string& port);
	InterClientCom(std::string& port);
	~InterClientCom();

private:
	Network*			_network;
	MySocket			_socket;
	MySocket			_peerSocket;

public:
	bool				Connect(std::string& ip, std::string& port);
	bool				Accept(std::string& port);
	bool				TryAccept();
	bool				SendData(InterCPacket *);
	bool				ReceiveData(InterCPacket*) const;
};


#endif