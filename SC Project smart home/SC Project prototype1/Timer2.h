/*
 * Timer2.h
 *
 * Created: 27/09/2022 5:55:59 PM
 *  Author: Administrator
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>
#define OC2 PD7
#define TIMER_DDR DDRD
#define Timer2_PORT PORTD

#ifndef TIMER2_H_
#define TIMER2_H_

void Timer2_init();
void delay_seconds(int delay_val);
void PWM_init();
void setPWM(char dutycycle);




#endif /* TIMER2_H_ */