#include <QtGui>
#include "widget.h"
#include "window.h"

Window::Window()
    : QWidget()
{
    Widget* widget = new Widget(this);
    quitButton = new QPushButton(tr("Quit"));
    loadBackButton = new QPushButton(tr("1. Load Background Image"));
    loadForeButton = new QPushButton(tr("4. Load Foreground Image"));
    saveButton = new QPushButton(tr("Save Image"));
    placeVanButton =  new QPushButton(tr("2. Place Vanishing Point")); // button to place vanishing point
    placeBackButton = new QPushButton(tr("3. Specify Back Wall"));

    // connect quit button to program quit
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(widget);
    layout->addWidget(loadBackButton);
    layout->addWidget(placeVanButton);
    layout->addWidget(placeBackButton);
    layout->addWidget(loadForeButton);
    layout->addWidget(saveButton);
    layout->addWidget(quitButton);
    setLayout(layout);

    //resize(800, 600);
    setWindowTitle(tr("Tour Into the Picture - by Ross McDonald"));
}
