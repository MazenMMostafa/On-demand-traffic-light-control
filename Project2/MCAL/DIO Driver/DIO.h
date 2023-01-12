/*
 * DIO.h
 * On Demand traffic light control
 * Created: 12/29/2022 3:32:47 PM
 *  Author: Mazen
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../register.h"
//PORTS
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//DIRECTION
#define IN 0
#define OUT 1

//VALUE
#define LOW 0
#define HIGH 1

//Interrupt
#define LOW_LEVEL 'L' // Low level interrupt
#define ANY 'A'		// any logical change
#define Rising 'R'	// rising edge
#define Falling 'F'	// falling edge

// LED pins
#define RED 0
#define YELLOW 1
#define GREEN 2
	
void DIO_init(uint8_t pinNumber,uint8_t portNumber ,uint8_t direction);

void DIO_write(uint8_t pinNumber,uint8_t portNumber ,uint8_t direction);

void DIO_toggle(uint8_t pinNumber,uint8_t portNumber);

void DIO_read(uint8_t pinNumber,uint8_t portNumber ,uint8_t *value);




#endif /*DIO_H_*/