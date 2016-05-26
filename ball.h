#ifndef BALL_H
#define BALL_H
#include <QPixmap>
#include "paddle.h"


class Ball
{
public:
    Ball();
    ~Ball(){}
    int x();
    int y();
    int width();
    int height();
    void move();
    QPixmap image();
    int rx;
    int ry;
    bool minus;
    Paddle * paddle;
//private:
    int pos_x;
    int pos_y;
    int p_width;
    int p_height;
    QPixmap img;
};

#endif // BALL_H
