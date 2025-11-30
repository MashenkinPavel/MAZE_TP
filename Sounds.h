#ifndef SOUNDS_H
#define SOUNDS_H

#include <Arduboy2.h>

class SoundManager {
public:
    void init(Arduboy2* arduboyPtr) {
        arduboy = arduboyPtr;
    }
    
    void playTone(unsigned int frequency, unsigned long duration)
        {
            if (arduboy->audio.enabled() == true)
            {
                tone(PIN_SPEAKER_1, frequency, duration);
            }
        }

    // Фоновая музыка для стартового экрана
    void playTitleMusic() {
        if (!arduboy->audio.enabled()) return;
        
        // Простая мелодия (можно заменить на что-то более интересное)
        playTone(523, 200); // C5
        playTone(659, 200); // E5
        playTone(784, 200); // G5
        playTone(1047, 400); // C6
    }
    
    // Звук нажатия кнопки
    void playButtonPress() {
        if (!arduboy->audio.enabled()) return;
        playTone(800, 50);
    }
    
    // Звук перемещения
    void playMoveSound() {
        if (!arduboy->audio.enabled()) return;
        playTone(600, 30);
    }
    
    // Звук сбора монеты
    void playCoinCollect() {
        if (!arduboy->audio.enabled()) return;
        playTone(1000, 100);
        playTone(1200, 100);
    }
    
    // Звук смерти
    void playDeathSound() {
        if (!arduboy->audio.enabled()) return;
        playTone(200, 300);
        playTone(150, 200);
        playTone(100, 300);
    }
    
    // Звук победы
    void playWinSound() {
        if (!arduboy->audio.enabled()) return;
        for (int i = 0; i < 3; i++) {
            playTone(523 + i * 100, 100); // Восходящая мелодия
        }
    }
    
    // Звук удара
    void playHitSound() {
        if (!arduboy->audio.enabled()) return;
        playTone(300, 80);
        playTone(200, 80);
    }

private:
    Arduboy2* arduboy;
};

#endif