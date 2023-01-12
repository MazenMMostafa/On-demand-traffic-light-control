/*
 * pb.c
 * On Demand traffic light control
 * Created: 12/30/2022 4:00:53 PM
 *  Author: Mazen
 */ 
#include "pb.h"
void pb_init(uint8_t pinNumber,uint8_t portNumber)
{
	DIO_init(pinNumber,portNumber,IN);
}
void pb_read(uint8_t pinNumber,uint8_t portNumber,uint8_t *value)
{
	DIO_read(pinNumber,portNumber,value);
}
