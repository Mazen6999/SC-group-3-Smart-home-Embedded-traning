/*
 * Motor.h
 *
 * Created: 26/09/2022 9:25:56 PM
 *  Author: Administrator
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "UART.h"
#include "Timer2.h"
#include "key_pad.h"
#include "LCD.h"

#define MOTOR_DDR DDRB
#define MOTOR_PORT PORTB
#define INP1 PA1
#define INP3 PA1

#ifndef MOTOR_H_
#define MOTOR_H_

void DC_FAN_temp();
void temp_check();
void temp_check_init();
void DC_FAN_init();
void DC_fan_on();
void DC_fan_off();
void set_fan_speed(int dutyCycle);
void DC_fan_speed();
void ServoDoor_init();
void Servo_angle(unsigned char deg);
void door_control();


char speed;
char Servo_mode;






#endif /* MOTOR_H_ */