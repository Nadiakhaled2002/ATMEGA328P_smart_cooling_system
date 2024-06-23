/*
 * main.c
 *
 *  Created on: May 27, 2024
 *      Author: nadia
 */
#define F_CPU 16000000UL
#include <util/delay.h>

#include "std/STD_TYPES.h"
#include "std/BIT_MATH.h"

#include "HAL/DCM/DCMOTOR_interface.h"
#include "HAL/Temp/TEMP_interface.h"
#include "HAL/LCD/LCD_interface.h"


#include "MCAL/DIO/DIO_interface.h"



#define LOW  20
#define MEDIUM  50
#define HIGH  90

int main(void)
{
u8 x=0;

	LM35_init();
	LCD_init();






	while(1)
	{
		LM35_sendTemp(&x);

		if((x>=30)&&(x<35))
		{
			L293D_DCMOTOR_speed('A',LOW,1);

		}
		else if((x>=35)&&(x<40))
		{
			L293D_DCMOTOR_speed('A',MEDIUM,1);
		}
		else if(x>=40)
		{
			L293D_DCMOTOR_speed('A',HIGH,1);
		}
		else if(x<30)
		{
			L293D_DCMOTOR_stop('A');
		}


		 LCD_writeNumber(x);

				       LCD_sendChar('c');

				         _delay_ms(300);
				         LCD_clear();

				         if(x>=30)
				         		{

				       _delay_ms(300);
				       L293D_DCMOTOR_speed('A',1,1);

				        	 _delay_ms(300);
				         		}
				         x=0;

	}
}

