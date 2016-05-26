#ifndef MAIN_CLASS
#define MAIN_CLASS

#include <QPixmap>
#include <QDebug>

class Abstract_class
{
public:
    qreal x, y;
    QPixmap pixmap;
    void setPos(qreal posx, qreal posy)
    {
        x = posx;
        y = posy;
    }
};

#endif // MAIN_CLASS

