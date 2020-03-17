/*
 * ADC.c
 *
 * Created: 12/6/2019 2:02:37 PM
 *  Author: Alaa
 */ 
#include "ADC.h"

void ADCInit(void)
{
	ADMUX = (1<<REFS0);	
	// ADC Enable and prescaler of 8
	// 1000000/8 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);
	 ADMUX=0x00; 
}

uint16_t ReadADC(uint8_t ch)
{
	
	//Select ADC Channel ch must be 0-7
	ch=ch&0b00000111;
	ADMUX|=ch;	
	//Start Single conversion
	ADCSRA|=(1<<ADSC);
	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));
	//Clear ADIF by writing one to it
	ADCSRA|=(1<<ADIF);
	return(ADCW);
}