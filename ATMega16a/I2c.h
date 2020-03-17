/*
 * I2c.h
 *
 * Created: 3/16/2020 6:48:40 PM
 *  Author: Alaa Essam
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

#define F_CPU 16000000UL
#define F_SCL 400000UL
#define Prescaler 1

#define BITRATE(TWSR)	(((F_CPU/F_SCL)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))))

void I2cInit(void);
void I2cStop(void);
uint8_t I2cRead(void);
void I2cWrite(uint8_t data );
void I2cStart(uint8_t address);
uint8_t I2cSlaveRead(void);

#endif /* I2C_H_ */