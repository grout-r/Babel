#ifndef UICTRL
# define UICTRL

# include <QApplication>
# include <QObject>
# include <QTimer>
# include <QPushButton>
# include <QMessageBox>
# include <iostream>
# include <queue>
# include "GUI.h"

typedef enum e_GUICommand
{
	CONNECT,
	CALL,
	NICK
}			GUICommand;

typedef struct s_GUIEvent
{
	GUICommand	command;
	int			id;
	std::string nickname;
	std::string username;
	std::string password;
	std::string ip;
	std::string port;
}				GUIEvent;

class UserInterfaceController : public QObject
{
	Q_OBJECT

public:
	UserInterfaceController();
	~UserInterfaceController();

	void						run();
	void						insertNewContact(std::string, int);
	void						deleteContact(int);
	void						connectionError();
	bool						callRequest(std::string);
	std::queue<GUIEvent>*		getEvents();

private:
	void						connectSlots();
public slots:
	void						connectServerSlot();
	void						changeNicknameSlot();
	void						callSlot(int);

private:
	QApplication		*_app;
	GUI					*_gui;
	std::queue<GUIEvent> *_eventQueue;
};

# endif