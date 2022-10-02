/*
 * ADC.c
 *
 * Created: 26/09/2022 8:59:38 PM
 *  Author: Administrator
 */ 

#define  F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include "ADC.h"

void adc_init() {
	ADMUX = (1 << REFS0); // The Vref will be from AVCC
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);  // Enable the ADC then prescale the 8Mhz to a number between 50khz and 200khz.
	DDRA &= 0xFE;
}

uint16_t adc_read(char pin) {
	
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F);
	ADCSRA |= (1 << ADSC); // Start read.
	while ((ADCSRA & (1 << ADIF)) == 0); // Wait until finish ADIF not equals 1.
	ADCSRA |= (1 << ADIF); // Reset the ADIF bit by set it to logical one.
	return ADC;
}

int returntemp()
{
	return (adc_read(0)*0.49); //(5/1024)/10 *1000 = 0.49
}

void readtemp()
{
	LCD_cmd(0x01);
	LCD_sendstring("temp:");UART_sendChar(10);UART_sendChar(10);UART_sendString("temp:");
	LCD_send_int (adc_read(0)*0.49);UART_sendint(adc_read(0)*0.49); //(5/1024)/10 *1000 = 0.49
	LCD_sendstring(" C");UART_sendString(" c");
	_delay_ms(100);
}