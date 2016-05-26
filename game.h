#ifndef GAME_H
#define GAME_H
#include "gamewidget.h"

class Game
{
private:
    Game(){}
    Game(const Game& root);
    Game& operator=(const Game&);
    GameWidget *widget;
public:
    static Game& Instance()
    {
        static Game the_instance;
        return the_instance;
    }
    void run();
};

#endif // GAME_H
