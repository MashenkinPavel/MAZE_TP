#include <Arduboy2.h>
#include "Viewer.h"
#include "game_info.h"
#include "MAZE_GAME.h"
#include "zastavka.h"
#include "instruction_screen.h"
#include "simple_gameover.h" 


extern Arduboy2 arduboy;



void Viewer::update(){
    switch (pt_game->state){
        case GameClass::gamestate::START_STAGE:
        {
            ViewStartScreen();
        }
        break;
        case GameClass::gamestate::INTRO_STAGE:
        {
            ViewIntroScreen();
        }
        break;
        case GameClass::gamestate::CONTROLLER_STAGE:
        {
            ViewControlsScreen();
        }
        break;
        case GameClass::gamestate::GAME_STAGE:
        {
            //arduboy.print("VIEW TODO GAMEcases\n");
        }
        break;
        case GameClass::gamestate::END_STAGE:
        {
            //arduboy.print("VIEW TODO ENDcases\n");
            ViewGameOver();
        }
        break;
        default:
        {
            //arduboy.print("Viewer TODO cases\n");
        }
    }
}


void Viewer::ViewStartScreen(){
 Sprites::drawOverwrite(0, 0, zastavka_bitmap, 0);

}

void Viewer::ViewIntroScreen(){
    arduboy.print("Intro");
}

void Viewer::ViewControlsScreen(){
  Sprites::drawOverwrite(0, 0, instruction_screen_bitmap, 0);
}



void Viewer::ViewMaze(){
    //Xface oriented draw   вертикальные
    for (int xFace = 0;xFace <= COLCOUNT;xFace++){
        for (int row=0;row<ROWCOUNT;row++){
            if ( pt_game->get_game_model()->maze1.IsWallX(xFace,row)){
                //draw X oriented face
                int Xstart = xFace * X_SIZE; 
                int Xend  =  xFace * X_SIZE; 
                int Ystart = row * Y_SIZE;
                int Yend =   row * Y_SIZE + Y_SIZE;
                 arduboy.drawLine(Xstart, Ystart, Xend, Yend, WHITE);
            }
        }
    }

    //Yface oriented draw   горизонтальные
    for (int col = 0;col<COLCOUNT;col++){
        for (int row=0;row<=ROWCOUNT;row++){
            if ( pt_game->get_game_model()->maze1.IsWallY(col,row)){
                //draw  Y oriented face
                int Xstart = col * X_SIZE; 
                int Xend  =  col * X_SIZE + X_SIZE; 
                int Ystart = row * Y_SIZE;
                int Yend =   row * Y_SIZE;
                 arduboy.drawLine(Xstart, Ystart, Xend, Yend, WHITE);
            }
        }
    }
}

void Viewer::ViewGameOver(){
    Sprites::drawOverwrite(0, 0, zastavka_bitmap, 0);
}


 

