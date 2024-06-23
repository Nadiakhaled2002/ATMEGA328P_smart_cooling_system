/*
 * TIMER1_program.c
 *
 *  Created on: May 28, 2024
 *      Author: nadia
 */
#include "../../STD/STD_TYPES.h"
#include "../../STD/BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"



void TMR1_init(void)
{
//fast pwm
	 //fast pwm mode
	 SET_BIT(TCCR1A,WGM10);
	 CLR_BIT(TCCR1A,WGM11);
	 SET_BIT(TCCR1B,WGM12);
	 CLR_BIT(TCCR1B,WGM13);

	 //non inverting PWM
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
}
void TMR1_start(void)
{
	 SET_BIT(TCCR1B,CS10);
	 SET_BIT(TCCR1B,CS11);
     CLR_BIT(TCCR1B,CS12);
}
void TMR1_stop(void)
{
	 CLR_BIT(TCCR1B,CS10);
	 CLR_BIT(TCCR1B,CS11);
    CLR_BIT(TCCR1B,CS12);
}


void TMR1_setDutyCycle(u8 dutyCyclye)
{
	 if(dutyCyclye<=100)
		 {
		 u16OCR01A=((u16)(dutyCyclye*250)/100)-1;
		 }
}
