#include "state_load.h"
#include "state_menu.h"

state_load::state_load()
{
    rev =0;
}
void state_load::paint(QPaintEvent *, GameWidget *widget, QPainter *painter, QTimer *timer)
{
    QPalette palette;
    if(rev<25)
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/image/resource/loading/loading1.png")));
    if(rev>=25&&rev<50)
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/image/resource/loading/loading2.png")));
    if(rev>=50&&rev<75)
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/image/resource/loading/loading3.png")));
    if(rev>=75&&rev<100)
        palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/image/resource/loading/loading4.png")));
    widget->setPalette(palette);
    rev++;
    if (rev == 100) { setStage(widget,state_menu::instance()); }
    timer->start(20);
}
