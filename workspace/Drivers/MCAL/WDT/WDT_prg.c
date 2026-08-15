/*
 * WDT_prg.c
 *
 *  Created on: 5 Aug 2026
 *      Author: LOQ
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_prv.h"
#include "WDT_int.h"
#include "WDT_cfg.h"

void MWDT_vEnable(void)
{
	SET_BIT(WDTCR , 3);
}

void MWDT_vDisable(void)
{
	WDTCR |= 0b00011000 ;

	WDTCR =	0;
}

void MWDT_vSleep(void)
{
	WDTCR &=0xF8;
	WDTCR |= WDT_PRESCALLER;
}
