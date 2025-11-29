#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "global.h"
#include  <stdio.h>
#include  <Stack.h>
#include "Controller.h"


class Maze{
    public:
        bool IsWallX(int nx, int ny){   //dir == 1  right wall    dir == -1   left wall
            return maze_wallsX[ nx ][ny];   
        }
        bool IsWallY(int nx, int ny){   //dir == 1  dwon wall    dir == -1   up wall
            return maze_wallsY[ nx ][ny];   
        }
        void generateMaze(int startX, int startY);
        void save_walls_txt_for_dbg();
        void init();
    private:
        
        bool isValidCell(int X, int Y);
        bool maze_wallsX[COLCOUNT+1][ROWCOUNT] {true};
        bool maze_wallsY[COLCOUNT][ROWCOUNT+1] {true};
};

class Player{
    public:
        int pos_X = START_POS_X;
        int pos_Y = START_POS_Y;
        void move_player(Controller::action act, Maze *pmaze);
};

class MAZE_GAME{
public:
    void InitGame();
    Maze maze1;
    Player player1;
private:

};

struct Cell{
         int x = -1;
         int y = -1;
};








#endif