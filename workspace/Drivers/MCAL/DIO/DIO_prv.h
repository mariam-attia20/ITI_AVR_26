/*
 * DIO_prv.h
 *
 *  Created on: 23 Jul 2026
 *      Author: LOQ
 */

#ifndef MCAL_DIO_DIO_PRV_H_
#define MCAL_DIO_DIO_PRV_H_


//PORT
//we use volatile to disable the optimiser to save value as a defult
#define PORTA   *((volatile  u8 *)(0x3B)) //Dereference for the value in this address
                                // we get this address from data sheet
#define PORTB   *((volatile  u8 *)(0x38))
#define PORTC   *((volatile  u8 *)(0x35))
#define PORTD   *((volatile  u8 *)(0x32))

//DDR
#define DDRA    *((volatile  u8 *)(0x3A))
#define DDRB    *((volatile  u8 *)(0x37))
#define DDRC    *((volatile  u8 *)(0x34))
#define DDRD    *((volatile  u8 *)(0x31))

//PIN

#define PINA   *((volatile  u8 *)(0x39))
#define PINB   *((volatile  u8 *)(0x36))
#define PINC   *((volatile  u8 *)(0x33))
#define PIND   *((volatile  u8 *)(0x30))







#endif /* MCAL_DIO_DIO_PRV_H_ */
