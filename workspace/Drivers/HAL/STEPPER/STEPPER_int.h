/*
 * STEPPER_int.h
 *
 *  Created on: 29 Jul 2026
 *      Author: LOQ
 */

#ifndef HAL_STEPPER_STEPPER_INT_H_
#define HAL_STEPPER_STEPPER_INT_H_

#include "../../LIB/STD_TYPES.h"

#define Stepper_Port DIO_PORTA
#define Stepper_Blue  DIO_PIN1
#define Stepper_PINK  DIO_PIN0
#define Stepper_ORANGE DIO_PIN2
#define Stepper_YELLOW DIO_PIN3

void HSTEPPER_vInit();

void HTEPPER_vRotateCW(f64 A_f64StepDelay);
void HTEPPER_vRotateCCW(f64 A_f64StepDelay);

void HSTEPPER_vStop();

#endif /* HAL_STEPPER_STEPPER_INT_H_ */
