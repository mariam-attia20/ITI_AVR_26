///*
// * UART_LAD.c
// *
// *  Created on: 6 Aug 2026
// *      Author: LOQ
// */
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/GIE/GIE_int.h"
//#include "../HAL/LCD/LCD_int.h"
//#include "../MCAL/WDT/WDT_int.h"
//#include "../MCAL/UART/UART_int.h"
//#include <util/delay.h>
//
//
//int main()
//{
//	MDIO_vInit();
//	MUART_vInit();
//	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
//	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN1 , DIO_OUTPUT);
//	while(1)
//	{
//		switch(MUART_u8Receive())
//		{
//		case '1':
//			MDIO_vTogPinVal(DIO_PORTA , DIO_PIN0);
//			break;
//		case '2':
//			MDIO_vTogPinVal(DIO_PORTA , DIO_PIN1);
//		    break;
//		}
//     }
//
//	return 0 ;
//}
//
//
