/*
 * DC_TIMER.c
 *
 *  Created on: 15 Aug 2026
 *      Author: LOQ
 *
 *  Requirement:
 *      CW for 5 sec -> CCW for 3 sec -> STOP for 5 sec
 *
 *  Implementation:
 *      Timer0 is used in CTC mode to generate ~250 ms ticks.
 *      The same sequence can be implemented in Timer0 OVF mode by using the
 *      Timer0 overflow interrupt callback and counting overflows.
 */

#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/TIMER/TIMER_int.h"

#define MOTOR_PORT      DIO_PORTA
#define MOTOR_CW_PIN    DIO_PIN0
#define MOTOR_CCW_PIN   DIO_PIN1

#define TIMER0_CTC_TICK_COUNT   16U
#define CW_TICKS                20U   /* ~5 sec at ~250 ms per tick */
#define CCW_TICKS               12U   /* ~3 sec at ~250 ms per tick */
#define STOP_TICKS              20U   /* ~5 sec at ~250 ms per tick */

typedef enum {
    STATE_CW,
    STATE_CCW,
    STATE_STOP
} MotorState_t;

static volatile u8 g_u8TimerTickFlag = 0;

static void vMotorSetDirection(MotorState_t A_xState)
{
    switch(A_xState)
    {
        case STATE_CW:
            MDIO_vSetPinVal(MOTOR_PORT, MOTOR_CW_PIN, DIO_HIGH);
            MDIO_vSetPinVal(MOTOR_PORT, MOTOR_CCW_PIN, DIO_LOW);
            break;

        case STATE_CCW:
            MDIO_vSetPinVal(MOTOR_PORT, MOTOR_CW_PIN, DIO_LOW);
            MDIO_vSetPinVal(MOTOR_PORT, MOTOR_CCW_PIN, DIO_HIGH);
            break;

        case STATE_STOP:
        default:
            MDIO_vSetPinVal(MOTOR_PORT, MOTOR_CW_PIN, DIO_LOW);
            MDIO_vSetPinVal(MOTOR_PORT, MOTOR_CCW_PIN, DIO_LOW);
            break;
    }
}

static void vTimer0CTC_250msTick(void)
{
    static u16 L_u16CTCCounter = 0;

    L_u16CTCCounter++;

    if(L_u16CTCCounter >= TIMER0_CTC_TICK_COUNT)
    {
        L_u16CTCCounter = 0;
        g_u8TimerTickFlag = 1;
    }
}

static void vTimer0Init_CTC_250ms(void)
{
    /* CTC mode: WGM01 = 1, WGM00 = 0 */
    CLR_BIT(TCCR0, 6);
    SET_BIT(TCCR0, 3);

    /* Prescaler = 64 -> CS01 = 1, CS00 = 0, CS02 = 0 */
    CLR_BIT(TCCR0, 2);
    SET_BIT(TCCR0, 1);
    CLR_BIT(TCCR0, 0);

    /* OCR0 = 249 so each compare match is 250 * 64us = 16ms. Every 16 matches => ~250ms */
    OCR0 = 249;
    TCNT0 = 0;

    /* Disable overflow interrupt and enable CTC interrupt */
    CLR_BIT(TIMSK, 0);
    SET_BIT(TIMSK, 1);

    MTIMERS_vSetInterval_CTC(vTimer0CTC_250msTick, 1U);
}

int main(void)
{
    MotorState_t L_xCurrentState = STATE_CW;
    u16 L_u16TickCounter = 0;

    MDIO_vSetPinDir(MOTOR_PORT, MOTOR_CW_PIN, DIO_OUTPUT);
    MDIO_vSetPinDir(MOTOR_PORT, MOTOR_CCW_PIN, DIO_OUTPUT);

    vMotorSetDirection(L_xCurrentState);
    vTimer0Init_CTC_250ms();
    sei();

    while(1)
    {
        if(g_u8TimerTickFlag == 1U)
        {
            g_u8TimerTickFlag = 0;
            L_u16TickCounter++;

            switch(L_xCurrentState)
            {
                case STATE_CW:
                    if(L_u16TickCounter >= CW_TICKS)
                    {
                        L_xCurrentState = STATE_CCW;
                        L_u16TickCounter = 0;
                        vMotorSetDirection(L_xCurrentState);
                    }
                    break;

                case STATE_CCW:
                    if(L_u16TickCounter >= CCW_TICKS)
                    {
                        L_xCurrentState = STATE_STOP;
                        L_u16TickCounter = 0;
                        vMotorSetDirection(L_xCurrentState);
                    }
                    break;

                case STATE_STOP:
                default:
                    if(L_u16TickCounter >= STOP_TICKS)
                    {
                        L_xCurrentState = STATE_CW;
                        L_u16TickCounter = 0;
                        vMotorSetDirection(L_xCurrentState);
                    }
                    break;
            }
        }
    }

    return 0;
}
