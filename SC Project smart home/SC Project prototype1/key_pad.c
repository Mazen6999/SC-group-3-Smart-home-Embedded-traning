/*
 * key_pad.c
 *
 * Created: 9/14/2022 9:42:14 AM
 *  Author: BLU-RAY
 */ 
#include "key_pad.h"

unsigned char keypad[4][4] =
{
	{'7','8','9','/'},
	{'4','5','6','x'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};

void keypad_init()
{
	DDRB = 0x0F;
	PORTB = 0xFF;
}



unsigned char readKeypad()
{
	char temp;
	unsigned char val='u';
	while (val == 'u')
	{
		for (int row = 0; row < 4 ; row++)
		{
			PORTB &= ~(1 << row);
			for (int col = 4 ; col < 8 ; col++)
			{
				temp = (PINB >> col) & 0x01;
				if (temp == 0)
				{
						while (temp == 0)
						{
							temp = (PINB >> col) & 0x01;
						}
						val = keypad[row][col - 4];
				}
				
			}
			PORTB |= (1 << row);
		}
	}
	
	return val;
}


unsigned char readKPonce()
{
	char temp;
	unsigned char val='u';
		for (int row = 0; row < 4 ; row++)
		{
			PORTB &= ~(1 << row);
			for (int col = 4 ; col < 8 ; col++)
			{
				temp = (PINB >> col) & 0x01;
				if (temp == 0)
				{
					while (temp == 0)
					{
						temp = (PINB >> col) & 0x01;
					}
					val = keypad[row][col - 4];
				}
				
			}
			PORTB |= (1 << row);
		}
	
	return val;
}