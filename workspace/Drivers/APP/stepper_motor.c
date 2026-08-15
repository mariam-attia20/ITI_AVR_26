///*
// * stepper_motor.c
// *
// *  Created on: 29 Jul 2026
// *      Author: LOQ
// */
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include <util/delay.h>
//#include "../HAL/STEPPER/STEPPER_int.h"
//int main()
//{
//	HSTEPPER_vInit();
//	while(1){
//		for(u8 i = 0 ; i <128 ; i++){
//			HTEPPER_vRotateCW(5);
//		}
//		_delay_ms(1000);
//
//		HSTEPPER_vStop();
//		_delay_ms(1000);
//
//		for(u8 i = 0 ; i <128 ; i++){
//					HTEPPER_vRotateCCW(5);
//				}
//		_delay_ms(1000);
//
//		HSTEPPER_vStop();
//		_delay_ms(1000);
//	}
//	return 0 ;
//}
