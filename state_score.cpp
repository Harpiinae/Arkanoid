#include "state_score.h"

state_score::state_score()
{
    y = 100;
    for(int i=1;i<10;i++)
        num.push_back(QString::number(i));
    readTopScores();

}

state_score::~state_score()
{

}

void state_score::paint(QPaintEvent *, GameWidget * , QPainter *painter, QTimer *)
{
    readTopScores();
    painter->drawPixmap(0,0,QPixmap(":/new/image/resource/menu/HighScore.png"));
    painter->setPen(Qt::cyan);
    painter->setFont(QFont("Helvetica",10,QFont::Bold));
    for(int i=0; i<9;i++)
    {
        painter->drawText(100,y,num.at(i));
        y+=50;
        if(y>=550) y=100;
    }
    foreach (QString str, names) {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QByteArray encodedString = codec->fromUnicode(str);
        painter->drawText(450,y,encodedString);
        y+=50;
        if(y>=550) y=100;
    }
    for (int i=0; i<scores.length();i++) {
    painter->drawText(800,y,QString::number(scores.at(i)));
        y+=50;
        if(y>=550) y=100;
    }
    scores.clear();
    names.clear();
 }

void state_score::key_press(GameWidget * widget, QKeyEvent * event)
{
    switch(event->key())
    {
        case Qt::Key_Escape: setStage(widget,state_menu::instance());break;
    }
}

void state_score::readTopScores()
{
    QFile file("topscore.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))  return;
    int counter = 0;
    while (!file.atEnd() )
    {
        QString line = file.readLine();
        QString delimiterPattern(" ");
        QStringList splitLine = line.split(delimiterPattern);
        names.push_back(splitLine[0]);
        scores.push_back(splitLine[1].toInt());
        ++counter;
    }
    if(counter < 9)
    {
        for(int i = counter; i < 9; i++)
        {
            names.push_back("");
            scores.push_back(0);
        }
    }
    file.close();
}
