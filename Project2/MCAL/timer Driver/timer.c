/*
 * timer.c
 * On Demand traffic light control
 * Created: 12/31/2022 9:21:52 PM
 *  Author: Mazen
 */
#include "timer.h"
void timer(float T,uint8_t typ){
	TCCR0 =0x00;
	TCNT0 =0x00;
	TIFR= 0x00;
	float t0=0;	
	uint16_t ovfc=0;
	TCCR0 |=(1<<0);
	switch(typ){
		case 'm':
		t0=T/ 1000;
		//led_on(1,PORT_A);
		break;
		case 'u':
		t0=T/1000000;
		//led_on(2,PORT_A);
		break;
		case 's':
		t0=T/1;
		//led_on(3,PORT_A);
		break;
		default:
		break;
	}
	// calculate how many seconds for delay counting overflows	
	float ovc=ceil(t0/0.000256);
	TCCR0 |=(1<<0);

	while(ovfc<ovc){
		while((TIFR &(1<<0))==0);

		//clear overflow flag
		TIFR |= (1<<0);
		ovfc++;
	}
	TCCR0=0x00;
	ovfc=0;
}