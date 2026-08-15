//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include <util/delay.h>
//
//#define KPD_PORT     DIO_PORTA
//#define LED_PORT     DIO_PORTB
//
//#define COLS_NUM     3
//#define ROWS_NUM     3
//#define START_ROW    3
//void Anim_vFlashAll(void);
//void Anim_vChaserRight(void);
//void Anim_vChaserLeft(void);
//void Anim_vPingPong(void);
//void Anim_vConverging(void);
//void Anim_vDiverging(void);
//void Anim_vAlternate(void);
//void Anim_vBinaryCounter(void);
//
//int main(void)
//{
//
//    MDIO_vSetPortDir(KPD_PORT, 0x07);
//
//
//    MDIO_vSetPortVal(KPD_PORT, 0xFF);
//
//
//    MDIO_vSetPortDir(LED_PORT, DIO_OUTPUT);
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//
//    u8 L_u8PressedKey = 0;
//
//    while(1)
//    {
//        L_u8PressedKey = 0;
//
//
//        for(u8 col = 0; col < COLS_NUM; col++)
//        {
//
//            MDIO_vSetPinVal(KPD_PORT, col, DIO_LOW);
//
//            /* Check Rows */
//            for(u8 row = START_ROW; row < (START_ROW + ROWS_NUM); row++)
//            {
//                /* Check if button in current row is pressed */
//                if(MDIO_u8GetPinVal(KPD_PORT, row) == DIO_LOW)
//                {
//                    _delay_ms(20); // Debounce delay
//
//                    if(MDIO_u8GetPinVal(KPD_PORT, row) == DIO_LOW)
//                    {
//
//                        L_u8PressedKey = ((row - START_ROW) * COLS_NUM) + col + 1;
//
//
//                        while(MDIO_u8GetPinVal(KPD_PORT, row) == DIO_LOW);
//                    }
//                }
//            }
//
//
//            MDIO_vSetPinVal(KPD_PORT, col, DIO_HIGH);
//        }
//
//
//        switch(L_u8PressedKey)
//        {
//            case 1: Anim_vFlashAll();      break;
//            case 2: Anim_vChaserRight();   break;
//            case 3: Anim_vChaserLeft();    break;
//            case 4: Anim_vPingPong();      break;
//            case 5: Anim_vConverging();    break;
//            case 6: Anim_vDiverging();     break;
//            case 7: Anim_vAlternate();     break;
//            case 8: Anim_vBinaryCounter(); break;
//            case 9:
//                MDIO_vSetPortVal(LED_PORT, 0x00);
//                break;
//            default:
//
//                break;
//        }
//    }
//    return 0;
//}
//
//
//
//void Anim_vFlashAll(void) {
//    for(u8 i=0; i<3; i++) {
//        MDIO_vSetPortVal(LED_PORT, 0xFF); _delay_ms(150);
//        MDIO_vSetPortVal(LED_PORT, 0x00); _delay_ms(150);
//    }
//}
//
//void Anim_vChaserRight(void) {
//    for(u8 i=0; i<8; i++) {
//        MDIO_vSetPortVal(LED_PORT, (1 << i));
//        _delay_ms(80);
//    }
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//}
//
//void Anim_vChaserLeft(void) {
//    for(s8 i=7; i>=0; i--) {
//        MDIO_vSetPortVal(LED_PORT, (1 << i));
//        _delay_ms(80);
//    }
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//}
//
//void Anim_vPingPong(void) {
//    Anim_vChaserRight();
//    Anim_vChaserLeft();
//}
//
//void Anim_vConverging(void) {
//    for(u8 i=0; i<4; i++) {
//        MDIO_vSetPortVal(LED_PORT, (1 << i) | (1 << (7 - i)));
//        _delay_ms(150);
//    }
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//}
//
//void Anim_vDiverging(void) {
//    for(s8 i=3; i>=0; i--) {
//        MDIO_vSetPortVal(LED_PORT, (1 << i) | (1 << (7 - i)));
//        _delay_ms(150);
//    }
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//}
//
//void Anim_vAlternate(void) {
//    for(u8 i=0; i<4; i++) {
//        MDIO_vSetPortVal(LED_PORT, 0x55); _delay_ms(200); // 01010101
//        MDIO_vSetPortVal(LED_PORT, 0xAA); _delay_ms(200); // 10101010
//    }
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//}
//
//void Anim_vBinaryCounter(void) {
//    for(u16 i=0; i<30; i++) {
//        MDIO_vSetPortVal(LED_PORT, (u8)i);
//        _delay_ms(100);
//    }
//    MDIO_vSetPortVal(LED_PORT, 0x00);
//}
