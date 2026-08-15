/////*
//// * WDT_lab.C
//// *
//// *  Created on: 6 Aug 2026
//// *      Author: LOQ
//// */
////
////#include "../LIB/STD_TYPES.h"
////#include "../MCAL/DIO/DIO_int.h"
////#include "../MCAL/WDT/WDT_int.h"
////
////#include  <util/delay.h>
////
////int main()
////{
////    	MDIO_vInit();
////    	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
////    	MDIO_vSetPinVal(DIO_PORTA , DIO_PIN0 , DIO_HIGH);
////    	_delay_ms(500);
////
////    	MDIO_vSetPinVal(DIO_PORTA , DIO_PIN0 , DIO_LOW);
////    	MWDT_vSleep();
////    	MWDT_vEnable();
////	while (1)
////	{
////
////
////
////	}
////
////
////	return 0 ;
////}
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/TWI/TWI_int.h"
//
//#include <util/delay.h>
//
//void HEEPROM_vWriteByte( u8 A_u8Byte , u8 A_u8SLAadd , u16 A_u16WordAdd )
//{
//	MTWI_u8ReSendStartCondition();
//	MTWI_u8SendSLA_RW( A_u16WordAdd , TWI_WRITE);
//
//	MTWI_u8SendByte((u8)A_u16WordAdd);
//	MTWI_u8SendByte(A_u8Byte);
//
//	MTWI_u8SendEndCondition();
//}
//
//void HEEPROM_vReadByte( u8 A_u8SLAadd , u16 A_u16WordAdd )
//{
//
//}
