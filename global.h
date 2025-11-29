#ifndef GLOBAL_H
#define GLOBAL_H
#define X_SIZE  9
#define Y_SIZE  9
#define COLCOUNT (128/Y_SIZE)-2         //7
#define ROWCOUNT 64/X_SIZE      //14
#define MAX_LEVELCOUNT 2
#define START_POS_X 0
#define START_POS_Y 0
#define EXIT_POS_X (COLCOUNT - 1)
#define EXIT_POS_Y (ROWCOUNT - 1)


void waitForButtonPress();



#endif
