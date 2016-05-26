#include "state_menu.h"
#include "state_game.h"
#include "state_load.h"
#include "state_score.h"

state_menu::state_menu()
{
    button=0;
}

state_menu::~state_menu()
{

}

void state_menu::paint(QPaintEvent *, GameWidget *widget, QPainter *painter, QTimer *timer)
{
    widget->setCursor(Qt::ArrowCursor);
    painter->drawPixmap(0,0,QPixmap(":/new/image/resource/menu/menu.png"));
    painter->drawPixmap(100,20,QPixmap(":/new/image/resource/menu/Arkanoid.png"));
    QPoint position = widget->mapFromGlobal(cursor->pos());
    if(position.ry() > 320 && position.ry() < 360 && position.rx()>300 &&  position.rx()<700)
       {button = 1;mouse=true;}
       else if(position.ry() > 380 && position.ry() < 420 && position.rx()>300 &&  position.rx()<700)
           {button= 2;mouse=true;}
       else if(position.ry() > 440 && position.ry() < 480 && position.rx()>300 &&  position.rx()<700)
           {button = 3;mouse=true;}
       else {if(mouse)button = 0;mouse=false;}
       switch(button)
       {
           case 1:painter->drawPixmap(220,310,QPixmap(":/new/image/resource/menu/Arrow.png"));;break;
           case 2:painter->drawPixmap(220,370,QPixmap(":/new/image/resource/menu/Arrow.png"));;break;
           case 3:painter->drawPixmap(220,430,QPixmap(":/new/image/resource/menu/Arrow.png"));;break;
       }
    timer->start(30);
}

void state_menu::key_press(GameWidget* widget,QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_Down:
        {
            switch(button)
            {
                case 0: button =1;break;
                case 1: button =2;break;
                case 2: button =3;break;
                case 3: button =1;break;
            }
            break;
        }
        case Qt::Key_Up:
        {
            switch(button)
            {
                case 0: button =1;break;
                case 1: button =3;break;
                case 2: button =1;break;
                case 3: button =2;break;

            }
            break;
        }
        case Qt::Key_Return:
        {
            switch(button)
            {
                case 1: setStage(widget,state_game::instance());break;
                case 2: setStage(widget,state_score::instance());break;
                case 3: widget->close();break;
            }
            break;
        }
        case Qt::Key_Escape:
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(0, "Exit", "Do you want to exit?",QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                exit(0);
            }
        }
    }
}
void state_menu::mouse_click(GameWidget * widget,QMouseEvent* event)
{
    if (event->button())
    {
        if(Qt::LeftButton)
        {
            switch (button)
            {
            case 1: setStage(widget,state_game::instance());break;
            case 2: setStage(widget,state_score::instance());break;
            case 3: widget->close();break;
            }
        }
    }
}

