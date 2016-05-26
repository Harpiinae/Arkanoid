#include "gamewidget.h"
#include "state_load.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Arkanoid");
    setFixedSize(1000,600);
    stage = state_load::instance();
    timer = new QTimer(this);
    timer->stop();
    connect(GameWidget::timer, SIGNAL(timeout()), this, SLOT(update()));
}
void GameWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    stage->paint(event, this, &painter, timer);
}
void GameWidget::keyPressEvent(QKeyEvent *event)
{
    stage->key_press(this,event);
}
void GameWidget::keyReleaseEvent(QKeyEvent *event)
{
    stage->key_release(this,event);
}
void GameWidget::mousePressEvent(QMouseEvent *event)
{
    stage->mouse_click(this,event);
}
