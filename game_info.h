#ifndef GAME_INFO
#define GAME_INFO
class Viewer;
#include "Controller.h"
#include "Viewer.h"
#include "MAZE_GAME.h"
#include "Sounds.h"

class GameClass{
public:
    enum class gamestate{
        START_STAGE,
        INTRO_STAGE, 
        CONTROLLER_STAGE,
        GAME_STAGE,
        END_STAGE
    } state;
    void action();
    void init(Controller* joystick, SoundManager *audio);
    void addViewer(Viewer* pt_monitor){
        pt_viewer = pt_monitor;
    }
    MAZE_GAME* get_game_model(){
        return &gamemodel;
    }
private:
    SoundManager *pt_audio;
    Controller* pt_joystick;
    Viewer * pt_viewer; 
    MAZE_GAME gamemodel;
    int step = 0;
};



#endif
