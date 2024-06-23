/*
 * DCMOTOR_program.c
 *
 *  Created on: Jan 26, 2024
 *      Author: nadia
 */
#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../std/STD_TYPES.h"
#include "../../std/BIT_MATH.h"

//********************************HAL********************//
#include "DCMOTOR_interface.h"

#include "DCMOTOR_config.h"
//********************************MCAL********************//
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "../../MCAL/TIMER1/TIMER1_private.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"




void L293D_DCMOTOR_start(u8 direction,u8 motor)
{
switch(motor)
{
case 'A':
{
	//motorA
	DIO_setPinDirection(H_EN1_PORT,H_EN1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_EN1_PORT,H_EN1_PIN,DIO_PIN_HIGH);
	DIO_setPinDirection(H_A1_PORT,H_A1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(H_A2_PORT,H_A2_PIN,DIO_PIN_OUTPUT);
	switch(direction)
	{
	case 1:
	{
	//CLCWISE
	DIO_setPinValue(H_A1_PORT,H_A1_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(H_A2_PORT,H_A2_PIN,DIO_PIN_LOW);
	break;
	}
	case 2:
	{
	//ANTI CLCWISE
	DIO_setPinValue(H_A1_PORT,H_A1_PIN,DIO_PIN_LOW);
	DIO_setPinValue(H_A2_PORT,H_A2_PIN,DIO_PIN_HIGH);
	break;
	}
	}
	break;
}
case 'B':
{
	//motorB
	DIO_setPinDirection(H_EN2_PORT,H_EN2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_EN2_PORT,H_EN2_PIN,DIO_PIN_HIGH);
    DIO_setPinDirection(H_A3_PORT,H_A3_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(H_A4_PORT,H_A4_PIN,DIO_PIN_OUTPUT);
	switch(direction)
	{
	case 1:
	{
	//CLCWISE
	DIO_setPinValue(H_A3_PORT,H_A3_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(H_A4_PORT,H_A4_PIN,DIO_PIN_LOW);
    break;
	}
	case 2:
	{
	//ANTI CLCWISE
	DIO_setPinValue(H_A3_PORT,H_A3_PIN,DIO_PIN_LOW);
	DIO_setPinValue(H_A4_PORT,H_A4_PIN,DIO_PIN_HIGH);
	break;
	}
	}


break;

}

}
}
void L293D_DCMOTOR_stop(u8 motor)
{
switch(motor)
{
case 'B':
{
	TMR1_stop();
break;
}
case 'A':
{


	DIO_setPinValue(H_A1_PORT,H_A1_PIN,DIO_PIN_LOW);
	DIO_setPinValue(H_A2_PORT,H_A2_PIN,DIO_PIN_LOW);
	DIO_setPinValue(H_EN1_PORT,H_EN1_PIN,DIO_PIN_LOW);

break;
}


}
}
void L293D_DCMOTOR_speed(u8 motor,u8 num,u8 direction)
{
	TMR1_init();
		TMR1_start();
		DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);

switch(motor)
{

case 'A':
{

	switch(direction)
	{
	case 1:
	{
	//CLCWISE

	DIO_setPinDirection(H_A2_PORT,H_A2_PIN,DIO_PIN_OUTPUT);

	DIO_setPinValue(H_A2_PORT,H_A2_PIN,DIO_PIN_LOW);
	TMR1_setDutyCycle(num);
	break;
	}
	case 2:
	{
	//ANTI CLCWISE

		DIO_setPinDirection(H_A1_PORT,H_A1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_A1_PORT,H_A1_PIN,DIO_PIN_LOW);
	TMR1_setDutyCycle(num);
	break;
	}
	}
	break;
}
case 'B':
{
	//motorB


	switch(direction)
	{
	case 1:
	{
	//CLCWISE


		DIO_setPinDirection(H_A4_PORT,H_A4_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_A4_PORT,H_A4_PIN,DIO_PIN_LOW);
	TMR1_setDutyCycle(num);
	break;
	}
	case 2:
	{
	//ANTI CLCWISE


		 DIO_setPinDirection(H_A3_PORT,H_A3_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_A3_PORT,H_A3_PIN,DIO_PIN_LOW);
	TMR1_setDutyCycle(num);
	break;
	}
	}
break;
}
}
}

/*
void L9110_DCMOTOR_start(u8 direction,u8 motor)
{
	switch(motor)
	{
	case 'A':
	{
		//motorA

		DIO_setPinDirection(A_1A_PORT,A_1A_PIN,DIO_PIN_OUTPUT);
		DIO_setPinDirection(A_2A_PORT,A_2A_PIN,DIO_PIN_OUTPUT);
		switch(direction)
		{
		case 1:
		{
		//CLCWISE
		DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_HIGH);
		DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_LOW);
		break;
		}
		case 2:
		{
		//ANTI CLCWISE
		DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_LOW);
		DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_HIGH);
		break;
		}
		}
		break;
	}
	case 'B':
	{
		//motorB


	    DIO_setPinDirection(B_1A_PORT,B_1A_PIN,DIO_PIN_OUTPUT);
		DIO_setPinDirection(B_2A_PORT,B_2A_PIN,DIO_PIN_OUTPUT);
		switch(direction)
		{
		case 1:
		{
		//CLCWISE
		DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_HIGH);
		DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_LOW);
	    break;
		}
		case 2:
		{
		//ANTI CLCWISE
		DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_LOW);
		DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_HIGH);
		break;
		}
		}


	break;

	}

	}
}
void L9110_DCMOTOR_stop(u8 motor)
{
switch(motor)
{
case 'A':
{
	DIO_setPinDirection(A_1A_PORT,A_1A_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(A_2A_PORT,A_2A_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_LOW);
	DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_LOW);
	break;
}
case 'B':
{   DIO_setPinDirection(B_1A_PORT,B_1A_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(B_2A_PORT,B_2A_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_LOW);
	DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_LOW);

	break;
}


}

}
void L9110_DCMOTOR_speed(u8 motor,u8 num,u8 direction)
{
	TMR0_init();
			TMR0_start();
			DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

	switch(motor)
	{

	case 'A':
	{

		switch(direction)
		{
		case 1:
		{
		//CLCWISE

		DIO_setPinDirection(A_2A_PORT,A_2A_PIN,DIO_PIN_OUTPUT);
		TMR0_setDutyCycle(num);
		DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_LOW);
		break;
		}
		case 2:
		{
		//ANTI CLCWISE

			DIO_setPinDirection(A_1A_PORT,A_1A_PIN,DIO_PIN_OUTPUT);
		DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_LOW);
		TMR0_setDutyCycle(num);
		break;
		}
		}

		break;
	}
	case 'B':
	{
		//motorB


		switch(direction)
		{
		case 1:
		{
		//CLCWISE

			TMR0_setDutyCycle(num);
			DIO_setPinDirection(B_2A_PORT,B_2A_PIN,DIO_PIN_OUTPUT);
		DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_LOW);
	    break;
		}
		case 2:
		{
		//ANTI CLCWISE

			TMR0_setDutyCycle(num);
			 DIO_setPinDirection(B_1A_PORT,B_1A_PIN,DIO_PIN_OUTPUT);
		DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_LOW);

		break;
		}
		}

	break;

	}
	}

}

void DCMOTOR_start(u8 direction)
{
	//motor a l293d
	DIO_setPinDirection(H_EN1_PORT,H_EN1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_EN1_PORT,H_EN1_PIN,DIO_PIN_HIGH);
	DIO_setPinDirection(H_A1_PORT,H_A1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(H_A2_PORT,H_A2_PIN,DIO_PIN_OUTPUT);
	//motor b l293d
	DIO_setPinDirection(H_EN2_PORT,H_EN2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinValue(H_EN2_PORT,H_EN2_PIN,DIO_PIN_HIGH);
	DIO_setPinDirection(H_A3_PORT,H_A3_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(H_A4_PORT,H_A4_PIN,DIO_PIN_OUTPUT);
	//motor a l9110
	DIO_setPinDirection(A_1A_PORT,A_1A_PIN,DIO_PIN_OUTPUT);
			DIO_setPinDirection(A_2A_PORT,A_2A_PIN,DIO_PIN_OUTPUT);
	//motor b l9110
			 DIO_setPinDirection(B_1A_PORT,B_1A_PIN,DIO_PIN_OUTPUT);
					DIO_setPinDirection(B_2A_PORT,B_2A_PIN,DIO_PIN_OUTPUT);
switch(direction)
{
case 1:
{//motor a l293d
	DIO_setPinValue(H_A1_PORT,H_A1_PIN,DIO_PIN_HIGH);
		DIO_setPinValue(H_A2_PORT,H_A2_PIN,DIO_PIN_LOW);
		//motor b l293d
		DIO_setPinValue(H_A3_PORT,H_A3_PIN,DIO_PIN_HIGH);
		DIO_setPinValue(H_A4_PORT,H_A4_PIN,DIO_PIN_LOW);
		//motor a l9110
		DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_HIGH);
				DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_LOW);
		//motor b l9110
				DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_HIGH);
					DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_LOW);

	break;
}
case 2:
{//motor a l293d
	DIO_setPinValue(H_A1_PORT,H_A1_PIN,DIO_PIN_LOW);
		DIO_setPinValue(H_A2_PORT,H_A2_PIN,DIO_PIN_HIGH);
	//motor b l293d
		DIO_setPinValue(H_A3_PORT,H_A3_PIN,DIO_PIN_LOW);
			DIO_setPinValue(H_A4_PORT,H_A4_PIN,DIO_PIN_HIGH);
	//motor a l9110
			DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_LOW);
					DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_HIGH);
	//motor b l9110
					DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_LOW);
						DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_HIGH);
	break;
}










}





}
void DCMOTOR_stop(void)
{
//l293d b
	DIO_setPinDirection(H_EN2_PORT,H_EN2_PIN,DIO_PIN_OUTPUT);
		DIO_setPinValue(H_EN2_PORT,H_EN2_PIN,DIO_PIN_LOW);
	//l293d a
		DIO_setPinDirection(H_EN1_PORT,H_EN1_PIN,DIO_PIN_OUTPUT);
			DIO_setPinValue(H_EN1_PORT,H_EN1_PIN,DIO_PIN_LOW);
	//l9110 a
			DIO_setPinDirection(A_1A_PORT,A_1A_PIN,DIO_PIN_OUTPUT);
				DIO_setPinDirection(A_2A_PORT,A_2A_PIN,DIO_PIN_OUTPUT);
				DIO_setPinValue(A_1A_PORT,A_1A_PIN,DIO_PIN_LOW);
				DIO_setPinValue(A_2A_PORT,A_2A_PIN,DIO_PIN_LOW);
	//l9110 b
				  DIO_setPinDirection(B_1A_PORT,B_1A_PIN,DIO_PIN_OUTPUT);
					DIO_setPinDirection(B_2A_PORT,B_2A_PIN,DIO_PIN_OUTPUT);
					DIO_setPinValue(B_1A_PORT,B_1A_PIN,DIO_PIN_LOW);
					DIO_setPinValue(B_2A_PORT,B_2A_PIN,DIO_PIN_LOW);
}
void DCMOTOR_right(void)
{
	L9110_DCMOTOR_start(1,'A');
	L9110_DCMOTOR_start(1,'B');
	_delay_ms(2000);
	DCMOTOR_stop();
//	L9110_DCMOTOR_start(2,'A');
  // L9110_DCMOTOR_start(2,'B');

	//L293D_DCMOTOR_start(forward,'A');
//	L293D_DCMOTOR_start(2,'B');
	//L293D_DCMOTOR_start(forward,'A');
	//L293D_DCMOTOR_start(2,'B');

}
void DCMOTOR_left(void)
{
//	L293D_DCMOTOR_start(1,'A');
//	L293D_DCMOTOR_start(2,'B');

	//L9110_DCMOTOR_start(forward,'A');
	//L9110_DCMOTOR_start(forward,'B');


	L9110_DCMOTOR_start(2,'A');
	L9110_DCMOTOR_start(2,'B');
	_delay_ms(2000);
	DCMOTOR_stop();
}
*/
