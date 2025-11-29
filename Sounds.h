#ifndef SOUNDS_H
#define SOUNDS_H

#include <Arduboy2.h>

class SoundManager {
public:
    void init(Arduboy2* arduboyPtr) {
        arduboy = arduboyPtr;
    }
    
    // Фоновая музыка для стартового экрана
    void playTitleMusic() {
        if (!arduboy->audio.enabled()) return;
        
        // Простая мелодия (можно заменить на что-то более интересное)
        arduboy->tunes.tone(523, 200); // C5
        arduboy->tunes.tone(659, 200); // E5
        arduboy->tunes.tone(784, 200); // G5
        arduboy->tunes.tone(1047, 400); // C6
    }
    
    // Звук нажатия кнопки
    void playButtonPress() {
        if (!arduboy->audio.enabled()) return;
        arduboy->tunes.tone(800, 50);
    }
    
    // Звук перемещения
    void playMoveSound() {
        if (!arduboy->audio.enabled()) return;
        arduboy->tunes.tone(600, 30);
    }
    
    // Звук сбора монеты
    void playCoinCollect() {
        if (!arduboy->audio.enabled()) return;
        arduboy->tunes.tone(1000, 100);
        arduboy->tunes.tone(1200, 100);
    }
    
    // Звук смерти
    void playDeathSound() {
        if (!arduboy->audio.enabled()) return;
        arduboy->tunes.tone(200, 300);
        arduboy->tunes.tone(150, 200);
        arduboy->tunes.tone(100, 300);
    }
    
    // Звук победы
    void playWinSound() {
        if (!arduboy->audio.enabled()) return;
        for (int i = 0; i < 3; i++) {
            arduboy->tunes.tone(523 + i * 100, 100); // Восходящая мелодия
        }
    }
    
    // Звук удара
    void playHitSound() {
        if (!arduboy->audio.enabled()) return;
        arduboy->tunes.tone(300, 80);
        arduboy->tunes.tone(200, 80);
    }

private:
    Arduboy2* arduboy;
};

#endif