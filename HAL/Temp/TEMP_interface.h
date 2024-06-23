/*
 * TEMP_interface.h
 *
 *  Created on: May 27, 2024
 *      Author: nadia
 */

#ifndef TEMP_INTERFACE_H_
#define TEMP_INTERFACE_H_

static u16 x;
static u32 c;
//init
void LM35_init();

//calculate temp in  c and sends it
void LM35_sendTemp(u32*num);
#endif /* TEMP_INTERFACE_H_ */
