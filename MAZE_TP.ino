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
   //0 - without additional walls on levels

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
    arduboy.generateRandomSeed();
}

void loop() {

    if (!(arduboy.nextFrame()))
    return;
  
    arduboy.clear();
    arduboy.pollButtons();
    joystick.get_action();
    game.action();
    arduboy.display(); // Выводим буфер на экран
    //delay(500);
    //waitForButtonPress();
    //loopstep++;
   
}

