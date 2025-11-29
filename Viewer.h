#ifndef VIEWER_H
#define VIEWER_H
class GameClass;
#include "game_info.h"

class Viewer{
public:
        void init(GameClass* game){
          pt_game = game;
        }
        void ViewMaze();
        void update();
private:
    GameClass* pt_game;
    void ViewStartScreen();
    void ViewIntroScreen();
};



#endif