/*
 * security.h
 *
 * Created: 24/09/2022 9:24:59 PM
 *  Author: Administrator
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "UART.h"
#include "key_pad.h"
#include "Motor.h"
#include <stdlib.h>
#define reset_security PC2
#define Alarm PC3
#define password "1234"
#ifndef SECURITY_H_
#define SECURITY_H_
#define ModeButton PA2

char mode;
char secure;
char BREACH;
char SelectMode;
char interrupt;
void Mode_button_init();
void securitypass();



#endif /* SECURITY_H_ */