#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

/*
 This is the main window class for TIP. It will hold all of the widgets and buttons
 to operate the program correctly
*/
class QPushButton;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    QPushButton* quitButton; // button to quit program
    QPushButton* loadBackButton; // button to load background image
    QPushButton* saveButton; // button to save image
    QPushButton* loadForeButton; // button to load foreground objects
    QPushButton* placeVanButton; // button to place vanishing point
    QPushButton* placeBackButton; // button to place background box
};

#endif // WINDOW_H
