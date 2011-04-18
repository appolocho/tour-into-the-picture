#include <widget.h>

Widget::Widget(QWidget* parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    setFixedSize(400, 400);
}
