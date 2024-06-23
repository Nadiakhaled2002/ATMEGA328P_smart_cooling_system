/*
 * ADC_program.c
 *
 *  Created on: Jan 7, 2024
 *      Author: nadia
 */
#include "../../STD/STD_TYPES.h"
#include "../../STD/BIT_MATH.h"

#include "ADC_private.h"
#include "ADC_interface.h"



  void ADC_init(u8 refVolt)
  {
	  switch(refVolt)
	  {
	  case ADC_REF_AVCC:
	  {
		  SET_BIT(ADMUX,REFS0);
		  CLR_BIT(ADMUX,REFS1);

		  break;
	  }
	   case ADC_REF_AVREF:
	   {
	    CLR_BIT(ADMUX,REFS0);
	    CLR_BIT(ADMUX,REFS1);

	    break;
	   }
	   case ADC_REF_INTERNAL:
	   {
	    SET_BIT(ADMUX,REFS0);
	    SET_BIT(ADMUX,REFS1);

	    break;
	   }

	  }
	  //SELECT RA
	  CLR_BIT(ADMUX,ADLAR);
	  //SINGLE CONV MODE
	  CLR_BIT(ADCSRA,ADATE);
	  //NO INTERUPT MODE
	  CLR_BIT(ADCSRA,ADIE);
	  //prescaller
       SET_BIT(ADCSRA,ADPS0);
       SET_BIT(ADCSRA,ADPS1);
       SET_BIT(ADCSRA,ADPS2);




	  //LAST THING IS TO ENABLE ADC
	  SET_BIT(ADCSRA,ADEN);

  }
  void ADC_getDigitalValue(u8 channelId,u16* digitalValue)
  {

	  if((channelId<32)&&(digitalValue!=NULL))
	  {
		  //select channel
		  ADMUX = ADMUX & 0xF0;    //0b111100000
		  ADMUX = ADMUX | channelId;

		  //start conversion
		  SET_BIT(ADCSRA,ADSC);

		  //BUSY WAIT FOR FLAG ADIF(BLOCKING)
		  while(0 == GET_BIT(ADCSRA,ADIF));

		  //CLEAR HARDWARE FLAG==1
		  SET_BIT(ADCSRA,ADIF);

		  //read digital value from ADC data REG.
		  *digitalValue=ADC_u16;





	  }



  }
