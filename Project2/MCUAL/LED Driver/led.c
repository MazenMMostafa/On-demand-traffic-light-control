/*
 * led.c
 * On Demand traffic light control
 * Created: 12/30/2022 3:14:41 PM
 *  Author: Mazen
 */ 
#include "led.h"
#include "../../MCAL/timer Driver/timer.h"

// Initializes a LED connected to the specified pin and port
void led_init(uint8_t pinNumber, uint8_t portNumber)
{
	// Initialize the specified pin as an output
	DIO_init(pinNumber, portNumber, OUT);
}

// Turns on a LED connected to the specified pin and port
void led_on(uint8_t pinNumber, uint8_t portNumber)
{
	// Set the specified pin to HIGH (turn on the LED)
	DIO_write(pinNumber, portNumber, HIGH);
}

// Turns off a LED connected to the specified pin and port
void led_off(uint8_t pinNumber, uint8_t portNumber)
{
	// Set the specified pin to LOW (turn off the LED)
	DIO_write(pinNumber, portNumber, LOW);
}

// Makes a LED connected to the specified pin and port blink
void led_blink(uint8_t pinNumber, uint8_t portNumber)
{
	// Turn on the LED
	led_on(pinNumber, portNumber);

	// Wait for 500 milliseconds
	timer(500, ms);

	// Turn off the LED
	led_off(pinNumber, portNumber);

	// Wait for 500 milliseconds
	timer(500, ms);
}
