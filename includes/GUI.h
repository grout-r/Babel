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


private:
	QGridLayout		*_mainLayout;
	QLineEdit		*_ipAddress;
	QLineEdit		*_port;
	QPushButton		*_connectServer;
	QScrollArea		*_contactListArea;
	QVBoxLayout		*_contactListLayout;

public:
	QPushButton		*getConnectServerButton();
	std::string		getIp();
	std::string		getPort();

public:
	QPushButton*	insertNewContact(std::string);
};

#endif