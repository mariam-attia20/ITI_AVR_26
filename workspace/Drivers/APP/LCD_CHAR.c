//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../HAL/LCD/LCD_int.h"
//#include <util/delay.h>
//
//
//void HLCD_vDisplaySpecialCharacter(u8 *A_pu8Pattern, u8 A_u8BlockNo, u8 A_u8Row, u8 A_u8Col);
//
//int main(void)
//{
//
//    HLCD_vInit();
//
//
//    u8 L_u8CustomUpperM[8] = {
//        0b10001,  // *   *
//        0b11011,  // ** **
//        0b10101,  // * * *
//        0b10001,  // *   *
//        0b10001,  // *   *
//        0b10001,  // *   *
//        0b10001,  // *   *
//        0b00000   // (Bottom cursor line empty)
//    };
//
//    u8 L_u8CustomLowerM[8] = {
//        0b00000,  // (Top lines empty for short letter height)
//        0b00000,
//        0b11010,  // ** *
//        0b10101,  // * * *
//        0b10101,  // * * *
//        0b10101,  // * * *
//        0b10101,  // * * *
//        0b00000
//    };
//
//    HLCD_vDisplaySpecialCharacter(L_u8CustomUpperM, 0, 0, 0);
//    HLCD_vDisplaySpecialCharacter(L_u8CustomLowerM, 1, 0, 2);
//
//    while(1)
//    {
//
//    }
//
//    return 0;
//}
//
//
//void HLCD_vDisplaySpecialCharacter(u8 *A_pu8Pattern, u8 A_u8BlockNo, u8 A_u8Row, u8 A_u8Col)
//{
//    u8 L_u8LoopIndex = 0;
//    u8 L_u8CGRAMAddress = 0;
//
//
//    L_u8CGRAMAddress = A_u8BlockNo * 8;
//
//
//    HLCD_vSendCommand(0x40 + L_u8CGRAMAddress);
//
//
//    for(L_u8LoopIndex = 0; L_u8LoopIndex < 8; L_u8LoopIndex++)
//    {
//        HLCD_vSendChar(A_pu8Pattern[L_u8LoopIndex]);
//    }
//
//
//    if(A_u8Row == 0)
//    {
//        HLCD_vSendCommand(0x80 + A_u8Col); // Row 0 position address
//    }
//    else
//    {
//        HLCD_vSendCommand(0xC0 + A_u8Col); // Row 1 position address
//    }
//
//    HLCD_vSendChar(A_u8BlockNo);
//}
