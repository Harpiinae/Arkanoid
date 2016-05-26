#include "block.h"

Block::Block()
{
    rx=125;
    ry=30;
    p_width = 125;
    p_height = 30;
    pos_x = 15;
    pos_y = 50;
    img.load(":/new/image/resource/game/block.png");
}

int Block::x()     { return pos_x;}
int Block::y()     { return pos_y;}
int Block::width()    { return p_width;}
int Block::height()   { return p_height;}
QPixmap Block::image(){ return img;}

