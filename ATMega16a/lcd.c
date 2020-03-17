  // Alaa Essam
#include "lcd.h"

void lcdCommand ( unsigned char command ){
  //sending the upper 4-bits
    lcdPort = (lcdPort & 0x0F) | (command & 0xF0);
    clearBit(lcdPort,RS); //0 for  command

    setBit(lcdPort,EN);
     _delay_us(1);
    clearBit(lcdPort, EN);
    _delay_us(200);
   //sending the lower 4-bits
    lcdPort = (lcdPort & 0x0F) |  (command << 4);

    setBit(lcdPort,EN);
     _delay_us(1);
    clearBit(lcdPort,EN);
    _delay_ms(2);

}

void lcdChar (char c){
  lcdPort = (lcdPort & 0x0F) | (c & 0xF0);
  setBit(lcdPort,RS); // 1 for data

  setBit(lcdPort,EN);
   _delay_us(1);
  clearBit(lcdPort, EN);
  _delay_us(200);
 //sending the lower 4-bits
  lcdPort = (lcdPort & 0x0F) | (c << 4);

  setBit(lcdPort,EN);
   _delay_us(1);
  clearBit(lcdPort,EN);
  _delay_ms(2);

}

void lcdString (char *str){
  int k;
  for (k = 0 ; str[k]!= 0 ; k++){
    lcdChar(str[k]);
  }
}

void lcdClear(){
  //cleaning screen
  lcdCommand(0x01);
  _delay_ms(20);
  //setting cursor to initial position
  lcdCommand(0x80);

}
void lcdInit(void){
  lcdDirection = 0xFF;
  _delay_ms(20);
  lcdCommand(0x02);//4-bit
  lcdCommand(0x28);//2 line 15*7 matrix
  lcdCommand(0x06);//auto inc
  lcdCommand(0x0c);
  lcdCommand(0x01);//clear Display
  _delay_ms(500);
  lcdString("Welcome Back");
  lcdCommand(0xC0);
  lcdString("Mr.Alaa");

}
void lcdXYChar (char row, char pos, char str){
	if (row == 0 && pos<16)
	lcdCommand((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	lcdCommand((pos & 0x0F)|0xC0);
	lcdChar(str);
}
void lcdXYString (char row, char pos, char *str){
	if (row == 0 && pos<16)
	lcdCommand((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	lcdCommand((pos & 0x0F)|0xC0);
	lcdChar(str);
}
void lcdSetXY(char row, char pos){
  if (row == 0 && pos<16)
  lcdCommand((pos & 0x0F)|0x80);
  else if (row == 1 && pos<16)
  lcdCommand((pos & 0x0F)|0xC0);
}

void lcdCustomChar(unsigned char loc , unsigned char *msg){
  unsigned char i;
	if(loc<8)
	{
		lcdCommand (0x40 + (loc*8));
		_delay_ms(10);
		for(i=0;i<8;i++){
		  lcdChar(msg[i]);
		}
	}
}
