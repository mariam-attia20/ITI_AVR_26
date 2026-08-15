///*
// * INT.c
// *
// *  Created on: Jul 30, 2026
// *      Author: Hager Adel
// */
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/EXTI/EXTI_int.h"
//#include "../MCAL/GIE/GIE_int.h"
//
//#include <util/delay.h>
//
//volatile u8 G_u8AnimationMode =0;
//
//void ChangeAnimation(void)
//{
//	G_u8AnimationMode++;
//	if(G_u8AnimationMode == 3)
//	{
//		G_u8AnimationMode =0;
//	}
//
//}
//
//
//int main()
//{
//	u8 i =0;
//
//	MDIO_vSetPortDir(DIO_PORTA, DIO_PORT_OUTPUT);
//
//	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN2,DIO_INPUT);
//	MDIO_vSetPinVal(DIO_PORTD,DIO_PIN2,DIO_HIGH);
//
//
//	MEXTI_vInit();
//
//	MGIE_vEnableGlobalInterrupt();
//
//	MEXTI_vCallBackFunction(ChangeAnimation, 0);
//
//	while(1)
//	{
//
//		switch (G_u8AnimationMode)
//		{
//		case 0:
//			for (i=0; i<8 ; i++)
//			{
//				MDIO_vSetPinVal(DIO_PORTA, i,DIO_HIGH);
//				_delay_ms(1500);
//			}
//			break;
//		case 1:
//			for (i=7; i>0 ; i--)
//			{
//				MDIO_vSetPinVal(DIO_PORTA, i,DIO_HIGH);
//				_delay_ms(1500);
//			}
//			break;
//
//		case 2:
//			MDIO_vSetPortVal(DIO_PORTA , 0xFF);
//			_delay_ms(3000);
//			MDIO_vSetPortVal(DIO_PORTA , 0x00);
//			_delay_ms(3000);
//
//				break;
//		}
//	}
//return 0;
//}
