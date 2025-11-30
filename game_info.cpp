#include <avr/sleep.h>
#include "Arduboy2Core.h"
#include "game_info.h"
#include "Controller.h"
#include "Sounds.h"


void GameClass::init(Controller* joystick, SoundManager *audio){
    pt_joystick = joystick;
    pt_audio = audio;
    state = gamestate::START_STAGE;
}


void GameClass::action(){
    switch (state){
        case gamestate::START_STAGE:
        {
            if (pt_joystick->exec() == Controller::action::PRESS_A){
                state = gamestate::INTRO_STAGE;
                pt_viewer->update();
                //pt_audio->playTitleMusic();
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
          } 
          pt_viewer->update();
        }
        break;
        case gamestate::GAME_STAGE:
        {    
            state = gamestate::GAME_STAGE;
            gamemodel.player1.move_player(pt_joystick->exec(), gamemodel.maze1);
            if (gamemodel.player1.pos_X == gamemodel.maze1->exitpoint.pos_x && gamemodel.player1.pos_Y == gamemodel.maze1->exitpoint.pos_y)
                if(Controller::action::PRESS_A == pt_joystick->exec()) state = gamestate::END_STAGE;
            if(Controller::action::PRESS_B == pt_joystick->exec()){
                if(gamemodel.player1.floor == 0 ) 
                gamemodel.player1.changefloor(1,&gamemodel);
                else gamemodel.player1.changefloor(0,&gamemodel);
            }
            pt_viewer->update();
            
        }
        break;
        case gamestate::END_STAGE:
        { 
            
            pt_viewer->update();
            if (Controller::action::PRESS_B == pt_joystick->exec()) {
                 gamemodel.InitGame();  
                state = gamestate::GAME_STAGE;
            }
        }
        break;
    }

}