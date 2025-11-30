#include "Arduino.h"
#include "USBCore.h"
#include <Arduboy2.h>
#include "Viewer.h"
#include "game_info.h"
#include "MAZE_GAME.h"
#include "bmp.h"
// #include "zastavka.h"
// #include "instruction_screen.h"
// #include "simple_gameover.h"
// #include "player.h"
// #include "endpoint.h"
//#include "intro_text.h"


extern Arduboy2 arduboy;



void Viewer::update() {
  switch (pt_game->state) {
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
        int16_t pos_X = (COLCOUNT+1)* X_SIZE;
        int16_t pos_Y = 1* Y_SIZE;
        int L = pt_game->get_game_model()->player1.floor;
        arduboy.setCursor(pos_X, pos_Y);
        arduboy.print("L");
        arduboy.setCursor(pos_X, pos_Y + Y_SIZE);
        arduboy.print(L);
        //arduboy.print("VIEW TODO GAMEcases\n");
        ViewMaze();
        ViewPlayer();
        ViewTimer();
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
void Viewer::ViewTimer() {
  arduboy.setCursor(TIMER_POS_X, TIMER_POS_Y);
  arduboy.print((int)(millis()  * 0.001));
}

void Viewer::ViewPlayer() {
  Sprites::drawSelfMasked((1 + X_SIZE * pt_game->get_game_model()->player1.pos_X),
                          (1 + Y_SIZE * pt_game->get_game_model()->player1.pos_Y), player_bitmap, 0);
}

void Viewer::ViewStartScreen() {
  Sprites::drawOverwrite(0, 0, zastavka_bitmap, 0);
}

void Viewer::ViewIntroScreen() {
  Sprites::drawOverwrite(0, 0, introText, 0);
}

void Viewer::ViewControlsScreen() {
  Sprites::drawOverwrite(0, 0, instruction_screen_bitmap, 0);
}

void Viewer::ViewMaze() {
  // Draw exitpoint
  //Sprites::drawOverwrite((X_SIZE * pt_game->get_game_model()->maze1->exitpoint.pos_x),(Y_SIZE * pt_game->get_game_model()->maze1->exitpoint.pos_y), endpoint_bitmap, 0);
  // Draw Maze Exitpoint
  Sprites::drawSelfMasked((X_SIZE * pt_game->get_game_model()->maze1->exitpoint.pos_x), (Y_SIZE * pt_game->get_game_model()->maze1->exitpoint.pos_y), endpoint_bitmap, 0);
  //Xface oriented draw   вертикальные
  for (int xFace = 0; xFace <= COLCOUNT; xFace++) {
    for (int row = 0; row < ROWCOUNT; row++) {
      if (pt_game->get_game_model()->maze1->IsWallX(xFace, row)) {
        //draw X oriented face
        int Xstart = xFace * X_SIZE;
        int Xend = xFace * X_SIZE;
        int Ystart = row * Y_SIZE;
        int Yend = row * Y_SIZE + Y_SIZE;
        arduboy.drawLine(Xstart, Ystart, Xend, Yend, WHITE);
      }
    }
  }

  //Yface oriented draw   горизонтальные
  for (int col = 0; col < COLCOUNT; col++) {
    for (int row = 0; row <= ROWCOUNT; row++) {
      if (pt_game->get_game_model()->maze1->IsWallY(col, row)) {
        //draw  Y oriented face
        int Xstart = col * X_SIZE;
        int Xend = col * X_SIZE + X_SIZE;
        int Ystart = row * Y_SIZE;
        int Yend = row * Y_SIZE;
        arduboy.drawLine(Xstart, Ystart, Xend, Yend, WHITE);
      }
    }
  }
}

void Viewer::ViewGameOver() {
  Sprites::drawOverwrite(0, 0, simple_gameover_bitmap, 0);
}
