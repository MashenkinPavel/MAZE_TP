#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "global.h"
#include  <Stack.h>
#include "Controller.h"

class MAZE_GAME;
class Maze {
    public:
        bool IsWallX(int nx, int ny){   //dir == 1  right wall    dir == -1   left wall
            return maze_wallsX[ nx ][ny];   
        }
        bool IsWallY(int nx, int ny){   //dir == 1  dwon wall    dir == -1   up wall
            return maze_wallsY[ nx ][ny];   
        }
        void generateMaze(int startX, int startY);
        void addWallYSlice(int facecolumn );
        void addWallXSlice(int facerow);      // ----
        void init();
        struct exit {
            int pos_x = EXIT_POS_X;
            int pos_y = EXIT_POS_Y;
        } exitpoint;
    private:   
        bool isValidCell(int X, int Y);
        bool maze_wallsX[COLCOUNT+1][ROWCOUNT] ;   //  face like that    |   |    |
        bool maze_wallsY[COLCOUNT][ROWCOUNT+1] ;   //  face like that    _   _    _
};

class Player{
    public:
        int floor = 0;
        int pos_X = START_POS_X;
        int pos_Y = START_POS_Y;
        bool move_player(Controller::action act, Maze *pmaze);
        void changefloor(int newfloor, MAZE_GAME* pMAZE_GAME);
};

class MAZE_GAME{
public:
    void InitGame();
    Maze    down_maze;  //floor 0
    Maze    up_maze;    // floor 1
    
    Maze*   maze1;   //current maze
    Player player1;
    uint32_t start_time = 0;
    uint32_t time_for_level = 30; //sec
    
    int floor = 1; //этаж 
    int level_round = 1;
    uint32_t get_remain_sec()
    {
        uint32_t rez = time_for_level -  (int)( ( millis() - start_time )  * 0.001 );
        if (rez < 0) rez = 0;
        return rez;
    }

private:

};

struct Cell{
         int x = -1;
         int y = -1;
};








#endif