/*
 * Lights.h
 *
 * Created: 25/09/2022 11:45:12 AM
 *  Author: Administrator
 */ 
#include <avr/io.h>
#include "UART.h"
#include "Timer2.h"
#include "LCD.h"
#include "Motor.h"
#include "key_pad.h"
#define Light1 PA7
#define Light2 PA6
#define Light3 PA5
#define Light4 PA4
#define Light5 PA3

#ifndef Lights_H_
#define Lights_H_

void Lights_init();
void Lights_control();
void dimming_lamp_init();
void set_lamp_brightness(int dutyCycle);
char Light;
char Bright_mode;



#endif /* Lights_H_ */