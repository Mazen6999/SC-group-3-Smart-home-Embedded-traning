/*
 * Timer2.c
 *
 * Created: 27/09/2022 5:56:13 PM
 *  Author: Administrator
 */ 

#include "Timer2.h"

short overflows = 0;

ISR(TIMER2_OVF_vect)
{
	overflows++;
}

void Timer2_init()
{
	TIMER_DDR |= (1 << OC2);
	sei();
	TIMSK |= (1 << TOIE2);
}

void PWM_init()
{
	TIMER_DDR |= (1 << OC2);
	TCCR2 = 0x67;
	TCNT2 = 0;
}

void setPWM(char val)
{
	OCR2 = val;
}

void delay_seconds(int delay_val)
{
	overflows = 0;
	TCNT2 = 0;
	TCCR2 = 0x07;
	float delay_time = 0;
	float timerpertick = 1/(8000000.0/1024.0);
	do
	{
		delay_time = (256.0 * timerpertick * overflows) + TCNT2 * timerpertick;
	} while (delay_time < delay_val);
}