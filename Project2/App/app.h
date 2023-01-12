/*
 * app.h
 * On Demand traffic light control
 * Created: 12/30/2022 3:11:05 PM
 *  Author: Mazen
 */ 


#ifndef APP_H_
#define APP_H_
// leds library
#include "../MCUAL/Led Driver/led.h"
// push button library
#include "../MCUAL/Button Driver/pb.h"
// timer library
#include "../MCAL/Timer Driver/timer.h"
// interrupt library
#include "../MCAL/interrupt/INT.h"
void app_start(void);
void normalmod(void);
void pedemod(void);


#endif /* APP_H_ */