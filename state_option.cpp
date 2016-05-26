#include "state_option.h"



state_option::state_option()
{
    god = false;
    mouse = false;

    plan = 1;
    button = 0;
}

state_option::~state_option()
{
    delete cursor;
}

void state_option::paint(QPaintEvent *, GameWidget * widget, QPainter *painter, QTimer * )
{
    painter->drawPixmap(0,0,QPixmap(":/new/image/resource/option/back.jpg"));

    QPoint position = widget->mapFromGlobal(cursor->pos());
    if(position.ry() > 200 && position.ry() < 250 && position.rx()>150 &&  position.rx()<250)
    {button = 1;mouse = true;}
        else if(position.ry() > 200 && position.ry() < 250&& position.rx()>700 && position.rx()<750)
            {button= 2;mouse = true;}
        else if(position.ry() > 400 && position.ry() < 440&& position.rx()>400 && position.rx()<470)
            {button= 3;mouse = true;}
        else {if(mouse)button = 0;mouse = false;}

    painter->setPen(Qt::black);
    painter->setFont(QFont("Helvetica",14,QFont::Bold));
    painter->drawText(375,200,"AMMO: ");
    painter->drawText(450,200,QString::number(num_weapons));
    painter->drawText(375,250,"SPEED: ");
    painter->drawText(450,250,QString::number(abs(speed)));
    painter->drawPixmap(150,200,QPixmap( ":/new/image/resource/option/left.png"));
    painter->drawPixmap(700,200,QPixmap( ":/new/image/resource/option/right.png"));

    if(!god) painter->drawPixmap(400,400,QPixmap( ":/new/image/resource/option/off.png"));
        else painter->drawPixmap(400,400,QPixmap( ":/new/image/resource/option/on.png"));

    switch(plan)
    {
        case 1: num_weapons = 50;speed = -9;
                painter->drawPixmap(225,200,QPixmap( ":/new/image/resource/objects/Ship.png"));break;
        case 2: num_weapons = 100;speed = -6;
                painter->drawPixmap(225,200,QPixmap( ":/new/image/resource/objects/Ship2.png"));break;
        case 3: num_weapons = 150;speed = -3;
                painter->drawPixmap(225,200,QPixmap( ":/new/image/resource/objects/Ship3.png"));break;
        case 4: num_weapons = 200;speed = -2;
                painter->drawPixmap(225,200,QPixmap( ":/new/image/resource/objects/Ship4.png"));break;

    }
    switch(button)
    {
        case 1:painter->drawPixmap(150,200,QPixmap( ":/new/image/resource/option/red_left.png"));break;
        case 2:painter->drawPixmap(700,200,QPixmap( ":/new/image/resource/option/red_right.png"));break;
    }
}

void state_option::mouse_click(GameWidget *, QMouseEvent * event)
{
    if (event->button())
    {
        if(Qt::LeftButton)
        {
            switch (button)
            {
                case 1:
                switch(plan)
                {
                    case 4: plan =3;resize(); break;
                    case 3: plan =2;resize(); break;
                    case 2: plan =1;resize(); break;
                    case 1: plan =4;resize(); break;
                }
                break;
                case 2:
                switch(plan)
                {
                    case 1: plan =2;resize(); break;
                    case 2: plan =3;resize(); break;
                    case 3: plan =4;resize(); break;
                    case 4: plan =1;resize(); break;
                }
                break;
                case 3: if(god) god =false; else god=true; resize();break;
            }
        }
    }
}

void state_option::key_press(GameWidget * widget, QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Escape:
            setStage(widget,state_menu::instance());break;
    }
}

void state_option::resize()
{
    vector<int> temp;
    int a;

    QFile file("game.txt");
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        for(int i=0; i<5; i++)
        {
            stream >> a;
            temp.push_back(a);
        }
        file.close();
    }

        temp.erase(temp.begin());
        temp.insert(temp.begin(),plan);

        temp.erase(temp.begin()+1);
        temp.insert(temp.begin()+1,god);

    QFile file1("game.txt");
    if(file1.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream1(&file1);
        for(unsigned int i=0; i<temp.size(); i++)
        {
            a = temp.at(i);
            stream1<<a<<" ";
        }
    }
}
