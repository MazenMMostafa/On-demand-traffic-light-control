/*
 * app.c
 *	On Demand traffic light control
 * Created: 12/30/2022 3:10:51 PM
 *  Author: Mazen
 */ 
/*
Leds on port A 0 1 2
Leds on port B 0 1 2
*/

#include "app.h"
// n is used to change between normal and pedestrain modes
// debounce used to block the double or long press on button
uint16_t n=0,debounce=0;
// rv yv gv are red and yellow and green button read values to check them if high or low
uint8_t rv,yv,gv;
void app_start(void){
	for(uint16_t i=0;i<3;i++)
	{
		// initializing PORT A,B 0 to 2 as output for leds
		led_init(i,PORT_A);
		led_init(i,PORT_B);
	}
	// push button initializing for interrupt
	pb_init(PB_INT0_PIN,PB_INT0_PORT);
	// Interrupt enable
	INT_0(LOW_LEVEL);
	while (1)
	{
			if(n==0){
			// reset Pedestrian leds
			led_off(RED,PORT_B);
			led_off(YELLOW,PORT_B);
			led_off(GREEN,PORT_B); 
			normalmod();
			
			}
			else if(n==1){
			pedemod();
			
	}
			
	}
}
// normal mode Red 5s yellow blinks 5s green 5s then yellow blinks 5s
// this mode make Pedestrian off while normal mode running
/*
void normalmod(void){

	led_on(RED,PORT_A); // Red Led on for 5 seconds
	timer(5,s);
	led_off(RED,PORT_A);
	
	for(uint16_t ct=0;ct<5;ct++){
		yelon=1;
		led_blink(YELLOW,PORT_A);	// yellow led blink for 5 seconds
	}
	yelon=0;
	led_off(YELLOW,PORT_A);
	led_on(GREEN,PORT_A);		// green led on for 5 seconds
	geon=1;
	timer(5,s);
	led_off(GREEN,PORT_A);
	geon=0;
	for(uint16_t ct=0;ct<5;ct++){
		yelon=1;
	led_blink(YELLOW,PORT_A);
	}
	yelon=0;
	led_off(YELLOW,PORT_A);
}*/
// this mode make pedestrian running opposite of car 
// Red Led in cars = Green led in pedestrian, Green led in cars = Red led in pedestrian and both yellow blinks together
void normalmod(void){
	// Turn off all LEDs on PORT B
	led_off(RED,PORT_B);
	led_off(YELLOW,PORT_B);
	led_off(GREEN,PORT_B);

	// Turn off all LEDs on PORT A
	led_off(RED,PORT_A);
	led_off(YELLOW,PORT_A);
	led_off(GREEN,PORT_A);

	// Turn on red LED on PORT A and green LED on PORT B
	led_on(RED,PORT_A);   //Cars
	led_on(GREEN,PORT_B); //Pedestrian

	// Wait for 5 seconds
	timer(5,s);

	// Turn off red LED on PORT A and green LED on PORT B
	led_off(RED,PORT_A);   //Cars
	led_off(GREEN,PORT_B); //Pedestrian

	// Flash yellow LEDs on PORT A and PORT B for 5 iterations with a delay of 500ms in between each iteration
	for(uint16_t ct=0;ct<5;ct++){
		yv=1;
		led_on(YELLOW,PORT_A);   //Cars
		led_on(YELLOW,PORT_B); //Pedestrian
		timer(500,ms);
		led_off(YELLOW,PORT_A);   //Cars
		led_off(YELLOW,PORT_B); //Pedestrian
		timer(500,ms);
	}
	yv=0;
	// Turn off yellow LEDs on PORT A and PORT B
	led_off(YELLOW,PORT_A);   //Cars
	led_off(YELLOW,PORT_B); //Pedestrian

	// Turn on green LED on PORT A and red LED on PORT B
	led_on(GREEN,PORT_A);   //Cars
	led_on(RED,PORT_B); //Pedestrian

	// Wait for 5 seconds
	timer(5,s);

	// Turn off green LED on PORT A and red LED on PORT B
	led_off(GREEN,PORT_A);   //Cars
	led_off(RED,PORT_B); //Pedestrian

	// Flash yellow LEDs on PORT A and PORT B for 5 iterations with a delay of 500ms in between each iteration
	for(uint16_t ct=0;ct<5;ct++){
		yv=1;
		led_on(YELLOW,PORT_A);   //Cars
		led_on(YELLOW,PORT_B); //Pedestrian
		timer(500,ms);
		led_off(YELLOW,PORT_A);   //Cars
		led_off(YELLOW,PORT_B); //Pedestrian
		timer(500,ms);
	}
	yv=0;
	// Turn off yellow LEDs on PORT A and PORT B
	led_off(YELLOW,PORT_A);   //Cars
	led_off(YELLOW,PORT_B); //Pedestrian


}

/************************************************************************/
/* pedestrian 2 cases
1- if car red led on then green pedestrian on
then yellow blinks 5s pedestrian and car
then red green on and red pedestrian on									
2- if car yellow blinks or green on
then yellow car and pedestrian yellow blinks for 5s and
car red on and pedestrian green on for 5s								*/
/************************************************************************/
void pedemod(void){
		// Check if the red light is on by checking the value of the `rv` variable.
		if(rv==HIGH){
			
			// If red light is on, turn on red light on PORT_A and green light on PORT_B.
			led_on(RED,PORT_A);   //Cars
			led_on(GREEN,PORT_B); //Pedestrian
			
			// Wait for 5 seconds.
			timer(5,s);
			
			// Turn off green and red lights.
			led_off(GREEN,PORT_B); //Pedestrian
			led_off(RED,PORT_A);   //Cars
			
			// Blink yellow lights on both PORT_A and PORT_B for 5 seconds (500ms on, 500ms off).
			for(uint16_t ct=0;ct<5;ct++){
				yv=1;
				led_on(YELLOW,PORT_A);   //Cars
				led_on(YELLOW,PORT_B); //Pedestrian
				timer(500,ms);
				led_off(YELLOW,PORT_A);   //Cars
				led_off(YELLOW,PORT_B); //Pedestrian
				timer(500,ms);
			}
			yv=0;
			// Turn off yellow lights.
			led_off(YELLOW,PORT_A);   //Cars
			led_off(YELLOW,PORT_B); //Pedestrian
			
			// Turn on green light on PORT_A and red light on PORT_B.
			led_on(GREEN,PORT_A);   //Cars
			led_on(RED,PORT_B); //Pedestrian
			
			// Wait for 5 seconds.
			timer(5,s);
			
			// Turn off green and red lights.
			led_off(GREEN,PORT_A);   //Cars
			led_off(RED,PORT_B); //Pedestrian
			
			// Blink yellow lights on both ports for 5 seconds.
			for(uint16_t ct=0;ct<5;ct++){
				yv=1;
				led_on(YELLOW,PORT_A);   //Cars
				led_on(YELLOW,PORT_B); //Pedestrian
				timer(500,ms);
				led_off(YELLOW,PORT_A);   //Cars
				led_off(YELLOW,PORT_B); //Pedestrian
				timer(500,ms);
			}
			yv=0;
			// Turn off yellow lights.
			led_off(YELLOW,PORT_B); //Pedestrian
			led_off(YELLOW,PORT_A);   //Cars
		}
		// check if Car Yellow or Green Led on
		else if(gv==HIGH || yv==HIGH){
			
		// turn off all LEDS
	for(uint16_t i=0;i<3;i++)
	{
		// initializing PORT A,B 0 to 2 as output for leds
		led_off(i,PORT_A);   //Cars
		led_off(i,PORT_B); //Pedestrian
	}

		// blink car and pedestrian yellow for 5 seconds
		for(uint16_t ct=0;ct<5;ct++){
			yv=1;
			led_on(YELLOW,PORT_A);   //Cars
			led_on(YELLOW,PORT_B); //Pedestrian
			timer(500,ms); // delay for half a second
			led_off(YELLOW,PORT_A);   //Cars
			led_off(YELLOW,PORT_B); //Pedestrian
			timer(500,ms); // delay for half a second
		}
			yv=0;
		// turn off yellow LED on both ports
		led_off(YELLOW,PORT_A);   //Cars
		led_off(YELLOW,PORT_B); //Pedestrian

	
		}
		
			debounce=0;
			n=0;
			app_start();
			
}


ISR(INT0_vect)
{	
	//Reading Car leds values
	DIO_read(RED,PORT_A,&rv);
	//DIO_read(YELLOW,PORT_A,&yv);
	DIO_read(GREEN,PORT_A,&gv);
	
	
	//to avoid double button press or hold
	if(debounce==0 && rv==0){
	if(n<1)
	{
		debounce=1;
		n++;
		app_start();	
	}
	else{
		debounce=1;
		n=0;
		app_start();
	}
	
	}
	}
