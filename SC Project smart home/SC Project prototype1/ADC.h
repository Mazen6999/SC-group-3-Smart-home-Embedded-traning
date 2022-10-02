/*
 * ADC.h
 *
 * Created: 26/09/2022 9:01:01 PM
 *  Author: Administrator
 */ 

#define  F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>
#include "LCD.h"
#include "UART.h"

#ifndef ADC_H_
#define ADC_H_

void adc_init();
uint16_t adc_read(char pin);
int returntemp();
void readtemp();

#endif /* ADC_H_ */