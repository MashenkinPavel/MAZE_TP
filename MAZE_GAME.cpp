#include "global.h"
#include <stdio.h>
#include <Stack.h>
#include "MAZE_GAME.h"
#include <stdio.h>


bool Maze::isValidCell(int x, int y) {
  if ((x < 0) || (x >= COLCOUNT)) return false;
  if ((y < 0) || (y >= ROWCOUNT)) return false;
  return true;
}

void Maze::init() {
  for (int i = 0; i <= COLCOUNT; i++) {
    for (int j = 0; j < ROWCOUNT; j++) {
      maze_wallsX[i][j] = true;
    }
  }

  for (int i = 0; i < COLCOUNT; i++) {
    for (int j = 0; j <= ROWCOUNT; j++) {
      maze_wallsY[i][j] = true;
    }
  }
}

void Player::move_player(Controller::action act, Maze *pmaze) {
  switch (act) {
      case Controller::action::PRESS_UP:
        if (!pmaze->IsWallY(pos_X, pos_Y) && pos_Y > 0)
          --pos_Y;
        break;
      case Controller::action::PRESS_DOWN:
        if (!pmaze->IsWallY(pos_X, pos_Y + 1) && pos_Y < (ROWCOUNT - 1))
          ++pos_Y;
        break;
      case Controller::action::PRESS_RIGHT:
        if (!pmaze->IsWallX(pos_X + 1, pos_Y) && pos_X < (COLCOUNT - 1))
          ++pos_X;
        break;
      case Controller::action::PRESS_LEFT:
        if (!pmaze->IsWallX(pos_X, pos_Y) && pos_X > 0)
          --pos_X;
        break;
    }
}

void Maze::generateMaze(int startX, int startY) {
  bool visited[ROWCOUNT][COLCOUNT]{ false };  // i j   - - columns
  Stack<Cell> localstack;
  const int direction_x[4] = { 0, 1, 0, -1 };  // up  right down left
  const int direction_y[4] = { -1, 0, 1, 0 };
  Cell loccell;
  loccell.x = startX;
  loccell.y = startY;
  localstack.push(loccell);
  visited[startY][startX] = true;
  while (localstack.length() > 0) {
    Cell current = localstack.pop();
    int availableDirs[4]{ -1, -1, -1, -1 };
    int count = 0;
    for (int dir = 0; dir < 4; dir++) {
      int nx = current.x + direction_x[dir];
      int ny = current.y + direction_y[dir];
      if (isValidCell(nx, ny) && !visited[ny][nx]) {
        availableDirs[count++] = dir;
      }
    }

    if (count > 0) {
      // Возвращаем текущую клетку в стек
      localstack.push(current);
      // Выбираем случайное направление
      int dir = availableDirs[rand() % count];
      int nx = current.x + direction_x[dir];
      int ny = current.y + direction_y[dir];

      // Убираем стену между клетками
      int wallX = current.x * 2 + 1 + direction_x[dir];
      int wallY = current.y * 2 + 1 + direction_y[dir];

      if (direction_y[dir] == 0) {  // Nx normal-oriented faces
        int Xface_number = -1;
        if (direction_x[dir] == -1) Xface_number = current.x;
        if (direction_x[dir] == 1) Xface_number = current.x + 1;
        maze_wallsX[Xface_number][ny] = false;
      }

      if (direction_x[dir] == 0) {  //Ny normal-oriented fases
        int Yface_number = -1;
        if (direction_y[dir] == -1) {
          Yface_number = current.y;
        }
        if (direction_y[dir] == 1) {
          Yface_number = current.y + 1;
        }
        maze_wallsY[current.x][Yface_number] = false;
      }

      // Переходим к новой клетке
      visited[ny][nx] = 1;
      Cell newcell;
      newcell.x = nx;
      newcell.y = ny;
      localstack.push(newcell);
    }
  }
}

void MAZE_GAME::InitGame() {
  //init maze1
  maze1.init();
  maze1.generateMaze(0, 0);
}
