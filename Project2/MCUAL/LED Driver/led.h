/*
 * led.h
 * On Demand traffic light control
 * Created: 12/30/2022 3:17:22 PM
 *  Author: Mazen
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO Driver/DIO.h"
void led_init(uint8_t pinNumber,uint8_t portNumber);
void led_on(uint8_t pinNumber,uint8_t portNumber);
void led_off(uint8_t pinNumber,uint8_t portNumber);
void led_toggle(uint8_t pinNumber,uint8_t portNumber);
void led_blink(uint8_t pinNumber,uint8_t portNumber);

#endif /* LED_H_ */