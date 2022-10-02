
#include "Lights.h"
																	
																	
																	
void Lights_init()
{
	Bright_mode='h';
	DDRA  |= (1<<Light1)|(1<<Light2)|(1<<Light3)|(1<<Light4)|(1<<Light5);
	PORTA |= (1<<Light1)|(1<<Light2)|(1<<Light3)|(1<<Light4)|(1<<Light5);
}

void dimming_lamp_init()
{
	PWM_init();
}

void set_lamp_brightness(int dutyCycle)
{
	if (dutyCycle >= 0 && dutyCycle <= 100)
	{
		setPWM(dutyCycle/100.0 * 255.0);
	}
	else
	{
		setPWM(0);
	}
}

void Lights_control()
{
	dimming_lamp_init();
	if(Light=='u')
	{
		LCD_cmd(0x01);UART_sendChar(10);
		LCD_cmd(0x80);LCD_sendstring("Lights(ret by C)"); UART_sendChar(10);UART_sendString("Lights(= to refresh)");
		LCD_cmd(0xc0);LCD_sendstring("1:on");LCD_cmd(0xc7);LCD_sendstring("2:on"); UART_sendChar(10);UART_sendString("1:on     2:on");
		LCD_cmd(0x90);LCD_sendstring("3:on");LCD_cmd(0x97);LCD_sendstring("4:on"); UART_sendChar(10);UART_sendString("3:on     4:on");
		LCD_cmd(0xD0);LCD_sendstring("5:on");LCD_cmd(0xD7);LCD_sendstring("6:"); UART_sendChar(10);UART_sendString("5:on     6:");UART_sendChar(10);
	}
	while(1)
	{
		temp_check();
		if(Emergency==1){Light=readKPonce();}else{Light=UART_readonce();}
		if(Light=='1'||Light=='2'||Light=='3'||Light=='4'||Light=='5'||Light=='6'||Light=='7'||Light=='8'||Light=='9'||Light=='0'||Light=='C'||Light=='/'||Light=='x'||Light=='-'||Light=='+'||Light=='='){break;}
	}
		if(Light=='C'){return;}
		if(Light=='0'){PORTA ^= 0xf8;}
		if(Light=='6'){Bright_mode='h';}if(Light=='8'){Bright_mode='l';}
		if(Light=='7'){Bright_mode='m';}if(Light=='9'){Bright_mode='o';}
	
	
	
	LCD_cmd(0x01);
	LCD_cmd(0x80);LCD_sendstring("Lights(ret by C)");UART_sendChar(10);UART_sendString("Lights");
	if(Light=='1'){PORTA ^= (1<<Light1);}
	if(Light=='2'){PORTA ^= (1<<Light2);}
	if(Light=='3'){PORTA ^= (1<<Light3);}
	if(Light=='4'){PORTA ^= (1<<Light4);}
	if(Light=='5'){PORTA ^= (1<<Light5);}
	
	if(PINA & (1<<Light1)){LCD_cmd(0xc0);LCD_sendstring("1:on");UART_sendChar(10);UART_sendString("1:on");}else{LCD_cmd(0xc0);LCD_sendstring("1:off");UART_sendChar(10);UART_sendString("1:off");}
	if(PINA & (1<<Light2)){LCD_cmd(0xc7);LCD_sendstring("2:on");UART_sendString("     2:on");}else{LCD_cmd(0xc7);LCD_sendstring("2:off");UART_sendString("     2:off");}
	if(PINA & (1<<Light3)){LCD_cmd(0x90);LCD_sendstring("3:on");UART_sendChar(10);UART_sendString("3:on");}else{LCD_cmd(0x90);LCD_sendstring("3:off");UART_sendChar(10);UART_sendString("3:off");}
	if(PINA & (1<<Light4)){LCD_cmd(0x97);LCD_sendstring("4:on");UART_sendString("     4:on");}else{LCD_cmd(0x97);LCD_sendstring("4:off");UART_sendString("     4:off");}
	if(PINA & (1<<Light5)){LCD_cmd(0xD0);LCD_sendstring("5:on");UART_sendChar(10);UART_sendString("5:on");}else{LCD_cmd(0xD0);LCD_sendstring("5:off");UART_sendChar(10);UART_sendString("5:off");}
		
		 if(Light=='6' || Bright_mode=='h'){set_lamp_brightness(100);LCD_cmd(0xD7);LCD_sendstring("6:High");UART_sendString("     6:High");UART_sendChar(10);}
	else if(Light=='7' || Bright_mode=='m'){set_lamp_brightness(25);LCD_cmd(0xD7);LCD_sendstring("6:Medium");UART_sendString("     6:Medium");UART_sendChar(10);}
	else if(Light=='8' || Bright_mode=='l'){set_lamp_brightness(5);LCD_cmd(0xD7);LCD_sendstring("6:Low");UART_sendString("     6:Low");UART_sendChar(10);}
	else if(Light=='9' || Bright_mode=='o'){set_lamp_brightness(0);LCD_cmd(0xD7);LCD_sendstring("6:off");UART_sendString("     6:off");UART_sendChar(10);}
}


