
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "bitAssign.h"
#include <avr/io.h>

#define keypadPort PORTA
#define keypadDirection DDRA
#define keypadPin PINA

unsigned char key,t;
unsigned char findKey(void);
void initKeyPad(void);
#endif
