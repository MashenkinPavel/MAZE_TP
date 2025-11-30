#include <Arduboy2.h>
#include "global.h"
#include "game_info.h"
#include "Controller.h"
#include "Viewer.h"
#include "Sounds.h"

//ArduboyTinyFont tinyfont = ArduboyTinyFont(arduboy.sBuffer);
Arduboy2 arduboy;
GameClass game;
Controller joystick;
Viewer monitor;
SoundManager audioFX;
long unsigned int startTime;

//int loopstep = 0;
void create_maze(int cols, int rows);

void setup() {
    arduboy.begin();
    startTime = millis();     // milliseconds at start
    arduboy.setFrameRate(60);
    arduboy.clear(); // Очистка экрана
    joystick.init();
    audioFX.init(&arduboy);
    game.init(&joystick, &audioFX);
    monitor.init(&game);
    game.addViewer(&monitor);
    arduboy.generateRandomSeed();

    //arduboy.print("setup done\n");
    //arduboy.display();
    //waitForButtonPress();
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

