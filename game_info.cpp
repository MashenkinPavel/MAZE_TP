#include "Arduboy2.h"
#include <avr/sleep.h>
#include "Arduboy2Core.h"
#include "game_info.h"
#include "Controller.h"
#include "Sounds.h"

extern Arduboy2 arduboy;

void GameClass::init(Controller* joystick, SoundManager *audio){
    pt_joystick = joystick;
    pt_audio = audio;
    state = gamestate::START_STAGE;
}


void GameClass::action(){
    switch (state){
        case gamestate::START_STAGE:
        {
            pt_audio->playTitleMusic(); // play bach
            if (pt_joystick->exec() == Controller::action::PRESS_A){
                state = gamestate::INTRO_STAGE;
                pt_viewer->update();
                pt_audio->playButtonPress(); // #MAX
            }
            else {
              state = gamestate::START_STAGE;
              pt_viewer->update();
            }
        }
        break;
        case gamestate::INTRO_STAGE:
        {
          if (pt_joystick->exec() == Controller::action::PRESS_A){
              state = gamestate::CONTROLLER_STAGE;
              pt_viewer->update();
              pt_audio->playButtonPress(); // #MAX
          } else{
              state = gamestate::INTRO_STAGE;
              pt_viewer->update();
          }
        }
        break;
        case gamestate::CONTROLLER_STAGE:
        {
          if (pt_joystick->exec() == Controller::action::PRESS_A){
                state = gamestate::GAME_STAGE;
                gamemodel.InitGame();
                pt_audio->playButtonPress(); //#MAX
          } 
          pt_viewer->update();
        }
        break;
        case gamestate::GAME_STAGE:
        {    
            pt_audio->muteScore();
            state = gamestate::GAME_STAGE;
            bool haveMoved = gamemodel.player1.move_player(pt_joystick->exec(), gamemodel.maze1);

            if (gamemodel.player1.pos_X == gamemodel.maze1->exitpoint.pos_x && gamemodel.player1.pos_Y == gamemodel.maze1->exitpoint.pos_y)
                if(Controller::action::PRESS_A == pt_joystick->exec()){
                    pt_audio->playExitReached(); // Звук достижения выхода #MAX
                     //state = gamestate::END_STAGE;
                    gamemodel.InitGame();  
                    gamemodel.level_round++;
                    gamemodel.time_for_level *= 0.9;
                    state = gamestate::GAME_STAGE;
                }
            if(Controller::action::PRESS_B == pt_joystick->exec()){
                pt_audio->playTeleportSound(); // Звук телепортации #MAX
                if(gamemodel.player1.floor == 0 ) 
                gamemodel.player1.changefloor(1,&gamemodel);
                else gamemodel.player1.changefloor(0,&gamemodel);
            }
            pt_viewer->update();
            
            if (gamemodel.get_remain_sec()<=0){
                state = gamestate::END_STAGE;
            }
            
        }
        break;
        case gamestate::END_STAGE:
        { 
            
            pt_viewer->update();
            if (Controller::action::PRESS_B == pt_joystick->exec()) {
                 pt_audio->playButtonPress(); // Звук рестарта #MAX
                 gamemodel.InitGame();  
                state = gamestate::GAME_STAGE;
            }
        }
        break;
    }

}