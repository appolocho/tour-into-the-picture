#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGLWidget>

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent);
    void chooseBackground();
    void chooseForeground();

private:
    QImage logo;
    QImage imageForeground;
    QImage imageBackground;
    QPoint imagePos(const QImage &image) const;
    void chooseImage(const QString &title, QImage *image);
    void loadImage(const QString &fileName, QImage *image);
};

#endif // WIDGET_H
