/*
 * Test.c
 * On Demand traffic light control
 * Created: 1/4/2023 10:19:36 AM
 *  Author: Mazen
 */ 
#include "test.h"
void test(void){
	// Testing Leds Driver using Avr library
	//DDRC |= 0b00000001;        //set only 0th pin of port c as output
	//PORTC |= 0b00000001;       //make it high.
	// Testing Leds Driver using DIO library
	
	//led_init(0,PORT_C);  // initializing led pin as output
	//led_on(0,PORT_C);    // turn on the led
	
	
	//Testing push button driver using DIO library
	/*
	uint8_t x; // holds push button value
	led_init(0,PORT_C);  // initializing led pin as output
	pb_init(2,PORT_D);	//initializing push button pin as input
	pb_read(2,PORT_D,&x);	// reading push button value
	if(x==1){		// button is pressed then led on
		led_on(0,PORT_C);  // turn on the led
	}
	else	// when releasing button led is off
	led_off(0,PORT_C);// turn off the led
	*/
	
	/*
	// TESTING Delay library 2 Seconds
	led_init(0,PORT_C);  // initializing led pin as output
	led_on(0,PORT_C);    // turn on the led
	timer(2,s);			//Delay 2 seconds
	led_off(0,PORT_C);  // turn off the led
	timer(2,s);
	*/
	/*
	// TESTING Delay library 2 Mili Seconds
	led_on(0,PORT_C);    // turn on the led
	timer(150,ms);		//Delay 2 mili seconds
	led_off(0,PORT_C);  // turn off the led
	timer(150,ms);
	*/

	/*
	// TESTING Delay library 2 Micro Seconds
	led_on(0,PORT_C);    // turn on the led
	timer(90000,us);		//Delay 2 micro seconds
	led_off(0,PORT_C);  // turn off the led
	timer(90000,us);	
	*/
}