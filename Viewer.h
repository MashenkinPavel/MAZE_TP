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
    void ViewGameOver();
    void ViewControlsScreen();
};

void Viewer::ViewStartScreen();
void Viewer::ViewControlsScreen();
void Viewer::ViewGameOver();
void Viewer::ViewIntroScreen();


#endif