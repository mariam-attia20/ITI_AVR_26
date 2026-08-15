//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include <util/delay.h>
//
//int main(){
////
//	 MDIO_vSetPinDir(DIO_PORTB ,DIO_PIN0 ,DIO_OUTPUT); //led pin
//	 MDIO_vSetPinDir(DIO_PORTB ,DIO_PIN1 ,DIO_INPUT); //bottom pin
//	 // turn on pull up resistor
//	 MDIO_vSetPinVal(DIO_PORTB , DIO_PIN1 , DIO_HIGH);
//
//	 while(1){
//
//		 if(MDIO_u8GetPinVal(DIO_PORTB ,DIO_PIN1) == 0){
//			 _delay_ms(20);
//			 while(MDIO_u8GetPinVal(DIO_PORTB ,DIO_PIN1) == 0){}
//			 _delay_ms(20);
//				 MDIO_vTogPinVal(DIO_PORTB ,DIO_PIN0 );
//			 }
//		 }
//
//
//
//
//
//
//
//
//	return 0;
//}
//
