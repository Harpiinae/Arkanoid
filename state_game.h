#ifndef STATEGAME_H
#define STATEGAME_H

#include "state_menu.h"
#include "game.h"
#include "state.h"
#include "gamewidget.h"
#include "paddle.h"
#include "ball.h"
#include "block.h"
#include <QVector>
#include <QMessageBox>

class state_game : public State
{
    Q_OBJECT
private:
    state_game();
    ~state_game();
public:
    static State* instance()
    {

        return new state_game();
    }
    void paint(QPaintEvent *event, GameWidget * w, QPainter *painter, QTimer *timer);
    void mouse_click(GameWidget *,QMouseEvent*);
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget *,QKeyEvent*);
    Paddle * paddle;
    QVector <Block *> block;
    Ball * ball;
    bool start;
    int numb;
};

#endif // STATEGAME_H
