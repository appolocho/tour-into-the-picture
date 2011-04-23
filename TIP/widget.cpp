#include <widget.h>
#include <QtGui>

static const QSize resultSize(640, 480);

Widget::Widget(QWidget* parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    loadImage(":/Images/opengllogo.png", &logo);
    setFixedSize(640, 480);
    repaint();
}

void Widget::chooseBackground()
{
    chooseImage(tr("Choose Background Image"), &imageBackground);
}

void Widget::chooseForeground()
{
    chooseImage(tr("Choose Foreground Image"), &imageForeground);
}

void Widget::chooseImage(const QString &title, QImage *image)
{
    QString fileName = QFileDialog::getOpenFileName(this, title);
    if (!fileName.isEmpty())
        loadImage(fileName, image);
}

void Widget::loadImage(const QString &fileName, QImage *image)
{
    image->load(fileName);

    QImage fixedImage(resultSize, QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&fixedImage);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(fixedImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(imagePos(*image), *image);
    painter.end();

    *image = fixedImage;
    repaint();
}

QPoint Widget::imagePos(const QImage &image) const
{
    return QPoint((resultSize.width() - image.width()) / 2,
                  (resultSize.height() - image.height()) / 2);
}
