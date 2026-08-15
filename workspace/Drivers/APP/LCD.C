///*
// * LCD.C
// *
// *  Created on: 1 Aug 2026
// *      Author: LOQ
// */
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../HAL/LCD/LCD_int.h"
//#include <util/delay.h>
//
//
//#define LCD_ROW0_START   0x80
//#define LCD_ROW1_START   0xC0
//
//int main(void)
//{
//
//    HLCD_vInit();
//
//    u8 A_u8Name[] = "mariam";
//    u8 L_u8CharIdx = 0;
//    u8 L_u8StartCol = 0;
//
//    while(1)
//    {
//
//        for (L_u8StartCol = 0; L_u8StartCol < 16; L_u8StartCol++)
//        {
//
//        	HLCD_vSendCmd(0x01);
//            _delay_ms(2);
//
//
//            for (L_u8CharIdx = 0; A_u8Name[L_u8CharIdx] != '\0'; L_u8CharIdx++)
//            {
//
//                u8 L_u8CurrentCol = L_u8StartCol + L_u8CharIdx;
//
//
//                if (L_u8CurrentCol < 16)
//                {
//
//                    if (L_u8CharIdx % 2 == 0)
//                    {
//
//                    	HLCD_vSendCmd(LCD_ROW0_START + L_u8CurrentCol);
//                    }
//                    else
//                    {
//
//                    	HLCD_vSendCmd(LCD_ROW1_START + L_u8CurrentCol);
//                    }
//
//
//                    HLCD_vSendChar(A_u8Name[L_u8CharIdx]);
//                }
//            }
//
//
//            _delay_ms(300);
//        }
//    }
//
//    return 0;
//}
