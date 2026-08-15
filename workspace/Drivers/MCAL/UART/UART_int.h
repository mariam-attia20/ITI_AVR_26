/*
 * UART_int.h
 *
 *  Created on: 6 Aug 2026
 *      Author: LOQ
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_vInit(void);

void MUART_vTransmit(u8 A_u8Byte);

u8 MUART_u8Receive(void);


#endif /* MCAL_UART_UART_INT_H_ */
