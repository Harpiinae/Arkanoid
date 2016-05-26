#ifndef PADDLE_H
#define PADDLE_H
#include <QPixmap>


class Paddle
{
public:
    Paddle();
    ~Paddle(){}
    int x();
    int y();
    int width();
    int height();
    void move();
    QPixmap image();
    bool keyLeft;
    bool keyRight;
private:
    int pos_x;
    int pos_y;
    int p_width;
    int p_height;
    QPixmap img;
};

#endif // PADDLE_H
