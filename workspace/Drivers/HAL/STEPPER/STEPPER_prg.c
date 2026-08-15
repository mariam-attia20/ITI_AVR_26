/*
 * STEPPER_prg.c
 *
 *  Created on: 29 Jul 2026
 *      Author: LOQ
 */

#include "STEPPER_Int.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"

void HSTEPPER_vInit(){
    MDIO_vSetPinDir(Stepper_Port , Stepper_Blue , DIO_OUTPUT);
    MDIO_vSetPinDir(Stepper_Port , Stepper_PINK , DIO_OUTPUT);
    MDIO_vSetPinDir(Stepper_Port , Stepper_ORANGE , DIO_OUTPUT);
    MDIO_vSetPinDir(Stepper_Port , Stepper_YELLOW , DIO_OUTPUT);


}
void HTEPPER_vRotateCW(f64 A_f64StepDelay){
    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_HIGH);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);
    _delay_ms(A_f64StepDelay);

    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_HIGH);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);
    _delay_ms(A_f64StepDelay);

    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_HIGH);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);
    _delay_ms(A_f64StepDelay);

    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_HIGH);
    _delay_ms(A_f64StepDelay);
}
void HTEPPER_vRotateCCW(f64 A_f64StepDelay){
    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_HIGH);
    _delay_ms(A_f64StepDelay);

    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_HIGH);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);
    _delay_ms(A_f64StepDelay);

    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_HIGH);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);
    _delay_ms(A_f64StepDelay);

    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_HIGH);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);
    _delay_ms(A_f64StepDelay);

}

void HSTEPPER_vStop(){
    MDIO_vSetPinVal(Stepper_Port , Stepper_Blue , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_PINK , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_YELLOW , DIO_LOW);
    MDIO_vSetPinVal(Stepper_Port , Stepper_ORANGE , DIO_LOW);

}
