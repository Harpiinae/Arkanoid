#include "ball.h"
#include <QMessageBox>

Ball::Ball()
{
    paddle=new Paddle();
    rx=-1;
    ry=-1;
    p_width = 16;
    p_height = 16;
    pos_x = paddle->x()+paddle->width()/2;
    pos_y = 530;
    img.load(":/new/image/resource/game/Ball.png");
}

int Ball::x()     { return pos_x;}
int Ball::y()     { return pos_y;}
int Ball::width()    { return p_width;}
int Ball::height()   { return p_height;}
QPixmap Ball::image(){ return img;}

void Ball::move()
{
    if(pos_x<0) {rx=1;}
    if(pos_x>984) {rx=-1;}
    if(pos_y<0) {ry=1;}
    if(pos_y>584) {/*QMessageBox ms; ms.setText("FAIL!");ms.exec(); exit(0);*/minus=true;}
    pos_x+=rx;
    pos_y+=ry;
}
