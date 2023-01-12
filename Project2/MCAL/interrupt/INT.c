/*
 * INT.c
 * On Demand traffic light control
 * Created: 1/1/2023 9:17:42 PM
 *  Author: Mazen
 */ 
#include "INT.h"
// Function to configure external interrupt 0 (INT0)
void INT_0(uint8_t lvl){
	
	// Switch on the specified interrupt level
	switch(lvl)
	{
		// If interrupt level is LOW
		case 'L':
		// Enable global interrupts
		sei();
		// Set ISC00 and ISC01 to 0 to trigger interrupt on low level
		MCUCR &= ~((1<<ISC00)|(1<<ISC01));
		// Enable external interrupt 0
		GICR |= (1<<INT0);
		break;
		
		// If interrupt level is ANY
		case 'A':
		// Enable global interrupts
		sei();
		// Set ISC00 and ISC01 to 1 to trigger interrupt on any logical change
		MCUCR |= (1<<ISC00) | (1<<ISC01);
		// Enable external interrupt 0
		GICR |= (1<<INT0);
		break;
		
		// If interrupt level is FALLING
		case 'F':
		// Enable global interrupts
		sei();
		// Set ISC00 to 1 and ISC01 to 0 to trigger interrupt on falling edge
		MCUCR |= (1<<ISC00);
		MCUCR &=~(1<<ISC01);
		// Enable external interrupt 0
		GICR |= (1<<INT0);
		break;
		
		// If interrupt level is RISING
		case 'R':
		// Enable global interrupts
		sei();
		// Set ISC00 to 0 and ISC01 to 1 to trigger interrupt on rising edge
		MCUCR |= (1<<ISC01);
		MCUCR &= ~(1<<ISC00);
		// Enable external interrupt 0
		GICR |= (1<<INT0);
		break;
		
		// If interrupt level is not one of the defined constants
		default:
		break;
	}
}


// Function to configure external interrupt 1 (INT1)
void INT_1(uint8_t lvl){
	
	// Switch on the specified interrupt level
	switch(lvl)
	{
		// If interrupt level is LOW
		case 'L':
		// Enable global interrupts
		sei();
		// Set ISC00 and ISC01 to 0 to trigger interrupt on low level
		MCUCR &= ~((1<<ISC00)|(1<<ISC01));
		// Enable external interrupt 1
		GICR |= (1<<INT1);
		break;
		
		// If interrupt level is ANY
		case 'A':
		// Enable global interrupts
		sei();
		// Set ISC00 and ISC01 to 1 to trigger interrupt on any logical change
		MCUCR |= (1<<ISC00) | (1<<ISC01);
		// Enable external interrupt 1
		GICR |= (1<<INT1);
		break;
		
		// If interrupt level is FALLING
		case 'F':
		// Enable global interrupts
		sei();
		// Set ISC00 to 1 and ISC01 to 0 to trigger interrupt on falling edge
		MCUCR |= (1<<ISC00);
		MCUCR &=~(1<<ISC01);
		// Enable external interrupt 1
		GICR |= (1<<INT1);
		break;
		
		// If interrupt level is RISING
		case 'R':
		// Enable global interrupts
		sei();
		// Set ISC00 to 0 and ISC01 to 1

		MCUCR |= (1<<ISC01);
		MCUCR &= ~(1<<ISC00);
		//  Enable External interrupt 0 - INT0 
		GICR |= (1<<INT1);
		break;
		default:
		break;
	}
}
// Function to configure external interrupt 2 (INT2)
void INT_2(uint8_t lvl){
	
	switch(lvl)
	{
		case 'L':
		sei();
		MCUCR &= ~((1<<ISC00)|(1<<ISC01)); // setting ISC00 and ISC01 to 0
		//  Enable External interrupt 0 - INT0 
		GICR |= (1<<INT2);
		break;
		case 'A':
		sei();
		// enable any logical change  
		MCUCR |= (1<<ISC00) | (1<<ISC01); // setting ISC00 and ISC01 to 1
		//  Enable External interrupt 0 - INT0 
		GICR |= (1<<INT2);
		break;
		case 'F':
		sei();
		MCUCR |= (1<<ISC00); //setting ISC00 to 1
		MCUCR &=~(1<<ISC01); //setting ISC01 to 0
		//  Enable External interrupt 0 - INT0 
		GICR |= (1<<INT2);
		break;
		case 'R':
		sei();
		MCUCR |= (1<<ISC01);
		MCUCR &= ~(1<<ISC00);
		//  Enable External interrupt 0 - INT0 
		GICR |= (1<<INT2);
		break;
		default:
		break;
	}
}