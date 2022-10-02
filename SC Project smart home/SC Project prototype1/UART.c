/*
 * UART.c
 *
 * Created: 30/09/2022 9:40:28 PM
 *  Author: Administrator
 */ 
#include "UART.h"


void UART_INIT(unsigned long baudRate)
{
	UART_DDR |=  (1<<TXD);
	UART_DDR &= ~(1<<RXD);
	UCSRB |= (1<<TXEN)|(1<<RXEN);
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	baudRate = BAUD_CLC(baudRate);
	UBRRL = baudRate;
	UBRRH = (baudRate >> 8);
}

char isAvailable(){
	return (UCSRA & (1 << RXC));
}

unsigned char UART_readonce()
{
	if(isAvailable())
	{
		while (!(UCSRA & (1<<RXC)));
		return UDR;
	}
}

void UART_sendChar(unsigned char charcater)
{
	while(!(UCSRA & (1<< UDRE)));
	UDR=charcater;
}

void UART_sendString(char * str)
{
	for(int i=0; i < strlen(str); i++)
	{
		UART_sendChar(str[i]);
	}
}

void UART_sendint(int num) {
	char s[17];
	itoa(num, s, 10);
	UART_sendString(s);
}