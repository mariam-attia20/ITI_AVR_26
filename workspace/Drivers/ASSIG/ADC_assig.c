#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "../MCAL/ADC/ADC_int.h"


int main(void) {
    u16 L_u16LdrVal = 0;
    MDIO_vSetPortDir(DIO_PORTC, DIO_OUTPUT);
    MDIO_vSetPortVal(DIO_PORTC, 0x00);

   MADC_init();

    while (1) {
        L_u16LdrVal = u16 MADC_u16ReadAnaloge(0);;

        if (L_u16LdrVal < 300) {

        	 MDIO_vSetPortVal(DIO_PORTC, DIO_LOW);
        }
        else if (L_u16LdrVal >= 300 && L_u16LdrVal < 700) {

        	 MDIO_vSetPortVal(DIO_PORTC, DIO_HIGH);
        }
        else {

        	 MDIO_vSetPortVal(DIO_PORTC, DIO_HIGH);
        }

        _delay_ms(100);
    }
}
