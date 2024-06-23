/*
 * TEMP_program.c
 *
 *  Created on: May 27, 2024
 *      Author: nadia
 */



#include "../../STD/STD_TYPES.h"
#include "../../STD/BIT_MATH.h"

#include"TEMP_interface.h"
#include"TEMP_config.h"

/* MCAL */
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_private.h"
#include "../../MCAL/ADC/ADC_interface.h"







void LM35_init()
{
DIO_setPinDirection(DATA_PORT,DATA_PIN,DIO_PIN_INPUT);
ADC_init(ADC_REF_AVCC);
}

void LM35_sendTemp(u32*num)
{
	ADC_getDigitalValue(ADC_CHANNEL1,&x);

	 c=((u32)x*5000UL)/1020;

	*num=(c/10);

}



