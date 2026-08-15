//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include <util/delay.h>
//
//#define PORT_SEGMENT    DIO_PORTA
//#define PORT_BUTTON     DIO_PORTB
//
//#define PIN_INC_BUTTON  DIO_PIN0
//#define PIN_DEC_BUTTON  DIO_PIN1
//
//int main(void)
//{
//    // Index mapping: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//    u8 C_u8SegPatterns[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//
//    s8 L_s8Counter = 0;
//    u8 L_u8LastIncState = 1;
//    u8 L_u8LastDecState = 1;
//
//    MDIO_vSetPortDir(PORT_SEGMENT, DIO_PORT_OUTPUT);
//
//    MDIO_vSetPinDir(PORT_BUTTON, PIN_INC_BUTTON, DIO_INPUT);
//    MDIO_vSetPinDir(PORT_BUTTON, PIN_DEC_BUTTON, DIO_INPUT);
//
//
//    MDIO_vSetPinVal(PORT_BUTTON, PIN_INC_BUTTON, DIO_HIGH);
//    MDIO_vSetPinVal(PORT_BUTTON, PIN_DEC_BUTTON, DIO_HIGH);
//
//
//    MDIO_vSetPortVal(PORT_SEGMENT, ~C_u8SegPatterns[L_s8Counter]);
//
//    while(1)
//    {
//        u8 L_u8CurrentIncState = MDIO_u8GetPinVal(PORT_BUTTON, PIN_INC_BUTTON);
//        u8 L_u8CurrentDecState = MDIO_u8GetPinVal(PORT_BUTTON, PIN_DEC_BUTTON);
//
//
//        if (L_u8CurrentIncState == 0 && L_u8LastIncState == 1)
//        {
//            _delay_ms(20);
//            if (MDIO_u8GetPinVal(PORT_BUTTON, PIN_INC_BUTTON) == 0)
//            {
//                L_s8Counter++;
//                if (L_s8Counter > 9)
//                {
//                    L_s8Counter = 0;
//                }
//                MDIO_vSetPortVal(PORT_SEGMENT, ~C_u8SegPatterns[L_s8Counter]);
//            }
//        }
//        L_u8LastIncState = L_u8CurrentIncState;
//
//
//        if (L_u8CurrentDecState == 0 && L_u8LastDecState == 1)
//        {
//            _delay_ms(20);
//            if (MDIO_u8GetPinVal(PORT_BUTTON, PIN_DEC_BUTTON) == 0)
//            {
//                L_s8Counter--;
//                if (L_s8Counter < 0)
//                {
//                    L_s8Counter = 9;
//                }
//                MDIO_vSetPortVal(PORT_SEGMENT, ~C_u8SegPatterns[L_s8Counter]);
//            }
//        }
//        L_u8LastDecState = L_u8CurrentDecState;
//    }
//    return 0;
//}
