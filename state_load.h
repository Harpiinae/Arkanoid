#ifndef STATELOADING_H
#define STATELOADING_H
#include "state.h"
#include "gamewidget.h"

class state_load : public State
{
private:
    state_load();
    ~state_load(){}
    int rev;
public:
    static State *instance()
    {
        return new state_load();
    }
    void paint(QPaintEvent *, GameWidget *, QPainter *, QTimer *);
    void mouse_click(GameWidget *,QMouseEvent*){}
    void key_press(GameWidget*,QKeyEvent*){}
    void key_release(GameWidget*,QKeyEvent*){}
};

#endif // STATELOADING_H
