/*
 * DCMOTOR_interface.h
 *
 *  Created on: Jan 26, 2024
 *      Author: nadia
 */
#include "../../std/STD_TYPES.h"
#include "../../std/BIT_MATH.h"
#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#define forward 1
#define backward 2

void L293D_DCMOTOR_start(u8 direction,u8 motor);
void L293D_DCMOTOR_stop(u8 motor);
void L293D_DCMOTOR_speed(u8 motor,u8 num,u8 direction);

/*
void L9110_DCMOTOR_start(u8 direction,u8 motor);
void L9110_DCMOTOR_stop(u8 motor);
void L9110_DCMOTOR_speed(u8 motor,u8 num,u8 direction);

void DCMOTOR_start(u8 direction);
void DCMOTOR_stop(void);
void DCMOTOR_right(void);
void DCMOTOR_left(void);
*/


#endif /* DCMOTOR_INTERFACE_H_ */
