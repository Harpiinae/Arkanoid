#ifndef BLOCK_H
#define BLOCK_H
#include <QPixmap>


class Block
{
public:
    Block();
    ~Block() {}
    int x();
    int y();
    int width();
    int height();
    QPixmap image();
    int rx;
    int ry;
//private:
    int pos_x;
    int pos_y;
    int p_width;
    int p_height;
    QPixmap img;
};

#endif // BLOCK_H
