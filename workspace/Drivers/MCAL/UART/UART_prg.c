/*
 * UART_prg.c
 *
 *  Created on: 6 Aug 2026
 *      Author: LOQ
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_int.h"
#include "UART_prv.h"



void MUART_vInit(void)
{
	//2 way communication
	UCSRB = 0b00011000;
	//enable ucsrc |asyn|no parity| 1 stop bit |8bit data|
     UCSRC = 0b10000110;

     //boud rate 9600
     UBRRL = 51 ;
     UBRRH = 0 ;


}

void MUART_vTransmit(u8 A_u8Byte)
{
   //UDR
	//wait till udr reg is ready
	while(!GET_BIT(UCSRA , 5));

	UDR = A_u8Byte;
}

u8 MUART_u8Receive(void){

	while(!GET_BIT(UCSRA , 7));
	return UDR ;

}

