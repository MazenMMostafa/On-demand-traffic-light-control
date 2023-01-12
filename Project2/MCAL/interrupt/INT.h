/*
 * INT.h
 * On Demand traffic light control
 * Created: 1/1/2023 9:18:00 PM
 *  Author: Mazen
 */ 


#ifndef INT_H_
#define INT_H_
#include <avr/interrupt.h>

void INT_0(uint8_t lvl);
void INT_1(uint8_t lvl);
void INT_2(uint8_t lvl);

#endif /* INT_H_ */