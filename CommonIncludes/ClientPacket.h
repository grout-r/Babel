#ifndef CLIENTPACKET
# define CLIENTPACKET

typedef enum e_ClientNetworkCommand
{
	LOGIN,
	PASS,
	NICKNAME,
	GETCINFO,
	GETCLIST,
	RQ_CALL,
	ACPT_CALL,
	REFU_CALL,
}			ClientNetworkCommand;

typedef struct s_ClientPacket
{

	ClientNetworkCommand command;

	union data
	{
		struct LOGIN
		{
			char login[256];
		} login;

		struct PASS
		{
			char passwd[256];
		} pass;

		struct NICKNAME
		{
			char nickname[256];
		} nickname;

		struct GETCTINFO
		{
			int id;
		} getctinfo;

		struct GETCLIST
		{
		} getclist;

		struct RQ_CALL
		{
			int id;
		} rq_call;

		struct ACPT_CALL
		{
			int port;
			int id;
		} acpt_call;

		struct REFU_CALL
		{
			int id;
		};
	} data;
}				ClientPacket;


# endif