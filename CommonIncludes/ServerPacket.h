#ifndef SERVERPACKET_H_
# define SERVERPACKET_H_

typedef enum e_ClientStatus
{
	CONNECTED,
	AWAY,
	OFFLINE
}			ClientStatus;

typedef enum                    e_ServerNetworkCommand
{
	OK = 100,
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
	CALL_RQ_REFU = 402
}								ServerNetworkCommand;

typedef struct					s_ServerPacket
{
	int							response;

	union data
	{
		struct					s_getCtInfo
		{
			int					id;
			char				nickname[256];
			ClientStatus		status;

		}						GetCtInfo;

		struct					s_getRequestCallerInfo
		{
			int					id;
		}						RequestCallerInfo;

		struct					s_getCallerInfo
		{
			int					id;
			char				ip[56];
			char				port[56];
		}						GetCallerInfo;

	} data;
}				ServerPacket;

#endif