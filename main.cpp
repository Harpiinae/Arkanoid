#include "game.h"
#include <QApplication>
#include <cstdlib>
#include <ctime>
//Second Git Commit
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Game::Instance().run();
   return  a.exec();
}

