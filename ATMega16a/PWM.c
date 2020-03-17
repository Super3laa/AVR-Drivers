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
		//PWM Timer0 one channel
		TCNT0 = 0x00;
		setBit(DDRB,3);
		break;
	case 1 :
		//PWM Timer1 channel A
		TCNT1 = 0x00;
		setBit(DDRD,5);
		break;
	case 2 :
		TCNT1 = 0x00;
		setBit(DDRD,4);
		break;
	case 3 :
		TCNT2 = 0x00;
		setBit(DDRD,7);
	}
	
}
void PWMStart(uint8_t channel){
	switch (channel)
	{
	case 0 :
	//starting fast PWM for timer0 No preScalling
		setBit(TCCR0,CS00);setBit(TCCR0,COM01);setBit(TCCR0,WGM00);
		break;
	case 1 :
	//starting fast PWM for timer1A No preScalling
		setBit(TCCR1B,CS10);setBit(TCCR1A,COM1A1);setBit(TCCR1A,WGM10);
		break;
	case 2 :
		setBit(TCCR1B,CS10);setBit(TCCR1A,COM1B1);setBit(TCCR1A,WGM10);
		break;
	case 3 :
		setBit(TCCR2,CS20);setBit(TCCR2,COM21);setBit(TCCR2,WGM20);
		break;
	}
}
void PWMWrite(uint8_t channel,uint8_t dutyCycle){
	switch(channel){
		case 0 :
			OCR0 = dutyCycle;
			break;
		case 1 :
			OCR1A = dutyCycle;
			break;
		case 2 :
			OCR1B = dutyCycle;
			break;
		case 3 :
			OCR2 = dutyCycle;
	}
}

void PWMStop(uint8_t channel){
	switch (channel)
	{
	case 0 :
		clearBit(TCCR0,COM01);
		clearBit(TCCR0,WGM00);
		clearBit(TCCR0,CS00);
		break;
	case 1 :
		clearBit(TCCR1B,CS10);
		clearBit(TCCR1A,COM1A1);
		clearBit(TCCR1A,WGM10);
		break;
	case 2 :
		clearBit(TCCR1B,CS10);
		clearBit(TCCR1A,COM1B1);
		clearBit(TCCR1A,WGM10);
		break;
	case 3:
		clearBit(TCCR2,COM21);
		clearBit(TCCR2,WGM20);
		clearBit(TCCR2,COM21);
	}
}