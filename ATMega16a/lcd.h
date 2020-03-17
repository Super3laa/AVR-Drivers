/*
  Alaa Essam
*/
#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL

#include "bitAssign.h"
#include <avr/io.h>
#include <util/delay.h>


#define RS  0 // Register Select
#define EN  1 //Enable signal pin

#define lcdPort PORTB
#define lcdDirection DDRB

void lcdInit(void);
void lcdClear();
void lcdString (char *str);
void lcdChar (char c);
void lcdCommand ( unsigned char command );
void lcdXYChar (char row, char pos, char str);
void lcdXYString (char row, char pos, char *str);
void lcdSetXY(char row, char pos);
void lcdCustomChar(unsigned char loc , unsigned char *msg);

#endif
