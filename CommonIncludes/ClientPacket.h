#ifndef CLIENTPACKET
#define CLIENTPACKET

typedef enum                    e_ClientNetworkCommand
{
	AUTH = 10,
	NICKNAME = 12,
	GETCINF = 14,
	GETCLIST = 16,
	RQ_CALL = 18,
	ACPT_CALL = 20,
	REFU_CALL = 22,
}                               ClientNetworkCommand;

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
			char ip[56];
			int id;
		} acpt_call;

		struct REFU_CALL
		{
			int id;
		};
	} data;
}				ClientPacket;


#endif	/* !CLIENTPACKET */