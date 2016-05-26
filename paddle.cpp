#include "paddle.h"

Paddle::Paddle()
{
    keyLeft = false;
    keyRight = false;
    p_width = 100;
    p_height = 30;
    pos_x = 450;
    pos_y = 560;
    img.load(":/new/image/resource/game/paddle.png");
}

int Paddle::x()     { return pos_x;}
int Paddle::y()     { return pos_y;}
int Paddle::width()    { return p_width;}
int Paddle::height()   { return p_height;}
QPixmap Paddle::image(){ return img;}

void Paddle::move()
{
    if(keyLeft)
    {
        if(pos_x>0)
        {
            pos_x-=10;
            keyLeft=false;
        }
    }
    if(keyRight)
    {
        if(pos_x<900)
        {
            pos_x+=10;
            keyRight=false;
        }
    }
}
