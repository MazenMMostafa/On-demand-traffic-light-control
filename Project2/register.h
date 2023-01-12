/*
 * register.h
 * On Demand traffic light control
 * Created: 12/29/2022 2:08:32 PM
 *  Author: Mazen
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
#include <math.h>

#include "Type.h"
/************************************************************************/
/* PORTS Register                                                       */
/************************************************************************/
/*PORT A*/
#define PORTA *((volatile uint8_t*) 0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
/*PORT B*/
#define PORTB *((volatile uint8_t*) 0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)
/*PORT C*/
#define PORTC *((volatile uint8_t*) 0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)
/*PORT D*/
#define PORTD *((volatile uint8_t*) 0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

/************************************************************************/
/*Timer register                                                        */
/************************************************************************/
// controls the operation of the timer/counter 0 module
#define TCCR0 *((volatile uint8_t*) 0x53)

// holds the current value of the timer/counter 0 module
#define TCNT0 *((volatile uint8_t*)0x52)

// contains the timer interrupt flag bits
#define TIFR *((volatile uint8_t*)0x58)

// contains the timer interrupt mask bits
#define TIMSK *((volatile uint8_t*)0x59)

// holds the output compare value for the timer/counter 0 module
#define OCR0 *((volatile uint8_t*)0x5C)

//#define NUMBER_OF_OVERFLOW 2000

/************************************************************************/
/* Interrupt Register                                                   */
/************************************************************************/
/*
#define IEN() // Enable interrupt
#define IDS() // Disable interrupt
# define IEN()  __asm__ __volatile__ ("IEN" ::: "memory")
# define IDS()  __asm__ __volatile__ ("IDS" ::: "memory")
#define MCUCR *((volatile uint8_t*) 0x55)
#define GICR *((volatile uint8_t*) 0x5B)
#define GIFR *((volatile uint8_t*) 0x5A)


MCUCR 0x55
GICR 0x5B
GIFR 0x5A
*/
#endif /*REGISTER_H_ */