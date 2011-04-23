#include <QtGui>
#include "window.h"

Window::Window() : QWidget()
{
    widget = new Widget(this);
    quitButton = new QPushButton(tr("Quit"));
    loadBackButton = new QPushButton(tr("1. Load Background Image"));
    loadForeButton = new QPushButton(tr("4. Load Foreground Image"));
    //saveButton = new QPushButton(tr("Save Image"));
    //placeVanButton =  new QPushButton(tr("2. Place Vanishing Point")); // button to place vanishing point
    //placeBackButton = new QPushButton(tr("3. Specify Back Wall"));

    // connect buttons to functions
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(loadBackButton, SIGNAL(clicked()), this,
            SLOT(chooseBackground()));
    connect(loadForeButton, SIGNAL(clicked()), this,
            SLOT(chooseForeground()));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(widget);
    layout->addWidget(loadBackButton);
    //layout->addWidget(placeVanButton);
    //layout->addWidget(placeBackButton);
    layout->addWidget(loadForeButton);
    //layout->addWidget(saveButton);
    layout->addWidget(quitButton);
    setLayout(layout);

    //resize(800, 600);
    setWindowTitle(tr("Tour Into the Picture - by Ross McDonald"));
}

void Window::chooseBackground()
{
    widget->chooseBackground();
}

void Window::chooseForeground()
{
    widget->chooseForeground();
}

