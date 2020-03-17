/*
 * uart.c
 *  Author: Alaa
 */ 
#include "uart.h"

void SerialInit(long BAUD){
	UBRRH = (BAUDRATE>>8);
	UBRRL = BAUDRATE;
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
void sendInt(int data)
{
  unsigned char buf[6];
  sprintf((char *)buf, "%d", data);
  sendString(buf);
}
void sendChar (char data){
	while (!( UCSRA & (1<<UDRE)));
	UDR = data;
}

void sendString (char *data){
	while(*data > 0){
		sendChar(*data++);
	}
	sendChar('\0');
}

char readData(void){
	while ( !(UCSRA & (1 << RXC)) );
	return (UDR);
}

uint8_t Serial_available(void){
	if (UCSRA&(1<<RXC)){
		return 1;
	}else{
		return 0;
	}
}
