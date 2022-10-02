/*
 * LCD.h
 *
 * Created: 9/12/2022 9:08:34 AM
 *  Author: BLU-RAY
 */ 
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#define F_CPU 8000000
#include <util/delay.h>
#define RS PC0
#define EN PC1
#define LCD_DDR DDRC
#define LCD_PORT PORTC
#define LCD_PIN  PINC
#ifndef LCD_H_
#define LCD_H_


void LCD_cmd(unsigned char cmnd);
void LCD_sendchar(unsigned char data);
void LCD_sendstring(char * str);
void LCD_init();
void LCD_send_int(int num);




#endif /* LCD_H_ */