/*
 * UART.h
 *
 * Created: 30/09/2022 9:40:44 PM
 *  Author: Administrator
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#define BAUD_CLC(BAUD_RATE) (((F_CPU /(BAUD_RATE *16)))-1)
#define RXD PD0
#define TXD PD1
#define UART_DDR DDRD
#define UART_PORT PORTD


#ifndef UART_H_
#define UART_H_

void UART_INIT(unsigned long baudRate);
unsigned char UART_readonce();
unsigned char UART_readonce();
void UART_sendChar(unsigned char charcater);
void UART_sendString(char * str);
void UART_sendint(int num);

#endif /* UART_H_ */


