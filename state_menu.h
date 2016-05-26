#ifndef STATEMENU_H
#define STATEMENU_H

#include "state.h"
#include <QMediaPlayer>
#include <QPalette>

class state_menu : public State
{
    state_menu();
    ~ state_menu();
    int button;
    bool mouse;
    QCursor *cursor;

public:
    static State* instance()
    {
        return new state_menu();
    }
    void paint(QPaintEvent *event, GameWidget * w, QPainter *painter, QTimer *timer);
    void mouse_click(GameWidget *,QMouseEvent*) ;
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget*,QKeyEvent*){}
};

#endif // STATEMENU_H
