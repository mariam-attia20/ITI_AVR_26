/*
 * LCD_prg.c
 *
 *  Created on: Jul 26, 2026
 *      Author: Hager Adel
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

#include "LCD_int.h"
#include "LCD_cfg.h"

void HLCD_vInit(void)
{
	MDIO_vSetPortDir(LCD_DATA_PORT, DIO_PORT_OUTPUT);

	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RS, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RW, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_E, DIO_OUTPUT);


	_delay_ms(50);
	HLCD_vSendCmd(0x38);

	_delay_ms(1);
	HLCD_vSendCmd(0x0C);

	_delay_ms(1);
	HLCD_vSendCmd(0x01);

	_delay_ms(2);
	HLCD_vSendCmd(0x06);
}


void HLCD_vSendCmd(u8 A_u8cmd)
{

	/* Control RS to Send Command */
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS, DIO_LOW);

	/* Reset RW to Enable Writing */
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW, DIO_LOW);

	/* Write instruction */
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8cmd);

	/* Pulse on Enable */
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_E, DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_E, DIO_LOW);
	_delay_ms(1);

}
void HLCD_vSendChar(u8 A_u8Char)
{
	/* Control RS to Send Data */
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS, DIO_HIGH);

	/* Reset RW to Enable Writing */
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW, DIO_LOW);

	/* Write instruction */
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);

	/* Pulse on Enable */
	/* Pulse on Enable */
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_E, DIO_HIGH);
	_delay_us(1); // 1 microsecond is more than enough for the high pulse
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_E, DIO_LOW);
	_delay_ms(2); // Keep a 2ms delay here to let the LCD process the character

}


void HLCD_vDisplayString(u8 A_u8Str[])
{
	u8 L_u8Index=0;

	for( L_u8Index=0; A_u8Str[L_u8Index] != '\0'; L_u8Index++)
	{
		HLCD_vSendChar(A_u8Str[L_u8Index]);
	}
}

void HLCD_vPrintNumber(u32 A_u32Number)
{
	u8 l_u8Index = 0;
	u8 L_u8digits[10]={0};

	while(A_u32Number>0)
	{
		L_u8digits[l_u8Index]= (A_u32Number % 10) + '0';
		A_u32Number = A_u32Number/10;
		l_u8Index++;
	}

	for(u8 l_u8Index = 9; l_u8Index>=0 ; l_u8Index--)
	{
		if(L_u8digits[l_u8Index] == 0) continue;
		HLCD_vSendChar(L_u8digits[l_u8Index]);
	}
}

void HLCD_vClearScreen(void)
{
	HLCD_vSendCmd(0x01);

}
