/*
 * DCMOTOR_config.h
 *
 *  Created on: Jan 26, 2024
 *      Author: nadia
 */

#ifndef DCMOTOR_CONFIG_H_
#define DCMOTOR_CONFIG_H_

//H-BRIDGE L293D
#define H_A1_PORT              DIO_PORTB
#define H_A1_PIN               DIO_PIN1

#define H_A2_PORT              DIO_PORTB
#define H_A2_PIN               DIO_PIN4

#define H_A3_PORT              DIO_PORTC
#define H_A3_PIN               DIO_PIN5

#define H_A4_PORT              DIO_PORTC
#define H_A4_PIN               DIO_PIN6

#define H_EN1_PORT             DIO_PORTB
#define H_EN1_PIN              DIO_PIN0

#define H_EN2_PORT             DIO_PORTD
#define H_EN2_PIN              DIO_PIN7

//H-BRIDGE L9110
#define B_1A_PORT             DIO_PORTB
#define B_1A_PIN              DIO_PIN4

#define B_2A_PORT             DIO_PORTB
#define B_2A_PIN              DIO_PIN5

#define A_1A_PORT             DIO_PORTB
#define A_1A_PIN              DIO_PIN6

#define A_2A_PORT             DIO_PORTB
#define A_2A_PIN              DIO_PIN7




#endif /* DCMOTOR_CONFIG_H_ */
