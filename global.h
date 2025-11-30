#ifndef GLOBAL_H
#define GLOBAL_H
#define X_SIZE  9
#define Y_SIZE  9
#define COLCOUNT 12               //   (128-18)/9
#define ROWCOUNT 7        //7    64/9
#define MAX_LEVELCOUNT 2
#define START_POS_X 0
#define START_POS_Y 0
#define EXIT_POS_X (COLCOUNT - 1)
#define EXIT_POS_Y (ROWCOUNT - 1)
#define TIMER_POS_X 110
#define TIMER_POS_Y 0 

const int wall_difficult = 1;
void waitForButtonPress();



#endif
