/*
 * TIMER1_interface.h
 *
 *  Created on: May 28, 2024
 *      Author: nadia
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TMR1_init(void);
void TMR1_start(void);
void TMR1_stop(void);
void TMR1_setDutyCycle(u8 dutyCyclye);
#endif /* TIMER1_INTERFACE_H_ */
