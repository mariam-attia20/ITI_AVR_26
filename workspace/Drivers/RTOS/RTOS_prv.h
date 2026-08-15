#ifndef RTOS_PRV_H
#define RTOS_PRV_H

#include "../LIB/STD_TYPES.h"

typedef enum
{
    Suspended,
    Running
}TaskStates;

typedef struct
{
    void        (*TaskFunction)(void);
    u16         Periodicity;
    TaskStates  State;
}Task_t;


#define OUT_OF_BOUNDRY      1
#define PRIORITY_COLLISION  2
#define NO_TASK_EXISTS      3




#endif
