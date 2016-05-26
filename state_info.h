#ifndef STATE_INFO
#define STATE_INFO

#include "state.h"
#include "state_menu.h"

class state_info : public State
{
private:
    state_info(){}
    ~state_info(){}

public:
    static State* instance()
    {
        return new state_info();
    }
    void paint(QPaintEvent *, GameWidget *, QPainter * painter, QTimer *)
    {
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->drawPixmap(0,0,QPixmap(":/new/image/resource/menu/info.jpg"));
    }
    void key_press(GameWidget* widget,QKeyEvent* event)
    {
        if(event->key()) setStage(widget, state_menu::instance());
    }
    void mouse_click(GameWidget *,QMouseEvent*){}
    void key_release(GameWidget*,QKeyEvent*){}

};


#endif // STATE_INFO

