#include "state_game.h"

state_game::state_game()
{
    paddle=new Paddle();
    for(int i=0;i<7;i++)
    {
        block.push_back(new Block());
        if(i!=0)
            block[i]->pos_x=block[i-1]->x()+140;
        else
            block[i]->pos_x=block[i]->x();
    }
    ball=new Ball();
    start=false;
    numb=4;
}

state_game::~state_game()
{
    delete paddle;
    delete ball;
    block.clear();
}

void state_game::paint(QPaintEvent * , GameWidget * widget, QPainter *painter, QTimer *timer)
{
    painter->drawPixmap(0,0,QPixmap(":/new/image/resource/background/Images.png"));
    painter->drawPixmap(paddle->x(),paddle->y(),paddle->image());
    for(int i=0;i<block.size();i++)
    {
        painter->drawPixmap(block[i]->x(),block[i]->y(),block[i]->image());
    }
    paddle->move();
    if(numb>0)
        if(start)
        {
            painter->drawPixmap(ball->x(),ball->y(),ball->image());
            ball->move();
        }
    if(numb==0) {QMessageBox ms; ms.setText("FAIL!");ms.exec(); exit(0);}
    if(ball->minus==true)
    {
        delete ball;
        ball=new Ball();
        numb--;
        ball->minus=false;
        start=false;
    }
    if(paddle->y() < ball->y()+ball->height() &&
            paddle->x() < ball->x() &&
            paddle->x()+paddle->width() > ball->x()+ball->width()){ball->ry=-1;}
    for(int i=0;i<block.size();i++)
    {
        if(block[i]->y()+block[i]->height() == ball->y() &&
                block[i]->x()<=ball->x() &&
                block[i]->x()+block[i]->width() >= ball->x()+ball->width())
        {
            if((i+1)<=block.length())
                block.erase(block.begin()+i);
            ball->ry=-ball->ry;
        }
    }
    for(int i=0;i<block.size();i++)
    {
        if(block[i]->y()== ball->y()+ball->height() &&
                block[i]->x()<=ball->x() &&
                block[i]->x()+block[i]->width() >= ball->x()+ball->width())
        {
            if((i+1)<=block.length())
                block.erase(block.begin()+i);
            ball->ry=-ball->ry;
        }
    }
    for(int i=0;i<block.size();i++)
    {
        if(block[i]->x()==ball->x()+ball->width() &&
                block[i]->y()<=ball->y() &&
                block[i]->y()+block[i]->height()>=ball->y()+ball->height())
        {
            if((i+1)<=block.length())
                block.erase(block.begin()+i);
            ball->rx=-ball->rx;
        }
    }
    for(int i=0;i<block.size();i++)
    {
        if(block[i]->x()+block[i]->width()==ball->x() &&
                block[i]->y()<=ball->y() &&
                block[i]->y()+block[i]->height()>=ball->y()+ball->height())
        {
            if((i+1)<=block.length())
                block.erase(block.begin()+i);
            ball->rx=-ball->rx;
        }
    }
    timer->start(1);
}

void state_game::mouse_click(GameWidget *, QMouseEvent * event)
{

}

void state_game::key_press(GameWidget * widget , QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(0, "Exit", "Do you want to exit?",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            setStage(widget,state_menu::instance());
        }
    }
    if(event->key() == Qt::Key_Left){paddle->keyLeft = true; paddle->keyRight=false;}
    if(event->key() == Qt::Key_Right){paddle->keyRight = true; paddle->keyLeft=false;}
    if(event->key() == Qt::Key_Space && start==false) {start=true; ball->pos_x = paddle->x()+paddle->width()/2;}
}

void state_game::key_release(GameWidget *, QKeyEvent *event)
{

}
