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
        void ViewPlayer();
        void ViewTimer();
        void update();
        GameClass* pt_game;
private:

    void ViewStartScreen();
    void ViewIntroScreen();
    void ViewGameOver();
    void ViewControlsScreen();
};





#endif