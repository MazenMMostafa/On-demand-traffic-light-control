/*
 * pb.h
 * On Demand traffic light control
 * Created: 12/30/2022 4:00:39 PM
 *  Author: Mazen
 */ 


#ifndef PB_H_
#define PB_H_

#include "../../MCAL/DIO Driver/DIO.h"
// Interrupt Button to change to pedestrian
#define PB_INT0_PIN 2
#define PB_INT0_PORT PORT_D

void pb_init(uint8_t pinNumber,uint8_t portNumber);
void pb_read(uint8_t pinNumber,uint8_t portNumber,uint8_t *value);

#endif /* PB_H_ */