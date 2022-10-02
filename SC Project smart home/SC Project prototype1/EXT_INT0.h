/*
 * EXT_INT0.h
 *
 * Created: 9/13/2022 6:44:06 PM
 *  Author: BLU-RAY
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD.h"
#include "key_pad.h"
#include "Motor.h"
#define EXT_INT0_DDR DDRD
//#define LED_PIN PD0
#define INT0_PIN PD2
#ifndef EXT_INT0_H_
#define EXT_INT0_H_


void EXT_INT0_init();
void EXT_INT0_disable();


#endif /* EXT_INT0_H_ */