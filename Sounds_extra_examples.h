// Звук появления врага
void playEnemySpawn() {
    if (!arduboy->audio.enabled()) return;
    arduboy->tunes.tone(400, 100);
    arduboy->tunes.tone(300, 100);
}

// Звук телепортации
void playTeleportSound() {
    if (!arduboy->audio.enabled()) return;
    for (int i = 0; i < 5; i++) {
        arduboy->tunes.tone(800 + i * 50, 30);
    }
}

// Звук открытия двери
void playDoorOpen() {
    if (!arduboy->audio.enabled()) return;
    arduboy->tunes.tone(200, 100);
    arduboy->tunes.tone(400, 100);
    arduboy->tunes.tone(600, 100);
}