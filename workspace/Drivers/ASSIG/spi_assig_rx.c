/*
 * spi_assig_rx.c
 *
 *  Created on: 15 Aug 2026
 *      Author: LOQ
 */

#define F_CPU 1000000UL
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/SPI/SPI_int.h"

int main(void)
{

    u8 L_u8CurrentTemp = 24;

    MSPI_vInit();

    while(1)
    {
        L_u8CurrentTemp++;
        if(L_u8CurrentTemp > 30)
        {
            L_u8CurrentTemp = 22;
        }


        MSPI_vTransmit(L_u8CurrentTemp);

        // Wait 500ms between updates to avoid flooding the bus
        _delay_ms(500);
    }
}

