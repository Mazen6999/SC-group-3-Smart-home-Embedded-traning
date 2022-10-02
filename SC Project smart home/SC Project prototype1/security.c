
#include "security.h"

void Mode_button_init()
{
	DDRA |= (1<<PA2);
	PORTA &= ~(1<<PA2);
}
void securitypass()
{
	Servo_angle(0);
	Servo_mode='0';
	PORTC &= ~(1<<Alarm);
	LCD_cmd(0x01);
	LCD_sendstring("Press (=) to use");UART_sendChar(10);UART_sendString("Press (=) to use KP");
	LCD_cmd(0xc0);
	LCD_sendstring("Keypad:");
	LCD_cmd(0x90);
	LCD_sendstring("Enter pin: ");UART_sendChar(10);UART_sendString("Enter PIN:");
	LCD_cmd(0xD0);
	char val[5];
	val[4]='\0';
	for(int i=0;i<4;i++){
							while(1)
							{
									temp_check();
									if(Emergency==1){val[i]=readKPonce();}else{val[i]=UART_readonce();}
									if(val[i]=='1'||val[i]=='2'||val[i]=='3'||val[i]=='4'||val[i]=='5'||val[i]=='6'||val[i]=='7'||val[i]=='8'||val[i]=='9'||val[i]=='0'||val[i]=='C'||val[i]=='/'||val[i]=='x'||val[i]=='-'||val[i]=='+'||val[i]=='='){break;}
							}	
							LCD_sendchar(val[i]);
							if(val[i]=='='){LCD_cmd(0xc0);LCD_sendstring("Keypad:");LCD_sendstring("KP usable");LCD_cmd(0xD0);LCD_sendstring("    ");LCD_cmd(0xD0);Emergency=1;i=-1;;UART_sendChar(10);UART_sendString("Enter PIN using Keypad !");} 
							}
	for(int i=0;i<3;i++)
	{
		if(strcmp(val,password)==0)
		{
			
			LCD_cmd(0x01);
			LCD_sendstring("Correct!");UART_sendChar(10);UART_sendString("Correct, Welcome :) !");
			secure='T';
			BREACH='F';
			SelectMode='o';
			Servo_angle(90);
			Servo_mode='1';
			_delay_ms(1000);
			break;
		}
		else if(i==2)
		{
			
			LCD_cmd(0x01);
			LCD_sendstring("WRONG(3/3)");UART_sendChar(10);UART_sendString("WRONG(3/3)");
			LCD_cmd(0xc0);
			LCD_sendstring("WARNING!");for(int i=0;i<10;i++){ UART_sendChar(10);UART_sendString("!! WARNING !! POSSIBLE BREACH !!"); }
			PORTC |=(1<<Alarm);
			Servo_angle(0);
			Servo_mode='0';
			BREACH='T';
			secure='F';
			SelectMode='c';
			break;
		}
		else
		{
			
			LCD_cmd(0x01);
			LCD_cmd(0x80);
			LCD_sendstring("Wrong,Try again ");UART_sendChar(10);UART_sendString("Wrong, Try again");
			LCD_cmd(0xc0);
			LCD_sendstring("(");UART_sendString("(");
			LCD_send_int(i+1);UART_sendint(i+1);
			LCD_sendstring("/3): ");UART_sendString("/3):");
			
			
			for(int i=0;i<4;i++)
			{
				
				while(1)
				{
					temp_check();
					if(Emergency==1){val[i]=readKPonce();}else{val[i]=UART_readonce();}
					if(val[i]=='1'||val[i]=='2'||val[i]=='3'||val[i]=='4'||val[i]=='5'||val[i]=='6'||val[i]=='7'||val[i]=='8'||val[i]=='9'||val[i]=='0'||val[i]=='C'||val[i]=='/'||val[i]=='x'||val[i]=='-'||val[i]=='+'||val[i]=='='){break;}
				}	
				LCD_sendchar(val[i]);
			}
		}
	}
}