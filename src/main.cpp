#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char ** argv)
{
 // We crate the main event handler. Without this, signals won’t work.
 QApplication app(argc, argv);

 // We create the main widget. It’s a container.
 QWidget *mainWidget = new QWidget(NULL);

 // We create a label and a push button, using convenient constructors
 QLabel *label = new QLabel("Hello world");
 QPushButton *quitButton = new QPushButton("Quit button");

 // We create the main layout. The main parameter for any widget is the
 // parent widget
 QVBoxLayout *layout = new QVBoxLayout(mainWidget);
 // Add the label and the button to the layout widget.
 layout->addWidget(label);
 layout->addWidget(quitButton);

 // Guess what...
 mainWidget->setLayout(layout);

 // MOST IMPORTANT PART
 QApplication::connect(quitButton, SIGNAL(clicked()),
 mainWidget, SLOT(close()));

 // Display the widget. Doing this, the widget is associated with the event
 // loop. Destroying the widget will exit the event loop.
 mainWidget->show();
 // Start the event loop.
 return app.exec();
}