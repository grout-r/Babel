#ifndef CLIENTPACKET
#define CLIENTPACKET

typedef enum e_ClientNetworkCommand
{
	AUTH,
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
		struct					s_Auth
		{
			char username[56];
			char password[56];
		}						Auth;

		struct					s_Nick
		{
			char nick[256];
		}						Nick;

		struct					s_getCtInfo
		{
			int id;
		}						GetCtInfo;

		struct					s_getCList
		{
		}						GetCList;

		struct s_RqCalll
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


#endif	/* !CLIENTPACKET */