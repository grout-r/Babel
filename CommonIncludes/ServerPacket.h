#ifndef SERVERPACKET_H_
# define SERVERPACKET_H_

typedef enum e_ClientStatus
{
	CONNECTED,
	AWAY,
	OFFLINE
}			ClientStatus;

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