
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include "UART.h"
#include "LCD.h"
#include "key_pad.h"
#include "EXT_INT0.h"
#include "security.h"
#include "ADC.h"
#include "Lights.h"
#include "Motor.h"
#include "EXT_INT0.h"


int main(void)
{
	Mode_button_init();
	DC_FAN_init();
	LCD_init();
	adc_init();
	keypad_init();
	Emergency=0;
	UART_INIT(9600);
	dimming_lamp_init();
	ServoDoor_init();
	Lights_init();
	temp_check_init();
	securitypass();
	
	while (1)
	{
		temp_check();
		if(secure =='T' && SelectMode=='o')
		{
			   LCD_cmd(0x01);LCD_sendstring("LightControl(/):");UART_sendChar(10);UART_sendChar(10);UART_sendString("Light Control");
			   LCD_cmd(0xc0);LCD_sendstring("FanControl(x);");UART_sendChar(10);UART_sendString("Fan Control");
			   LCD_cmd(0x90);LCD_sendstring("DoorControl(-):");UART_sendChar(10);UART_sendString("Door Control");
			   LCD_cmd(0xD0);LCD_sendstring("SecurityMode(+):");UART_sendChar(10);UART_sendString("Security Mode");
			   UART_sendChar(10);UART_sendString("(=) for KP:");
				while(1)
				{
					 temp_check();
					 if(Emergency==1){mode=readKPonce();}else{mode=UART_readonce();}
					 if(mode=='/' && secure =='T') {break;}
					 if(mode=='x' && secure =='T') {break;}
					 if(mode=='-' && secure =='T') {break;}
					 if(mode=='+' && secure =='T') {break;}
					 if(mode=='=' && Emergency==0) {break;}
					 if(mode=='C' && Emergency==1) {break;}
				}
				
			if(mode=='/' && secure =='T'){LCD_cmd(0x01);UART_sendChar(10);UART_sendChar(10);UART_sendString("Light Control");LCD_sendstring("LightControl");_delay_ms(1000);Light = 'u';}
			if(mode=='x' && secure =='T'){LCD_cmd(0x01);UART_sendChar(10);UART_sendChar(10);UART_sendString("Fan Control");LCD_sendstring("FanControl");_delay_ms(1000);EXT_INT0_init();speed='u';}
			if(mode=='-' && secure =='T'){LCD_cmd(0x01);UART_sendChar(10);UART_sendChar(10);UART_sendString("Door Control");LCD_sendstring("DoorControl");_delay_ms(1000);Servo_mode='u';}
			if(mode=='+' && secure =='T'){LCD_cmd(0x01);UART_sendChar(10);UART_sendChar(10);UART_sendString("Security Mode");LCD_sendstring("SecurityMode");_delay_ms(1000);}
			if(mode=='=' && Emergency==0){LCD_cmd(0x01);UART_sendChar(10);UART_sendString("KP On");LCD_sendstring("KP On");_delay_ms(1000);Emergency=1;}
			if(mode=='C' && Emergency==1){LCD_cmd(0x01);UART_sendChar(10);UART_sendChar(10);UART_sendString("Phone On");LCD_sendstring("KP Off");_delay_ms(1000);Emergency=0;}
				
		}
			
		
		
	     if(mode=='/'){while(1){ if(Light=='C')		 {SelectMode='o';break;}   SelectMode='a'; Lights_control();}}
	     if(mode=='x'){while(1){ if(speed=='C')		 {SelectMode='o';EXT_INT0_disable();break;}   SelectMode='a'; readtemp(); DC_FAN_temp();}}
		 if(mode=='-'){while(1){ if(Servo_mode=='C') {SelectMode='o';break;}   SelectMode='a'; door_control();}}
		 if(mode=='+'){if(BREACH=='F'){SelectMode='a';securitypass();}}	//breach 3shan myd5olsh b3d l wrong password
			
	     if((PINC & 0x04) && secure=='F'){securitypass();}
			
		
		
		
	}
}