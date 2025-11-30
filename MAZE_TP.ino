
#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
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
SoundManager game_sounds_manager;
//ArduboyTones sound(arduboy.audio.enabled);
ArduboyPlaytune tunes(arduboy.audio.enabled);
uint8_t count_frames = 0;
uint8_t currentFrame = 0;

//int loopstep = 0;

void create_maze(int cols, int rows);
void setup() {
  arduboy.begin();

  arduboy.setFrameRate(60);
  arduboy.clear();  // Очистка экрана

  // #MAX
  // Инициализация звука - сначала выключаем для безопасности
  // arduboy.audio.off();
  //game_sounds_manager.enableSound(false);
  //delay(100);
  game_sounds_manager.init(&arduboy, &tunes);

  joystick.init();

  game.init(&joystick, &game_sounds_manager);
  monitor.init(&game);
  game.addViewer(&monitor);
  arduboy.generateRandomSeed();

  // #MAX
  // Включаем звук после инициализации
  game_sounds_manager.enableSound(true);



  // audio setup
  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a DevKit
  tunes.initChannel(PIN_SPEAKER_1);  // use the same pin for both channels
  tunes.toneMutesScore(true);        // mute the score when a tone is sounding
#endif

 arduboy.invert(!arduboy.audio.enabled());  // invert display if sound muted
}

void loop() {

  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();
  arduboy.pollButtons();
  joystick.get_action();
  game.action();
  arduboy.display();  // Выводим буфер на экран

 
}
