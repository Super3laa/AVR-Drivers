/*
 * PWM.h
 *
 * Created: 3/17/2020 6:33:47 PM
 *  Author: Alaa Essam
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include "bitAssign.h"
void PWMInit(uint8_t channel);
void PWMStart(uint8_t channel);
void PWMStop(uint8_t channel);
void PWMWrite(uint8_t channel,uint8_t dutyCycle);


#endif /* PWM_H_ */