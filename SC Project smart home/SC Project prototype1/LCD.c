/*
 * LCD.c
 *
 * Created: 9/12/2022 9:09:03 AM
 *  Author: BLU-RAY
 */ 
#include "LCD.h"

void LCD_cmd(unsigned char cmnd)
{
	LCD_PORT =(cmnd & 0xF0) | (LCD_PORT & 0x0F);
	LCD_PORT &= ~(1 << RS); // Clear RS bit
	LCD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_PORT &= ~(1 << EN);
	
	_delay_ms(10);
	
	LCD_PORT = (cmnd << 4) | (LCD_PORT & 0x0F);
	LCD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_PORT &= ~(1 << EN);
}

void LCD_sendchar(unsigned char data)
{
	LCD_PORT =(data & 0xF0) | (LCD_PORT & 0x0F);
	LCD_PORT |= (1 << RS); // Clear RS bit
	LCD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_PORT &= ~(1 << EN);
	
	_delay_ms(10);
	
	LCD_PORT = (data << 4) | (LCD_PORT & 0x0F);
	LCD_PORT |= (1 << EN);
	_delay_ms(1);
	LCD_PORT &= ~(1 << EN);
}

void LCD_init()
{
	LCD_DDR = 0xFF;
	
	_delay_ms(20);
	LCD_cmd(0x02);
	LCD_cmd(0x28);
	LCD_cmd(0x0E);
	LCD_cmd(0x06);
	LCD_cmd(0x01);
	
	_delay_ms(2);
}

void LCD_sendstring(char * str)
{
	for (int i = 0 ; i < strlen(str); i++)
	{
		LCD_sendchar(str[i]);
	}
}

void LCD_send_int(int num) {
	char s[17];
	itoa(num, s, 10);
	LCD_sendstring(s);
}