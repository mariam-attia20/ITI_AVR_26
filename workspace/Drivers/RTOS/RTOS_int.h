/*
 * RTOS_int.h
 *
 *  Created on: 10 Aug 2026
 *      Author: LOQ
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_

#include "../LIB/STD_TYPES.h"




void RTOS_vStartOS(void);
u8 RTOS_u8CreateTask(void (*Fptr)(void), u16 A_u16Periodicity, u8 A_u8Priority, u8 A_u8FirstDelay);
u8 RTOS_DeleteTask(u8 A_u8Priority);
u8 RTOS_SuspendTask(u8 A_u8Priority);
u8 RTOS_ResumeTask(u8 A_u8Priority);


#endif /* RTOS_RTOS_INT_H_ */
