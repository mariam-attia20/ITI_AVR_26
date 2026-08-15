/*
 * ADC_int.h
 *
 *  Created on: 2 Aug 2026
 *      Author: LOQ
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "ADC_prv.h"

#define CHANEL_0 0
#define CHANEL_1 1
#define CHANEL_2 2
#define CHANEL_3 3
#define CHANEL_4 4
#define CHANEL_5 5
#define CHANEL_6 6
#define CHANEL_7 7

#define ADC_MAX_VAL 1024
#define ADC_VREF 5



void MADC_init(void);

u16 MADC_u16ReadAnaloge(u8 channel_no);




#endif /* MCAL_ADC_ADC_INT_H_ */
