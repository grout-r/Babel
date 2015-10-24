#ifndef UICTRL
# define UICTRL

#include <QApplication>
#include <QObject>
#include <QTimer>
#include <QPushButton>
#include <iostream>
#include "GUI.h"

class UserInterfaceController : public QObject
{
	Q_OBJECT

public:
	UserInterfaceController();
	~UserInterfaceController();
	void						run();
	void						insertNewContact(std::string, int);

private:
	void					connectSlots();

public slots:
	void					connectServerSlot();
	void					call(int);

private:
	QApplication		*_app;
	GUI					*_gui;
};

# endif