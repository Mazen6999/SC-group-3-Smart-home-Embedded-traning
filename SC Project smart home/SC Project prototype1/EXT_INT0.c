

#include "EXT_INT0.h"

ISR(INT0_vect)
{
	LCD_cmd(0x01);
	LCD_cmd(0x90);LCD_sendstring("RET(C):");UART_sendChar(10);UART_sendChar(10);UART_sendString("Return(C)");
	LCD_cmd(0xD0);LCD_sendstring("FanSpeed(1-5)?");UART_sendChar(10);UART_sendString("FanSpeed(1-5)?:");
	
	while(1)
	{
		temp_check();
		if(Emergency==1){speed=readKPonce();}else{speed=UART_readonce();}
		if(speed=='C'||speed=='1'||speed=='2'||speed=='3'||speed=='4'||speed=='5'){break;}
	}
		
		 if(speed=='C'){EXT_INT0_disable();return;}
	else if(speed=='1'){set_fan_speed(20);LCD_cmd(0x90);LCD_sendstring("FanSpeed(1-5): 1 ...");UART_sendChar(10);UART_sendString("FanSpeed(1-5): 1 ...");_delay_ms(200);}
	else if(speed=='2'){set_fan_speed(40);LCD_cmd(0x90);LCD_sendstring("FanSpeed(1-5): 2 ...");UART_sendChar(10);UART_sendString("FanSpeed(1-5): 2 ...");_delay_ms(200);}
	else if(speed=='3'){set_fan_speed(60);LCD_cmd(0x90);LCD_sendstring("FanSpeed(1-5): 3 ...");UART_sendChar(10);UART_sendString("FanSpeed(1-5): 3 ...");_delay_ms(200);}
	else if(speed=='4'){set_fan_speed(80);LCD_cmd(0x90);LCD_sendstring("FanSpeed(1-5): 4 ...");UART_sendChar(10);UART_sendString("FanSpeed(1-5): 4 ...");_delay_ms(200);}
	else if(speed=='5'){set_fan_speed(100);LCD_cmd(0x90);LCD_sendstring("FanSpeed(1-5): 5 ...");UART_sendChar(10);UART_sendString("FanSpeed(1-5): 5 ...");_delay_ms(200);}
}

void EXT_INT0_init()
{
	PORTD |= (1<<PD2);
	sei();
	EXT_INT0_DDR &= ~(1 << INT0_PIN);
	GICR |= (1 << INT0);
	MCUCR |= (1 << ISC00);
}

void EXT_INT0_disable()
{
	EXT_INT0_DDR |= (1 << INT0_PIN);
	PORTD &= ~(1<<PD2);
	GICR &= ~(1 << INT0);
	MCUCR &= ~(1 << ISC00);
}