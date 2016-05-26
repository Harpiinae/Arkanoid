#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

class State;
class GameWidget : public QWidget
{
    Q_OBJECT
public:

    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget(){}
private:
    QTimer *timer;
    void setStage(State* s)
    {
        stage = s;
    }
    friend class State;
protected:
    State* stage;
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);

};

#endif // GAMEWIDGET_H
