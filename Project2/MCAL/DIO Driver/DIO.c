/*
 * DIO.c
 * On Demand traffic light control
 * Created: 12/29/2022 3:33:00 PM
 *  Author: Mazen
 */
#include "DIO.h"

// Initializes a pin on the specified port as an input or output
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	// Select the correct port based on the portNumber argument
	switch(portNumber)
	{
		case PORT_A:
		// Set the specified pin as an input or output
		if(direction == IN)
		{
			// Set the pin as an input
			DDRA &= ~(1 << pinNumber);
		}
		else if(direction == OUT)
		{
			// Set the pin as an output
			DDRA |= (1 << pinNumber);
		}
		else
		{
			// If an invalid direction value is provided, set the pin as an input
			direction = IN;
			DDRA &= ~(1 << pinNumber);
		}
		break; // exit the switch statement
		case PORT_B:
		// Set the specified pin as an input or output
		if(direction == IN)
		{
			// Set the pin as an input
			DDRB &= ~(1 << pinNumber);
		}
		else if(direction == OUT)
		{
			// Set the pin as an output
			DDRB |= (1 << pinNumber);
		}
		else
		{
			// If an invalid direction value is provided, set the pin as an input
			direction = IN;
			DDRB &= ~(1 << pinNumber);
		}
		break; // exit the switch statement
		case PORT_C:
		if(direction==IN)
		{
			// Set the pin as an input
			DDRC &=~(1<<pinNumber);
		}
		else if(direction == OUT)
		{
			// Set the pin as an output
			DDRC |=(1<<pinNumber);
		}
		else
		{
			// If an invalid direction value is provided, set the pin as an input
			direction=IN;
			DDRC &=~(1<<pinNumber);
		}
		break; // exit the switch statement
		case PORT_D:
		if(direction==IN)
		{
			// Set the pin as an input
			DDRD &=~(1<<pinNumber);
		}
		else if(direction == OUT)
		{
			// Set the pin as an output
			DDRD |=(1<<pinNumber);
		}
		else
		{
			// If an invalid direction value is provided, set the pin as an input
			direction=IN;
			DDRD &=~(1<<pinNumber);
		}
		break;
			default:
			break;
			
			
		}
	}

void DIO_write(uint8_t pinNumber,uint8_t portNumber ,uint8_t value)
	{
	// Switch on the specified port
	switch(portNumber)
	{
		// If port is PORT_A
		case PORT_A:
		// If value is LOW, write a 0 to the specified pin on port A
		if(value == LOW)
		{
			PORTA &=~(1<<pinNumber); // WRITE 0 IN DATA
		}
		// If value is HIGH, write a 1 to the specified pin on port A
		else if(value == HIGH)
		{
			PORTA |=(1<<pinNumber); //WRITE 1 IN DATA
		}
		// If value is neither LOW nor HIGH, set value to LOW and write a 0 to the specified pin on port A
		else
		{
			value=LOW;
			PORTA &=~(1<<pinNumber);
		}
		// Exit the switch statement
		break;
		
		// If port is PORT_B
		case PORT_B:
		// If value is LOW, write a 0 to the specified pin on port B
		if(value == LOW)
		{
			PORTB &=~(1<<pinNumber); // WRITE 0 IN DATA
		}
		// If value is HIGH, write a 1 to the specified pin on port B
		else if(value == HIGH)
		{
			PORTB |=(1<<pinNumber);  //WRITE 1 IN DATA
		}
		// If value is neither LOW nor HIGH, set value to LOW and write a 0 to the specified pin on port B
		else
		{
			value=LOW;
			PORTB &=~(1<<pinNumber);
		}
		// Exit the switch statement
		break;
		
		// If port is PORT_C
		case PORT_C:
		// If value is LOW, write a 0 to the specified pin on port C
		if(value == LOW)
		{
			PORTC &=~(1<<pinNumber); // WRITE 0 IN DATA
		}
		// If value is HIGH, write a 1 to the specified pin on port C
		else if(value == HIGH)
		{
			PORTC |=(1<<pinNumber);  //WRITE 1 IN DATA
		}
		// If value is neither LOW nor HIGH, set value to LOW and write a 0 to the specified pin on port C
		else
		{
			value=LOW;
			PORTC &=~(1<<pinNumber);
		}
		// Exit the switch statement
		break;
		
		// If port is PORT_D
		case PORT_D:
		// If value is LOW, write a 0 to the specified pin on port D
		if(value == LOW)
		{
			PORTD &=~(1<<pinNumber); // WRITE 0 IN DATA
		}
		// If value is HIGH, write a 1 to the specified pin on port D
		else if(value == HIGH)
		{
			PORTD |=(1<<pinNumber);  //WRITE 1 IN DATA
		}
		// If value is neither LOW nor HIGH, set value to LOW and write a 0 to the specified pin on port D
		else
		{
			value=LOW;
			PORTD &=~(1<<pinNumber);
		}
		// Exit the switch statement
		break;
		default:
			break;
	}
	}	


// Function to toggle the value of a specified pin on a specified port
void DIO_toggle(uint8_t pinNumber,uint8_t portNumber){
	// Switch on the specified port
	switch(portNumber)
	{
		// If port is PORT_A
		case PORT_A:
		// Toggle the value of the specified pin on port A using XOR
		PORTA ^= (1 << pinNumber);
		break;
		
		// If port is PORT_B
		case PORT_B:
		// Toggle the value of the specified pin on port B using XOR
		PORTB ^= (1 << pinNumber);
		break;
		
		// If port is PORT_C
		case PORT_C:
		// Toggle the value of the specified pin on port C using XOR
		PORTC ^= (1 << pinNumber);
		break;
		
		// If port is PORT_D
		case PORT_D:
		// Toggle the value of the specified pin on port D using XOR
		PORTD ^= (1 << pinNumber);
		break;
		
		// If port is not one of the defined constants
		default:
		// Do nothing
		break;
	}
}

// Function to read the value of a specified pin on a specified port
void DIO_read(uint8_t pinNumber,uint8_t portNumber ,uint8_t *value){
	// Switch on the specified port
	switch(portNumber)
	{
		// If port is PORT_A
		case PORT_A:
		// Read the value of the specified pin on port A and store it in the provided value pointer
		*value = (PINA & (1 << pinNumber))>>pinNumber;
		break;
		
		// If port is PORT_B
		case PORT_B:
		// Read the value of the specified pin on port B and store it in the provided value pointer
		*value = (PINB & (1 << pinNumber))>>pinNumber;
		break;
		
		// If port is PORT_C
		case PORT_C:
		// Read the value of the specified pin on port C and store it in the provided value pointer
		*value = (PINC & (1 << pinNumber))>>pinNumber;
		break;
		
		// If port is PORT_D
		case PORT_D:
		// Read the value of the specified pin on port D and store it in the provided value pointer
		*value = (PIND & (1 << pinNumber))>>pinNumber;
		break;
		
		// If port is not one of the defined constants
		default:
		// Do nothing
		break;

	}
}
