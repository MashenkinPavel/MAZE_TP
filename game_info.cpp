#include "game_info.h"
#include "Controller.h"

void GameClass::init(Controller* joystick){
    pt_joystick = joystick;
    state = gamestate::START_STAGE;
}


void GameClass::action(){
    switch (state){
        case gamestate::START_STAGE:
        {
            if (pt_joystick->exec() == Controller::action::PRESS_A){
                state = gamestate::INTRO_STAGE;
                pt_viewer->update();
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
          }else{
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
                pt_viewer->ViewMaze();
          } 
          pt_viewer->update();
        }
        break;
        case gamestate::GAME_STAGE:
        {   
            
            state = gamestate::GAME_STAGE;
            pt_viewer->ViewMaze();
            pt_viewer->update();
        }
        break;
        case gamestate::END_STAGE:
        {
            
            pt_viewer->update();
        }
        break;
    }

}