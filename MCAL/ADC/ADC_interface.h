/*
 * ADC_interface.c
 *
 *  Created on: Jan 7, 2024
 *      Author: nadia
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*options for single endded channels*/
#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7

/*Options max.voltages*/
 #define ADC_REF_AVCC       0
 #define ADC_REF_AVREF      1
 #define ADC_REF_INTERNAL   2






void ADC_init(u8 refVolt);
void ADC_getDigitalValue(u8 channelId,u16* digitalValue);

#endif /* ADC_INTERFACE_H_ */
