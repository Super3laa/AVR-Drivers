/*
 * ADC.h
 *
 * Created: 3/17/2020 8:10:46 PM
 *  Author: Alaa Essam
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
void ADCInit(void);
uint16_t ReadADC(uint8_t ch);



#endif /* ADC_H_ */