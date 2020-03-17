/*
 * uart.h
 *
 * Created: 12/10/2019 9:51:23 PM
 *  Author: Alaa
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

#define BAUDRATE ((16000000UL/(16UL*BAUD)))-1

void SerialInit (long BAUD);

void sendChar (char data);

void sendString (char *data);

char readData(void);

uint8_t Serial_available(void);

void sendInt(int data);



#endif /* UART_H_ */