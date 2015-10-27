#ifndef GUI_H_
# define GUI_H_

# include <QWidget>
# include <QApplication.h>
# include <QLineEdit>
# include <QGridLayout>
# include <QPushButton>
# include <QLabel>
# include <QObject>
# include <string>
# include <QScrollArea>
# include <QString>
# include <QVBoxLayout>

class GUI : public QWidget
{
public:
	GUI();
	~GUI();

private:
	std::map<int, QPushButton*>		_contactList;

private:
	QGridLayout		*_mainLayout;

	QLineEdit		*_ipAddress;
	QLineEdit		*_port;
	QLineEdit		*_userName;
	QLineEdit		*_passwd;
	QLineEdit		*_nickname;

	QPushButton		*_connectServer;
	QPushButton		*_changeNickname;

	QScrollArea		*_contactListArea;
	QVBoxLayout		*_contactListLayout;

public:
	QPushButton		*getConnectServerButton();
	QPushButton		*getNicknameButton();
	std::string		getIp();
	std::string		getPort();
	std::string		getUsername();
	std::string		getPasswd();
	std::string		getNickname();

public:
	QPushButton*	insertNewContact(std::string, int id);
	void			deleteContact(int id);
};

#endif