/*
 * spi_assig.c
 *
 *  Created on: 15 Aug 2026
 *      Author: LOQ
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/SPI/SPI_int.h"

#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/SPI/SPI_int.h"

int main(void)
{
    u8 L_u8ReceivedTemp = 0;


    MDIO_vSetPinDir(DIO_PORTA, DIO_PIN0, DIO_OUTPUT); // Motor IN1
    MDIO_vSetPinDir(DIO_PORTA, DIO_PIN1, DIO_OUTPUT); // Motor IN2


    MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
    MDIO_vSetPinVal(DIO_PORTA, DIO_PIN1, DIO_LOW);


    MSPI_vInit();

    while(1)
    {

        L_u8ReceivedTemp = MSPI_u8Receive();


        if(L_u8ReceivedTemp > 26)
        {
            //  Clockwise direction
            MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
            MDIO_vSetPinVal(DIO_PORTA, DIO_PIN1, DIO_LOW);
        }
        else
        {
            // Turn off DC Motor
            MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
            MDIO_vSetPinVal(DIO_PORTA, DIO_PIN1, DIO_LOW);
        }
    }
}

