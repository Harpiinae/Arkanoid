#ifndef STATE_OPTION
#define STATE_OPTION


#include "state.h"
#include "gamewidget.h"
#include "state_menu.h"
#include "state_game.h"
#include "state_game.h"


class state_option : public State
{
    bool god;
    bool mouse;

    unsigned int plan;
    unsigned int button;
    unsigned int num_weapons;
     int speed;

    QCursor *cursor;

    void resize();

public:
    state_option();
    ~state_option();
    static State* instance()
    {
        return new state_option();
    }
    void paint(QPaintEvent *, GameWidget *, QPainter *, QTimer *);
    void mouse_click(GameWidget *,QMouseEvent*);
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget*,QKeyEvent*){}
};

#endif // STATE_OPTION


