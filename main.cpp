#include "game.h"
#include <QApplication>
#include <cstdlib>
#include <ctime>
//Second
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Game::Instance().run();
   return  a.exec();
}

