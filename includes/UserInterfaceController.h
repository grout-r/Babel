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

private:
	void					connectSlots();

public slots:
	void					connectServerSlot();


private:
	QApplication		*_app;
	GUI					*_gui;
};

# endif