/*
 * Motor.c
 *
 * Created: 26/09/2022 9:26:28 PM
 *  Author: Administrator
 */ 
#include "Motor.h"
void DC_FAN_init()
{
	DDRA |= (1<<PA1);
	PORTA &= ~(1<<PA1);
	speed='1';
}

void temp_check_init()
{
	if(returntemp()>28)
	{
		PORTA |= (1<<INP1);
		set_fan_speed(40);
	}
	else if(returntemp()<21)
	{
		PORTA &= ~(1<<INP1);
	}
}

void temp_check()
{
	if(returntemp()>28)
	{
		PORTA |= (1<<INP1);
	}
	else if(returntemp()<21)
	{
		PORTA &= ~(1<<INP1);
	}
}

void DC_FAN_temp()
{
	if(returntemp()<21)
	{
		DC_fan_off();
	}
	else if(returntemp()>28)
	{
		DC_fan_on();
	}
}

void DC_fan_on()
{
	PORTA |= (1<<INP1);
	DC_fan_speed();
}
void DC_fan_off()
{

	PORTA &= ~(1<<INP1);
}

void set_fan_speed(int dutyCycle)
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


void DC_fan_speed()
{
	PWM_init();
	LCD_cmd(0xd0);
	
		
		 if(OCR2==51) {LCD_cmd(0xc0);LCD_sendstring("FanSpeed:1");UART_sendChar(10);UART_sendString("FanSpeed:1");}
	else if(OCR2==102){LCD_cmd(0xc0);LCD_sendstring("FanSpeed:2");UART_sendChar(10);UART_sendString("FanSpeed:2");}
	else if(OCR2==153){LCD_cmd(0xc0);LCD_sendstring("FanSpeed:3");UART_sendChar(10);UART_sendString("FanSpeed:3");}
	else if(OCR2==204){LCD_cmd(0xc0);LCD_sendstring("FanSpeed:4");UART_sendChar(10);UART_sendString("FanSpeed:4");}
	else if(OCR2==255){LCD_cmd(0xc0);LCD_sendstring("FanSpeed:5");UART_sendChar(10);UART_sendString("FanSpeed:5");}
	_delay_ms(500);
		 if(speed=='C'){return;}		
}

void ServoDoor_init()
{
	DDRD |= (1<<PD4);
	TCCR1B=0x1B;
	TCCR1A=0x23;
	OCR1A=2499;
}

void Servo_angle(unsigned char deg)
{
	OCR1B=(deg - 0) * (250 - 125) / (180 - 0) + 125;
}


void door_control()
{
	temp_check();
	LCD_cmd(0x01); LCD_sendstring("0.Close Door");UART_sendChar(10);UART_sendChar(10);UART_sendChar(10);UART_sendString("0.Close Door");
	LCD_cmd(0xc0); LCD_sendstring("1.Open Door");UART_sendChar(10);UART_sendString("1.Open Door");
	LCD_cmd(0x90); LCD_sendstring("(C to Return)");UART_sendChar(10);UART_sendString("(C to Return):");
	while(1)
	{
		temp_check();
		if(Emergency==1){Servo_mode=readKPonce();}else{Servo_mode=UART_readonce();}
		if(Servo_mode=='C'||Servo_mode=='0'||Servo_mode=='1'){break;}
	}
	if(Servo_mode=='C'){return;}
	
	if(Servo_mode=='0')
	{
		Servo_angle(0);
		LCD_cmd(0x01); LCD_sendstring("Closing");UART_sendChar(10);UART_sendString("Closing the Door");_delay_ms(200);
	}
	if(Servo_mode=='1')
	{
		Servo_angle(90);
		LCD_cmd(0x01); LCD_sendstring("Opening");UART_sendChar(10);UART_sendString("Opening the Door");_delay_ms(200);
	}
	
	
}
