/*
 * key_pad.h
 *
 * Created: 9/14/2022 9:42:00 AM
 *  Author: BLU-RAY
 */ 

#include <avr/io.h>
#ifndef KEY_PAD_H_
#define KEY_PAD_H_

void keypad_init();
unsigned char readKeypad();
unsigned char readKPonce();


char Emergency;


#endif /* KEY_PAD_H_ */