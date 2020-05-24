/*
 * PWM.c
 *
 * Created: 3/17/2020 6:33:29 PM
 *  Author: Alaa Essam
 */ 
#include "PWM.h"

void PWMInit(uint8_t channel){
	switch (channel)
	{
	case 0 :
		//PWM Timer0 one channel   OC0A
		TCNT0 = 0x00;
		setBit(DDRD,6);
		break;
	case 1 :
		//PWM Timer0 one channel     OC0B
		TCNT0 = 0x00;
		setBit(DDRD,5);
		break;
	case 2 :
		//PWM Timer1 channel A       OC1A
		TCNT1 = 0x00;
		setBit(DDRB,1);
		break;
	case 3 :
		TCNT1 = 0x00;     // OC1B
		setBit(DDRB,2);
		break;
	case 4 :
		TCNT2 = 0x00; //// OC2A
		setBit(DDRB,3);
	case 5 :
		TCNT2 = 0x00;
		setBit(DDRD,3);   ////OC2B
	}
	
}
void PWMStart(uint8_t channel){
	switch (channel)
	{
	case 0 :
	//starting fast PWM for timer0 No preScalling
		setBit(TCCR0B,CS00);setBit(TCCR0A,COM0A1);setBit(TCCR0A,WGM00);
		break;
	case 1 :
		//starting fast PWM for timer0 No preScalling
		setBit(TCCR0B,CS00);setBit(TCCR0A,COM0B1);setBit(TCCR0A,WGM00);
		break;
	case 2 :
	//starting fast PWM for timer1A No preScalling
		setBit(TCCR1B,CS10);setBit(TCCR1A,COM1A1);setBit(TCCR1A,WGM10);
		break;
	case 3 :
		setBit(TCCR1B,CS10);setBit(TCCR1A,COM1B1);setBit(TCCR1A,WGM10);
		break;
	case 4 :
		setBit(TCCR2B,CS20);setBit(TCCR2A,COM2A1);setBit(TCCR2A,WGM20);
		break;
	case 5 :
		setBit(TCCR2B,CS20);setBit(TCCR2A,COM2B1);setBit(TCCR2A,WGM20);
		break;
	}
}
void PWMWrite(uint8_t channel,uint8_t dutyCycle){
	switch(channel){
		case 0 :
			OCR0A = dutyCycle;
			break;
		case 1 :
			OCR0B = dutyCycle;
			break;
		case 2 :
			OCR1A = dutyCycle;
			break;
		case 3 :
			OCR1B = dutyCycle;
			break;
		case 4 :
			OCR2A = dutyCycle;
		case 5 :
			OCR2B = dutyCycle;
	}
}

void PWMStop(uint8_t channel){
	switch (channel)
	{
	case 0 :
		clearBit(TCCR0A,COM0A1);
		clearBit(TCCR0A,WGM00);
		clearBit(TCCR0B,CS00);
		break;
	case 1 :
		clearBit(TCCR0A,COM0B1);
		clearBit(TCCR0A,WGM00);
		clearBit(TCCR0B,CS00);
		break;
	case 2 :
		clearBit(TCCR1B,CS10);
		clearBit(TCCR1A,COM1A1);
		clearBit(TCCR1A,WGM10);
		break;
	case 3 :
		clearBit(TCCR1B,CS10);
		clearBit(TCCR1A,COM1B1);
		clearBit(TCCR1A,WGM10);
		break;
	case 4 :
		clearBit(TCCR2A,COM2A1);
		clearBit(TCCR2A,WGM20);
		clearBit(TCCR2B,CS20);
	case 5 :
		clearBit(TCCR2A,COM2B1);
		clearBit(TCCR2A,WGM20);
		clearBit(TCCR2B,CS20);
	}
}