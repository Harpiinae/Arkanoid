#ifndef STATE_SCORE
#define STATE_SCORE

#include "state.h"
#include "state_menu.h"
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>

class state_score : public State
{
    state_score();
    ~ state_score();
    int y;
    QVector <int> scores;
    QVector <QString> names;
    QVector <QString> num;
    void readTopScores();

public:
    static State* instance()
    {
        return new state_score();
    }
    void paint(QPaintEvent *event, GameWidget * w, QPainter *painter, QTimer *timer);
    void mouse_click(GameWidget *,QMouseEvent*){}
    void key_press(GameWidget*,QKeyEvent*);
    void key_release(GameWidget*,QKeyEvent*){}
};




#endif // STATE_SCORE

