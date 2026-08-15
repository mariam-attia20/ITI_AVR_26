/*
 * DC_motor.c
 *
 *  Created on: 28 Jul 2026
 *      Author: LOQ
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>

int main(){
	//motor pins
	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN1 , DIO_OUTPUT);
	// switches pins
	MDIO_vSetPinDir(DIO_PORTB , DIO_PIN0 , DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTB , DIO_PIN0 , DIO_HIGH);//pull up resistance
	MDIO_vSetPinDir(DIO_PORTB , DIO_PIN1 , DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTB , DIO_PIN1 , DIO_HIGH);//pull up resistance
	while(1){
		if(MDIO_u8GetPinVal(DIO_PORTB , DIO_PIN0)== 0 && MDIO_u8GetPinVal(DIO_PORTB , DIO_PIN1)== 1 ){
			//direction 1
			MDIO_vSetPinVal(DIO_PORTA , DIO_PIN0 , DIO_HIGH);
			MDIO_vSetPinVal(DIO_PORTA , DIO_PIN1 , DIO_LOW);
		}else if (MDIO_u8GetPinVal(DIO_PORTB , DIO_PIN1)== 0 && MDIO_u8GetPinVal(DIO_PORTB , DIO_PIN0)== 1){
			//direction 2
			MDIO_vSetPinVal(DIO_PORTA , DIO_PIN1 , DIO_HIGH);
			MDIO_vSetPinVal(DIO_PORTA , DIO_PIN0 , DIO_LOW);
		}else if(MDIO_u8GetPinVal(DIO_PORTB , DIO_PIN0)== 0 && MDIO_u8GetPinVal(DIO_PORTB , DIO_PIN1)== 0){
			//stop the motor
			MDIO_vSetPinVal(DIO_PORTA , DIO_PIN1 , DIO_LOW);
			MDIO_vSetPinVal(DIO_PORTA , DIO_PIN0 , DIO_LOW);
		}


	}


	return 0 ;
}
