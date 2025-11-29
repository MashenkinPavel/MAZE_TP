#include "Controller.h"
#include <Arduboy2.h>

extern Arduboy2 arduboy;

void Controller::init(){
  button = action::NO_ACTION;
}

void Controller::get_action(){
    // if (arduboy.pressed(RIGHT_BUTTON))  button = action::PRESS_RIGHT;
    // else if (arduboy.pressed(LEFT_BUTTON))  button = action::PRESS_LEFT;
    // else if (arduboy.pressed(UP_BUTTON))  button = action::PRESS_UP;
    // else if (arduboy.pressed(DOWN_BUTTON))  button = action::PRESS_DOWN;
    // else if (arduboy.pressed(A_BUTTON))  button = action::PRESS_A;
    // else if (arduboy.pressed(B_BUTTON))  button = action::PRESS_B;

    if (arduboy.justPressed(RIGHT_BUTTON))  button = action::PRESS_RIGHT;
    else if (arduboy.justPressed(LEFT_BUTTON))  button = action::PRESS_LEFT;
    else if (arduboy.justPressed(UP_BUTTON))  button = action::PRESS_UP;
    else if (arduboy.justPressed(DOWN_BUTTON))  button = action::PRESS_DOWN;
    else if (arduboy.justPressed(A_BUTTON))  button = action::PRESS_A;
    else if (arduboy.justPressed(B_BUTTON))  button = action::PRESS_B;


    else button = action::NO_ACTION;
}

Controller::action Controller::exec(){
  return button;
}