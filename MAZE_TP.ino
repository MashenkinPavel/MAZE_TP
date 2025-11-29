#include <Arduboy2.h>
#include "global.h"
#include "game_info.h"
#include "Controller.h"
#include "Viewer.h"

//ArduboyTinyFont tinyfont = ArduboyTinyFont(arduboy.sBuffer);
Arduboy2 arduboy;
GameClass game;
Controller joystick;
Viewer monitor;
//int loopstep = 0;
void create_maze(int cols, int rows);

void setup() {
    arduboy.begin();
    arduboy.setFrameRate(60);
    arduboy.clear(); // Очистка экрана
    joystick.init();
    game.init(&joystick);
    monitor.init(&game);
    game.addViewer(&monitor);
    

    //arduboy.print("setup done\n");
    //arduboy.display();
    //waitForButtonPress();
}

void loop() {

    if (!(arduboy.nextFrame()))
    return;
  
    

    //  if (game.state == GameClass::gamestate::START_STAGE)   arduboy.print("START_STAGE");
    //  if (game.state == GameClass::gamestate::INTRO_STAGE)   arduboy.print("INTRO_STAGE");
    //  if (game.state == GameClass::gamestate::CONTROLLER_STAGE)   arduboy.print("CONTROLLER_STAGE");
    //  if (game.state == GameClass::gamestate::GAME_STAGE)   arduboy.print("GAME_STAGE");
    //  if (game.state == GameClass::gamestate::END_STAGE)   arduboy.print("END_STAGE");
    //  arduboy.display();    
    //  waitForButtonPress();

    arduboy.clear();
    arduboy.pollButtons();
    joystick.get_action();
    game.action();
    arduboy.display(); // Выводим буфер на экран
    //delay(500);
    //waitForButtonPress();
    //loopstep++;
   
}

 //arduboy.drawRect(0, 0, 128, 64, WHITE);
 //arduboy.drawRect(0, 0, X_SIZE, Y_SIZE, WHITE);
 //create_maze(COLCOUNT, ROWCOUNT);
 //draw_maze();
 //game.draw();