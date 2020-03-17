/*
 * I2c.c
 *  Author: Alaa Essam
 */ 
#include "I2c.h"

void I2cInit(void){
	TWBR = BITRATE(TWSR=0x00);
}
void I2cStart(uint8_t address){
	TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while( !(TWCR & (1<<TWINT)) );
	TWDR =  address;
	TWCR=(1<<TWEN)|(1<<TWINT);
	while(!(TWCR&(1<<TWINT)));
}
void I2cWrite(uint8_t data ){
	TWDR = data;
	//Transmitting data 
	TWCR = (1<<TWINT) | (1<<TWEN);
	//wait for transmission
	while( !(TWCR & (1<<TWINT)) );
}
uint8_t I2cRead(void){
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}
void I2cStop(void){
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);/* Enable TWI, generate stop */
	while(TWCR&(1<<TWSTO));
}

void I2cSlaveInit(uint8_t address){
	TWAR = address<<1;
	TWCR = (1<<TWEA) | (1<<TWINT) | (1<<TWEN);
}
uint8_t I2cSlaveRead(void){
	TWCR |= (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI & generation of ack */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	return TWDR;
}