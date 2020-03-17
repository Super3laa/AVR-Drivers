#include "keypad.h"
unsigned char keypad[4][3] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

void initKeyPad(void){
	keypadDirection = 0x0F;
}
unsigned char findKey(void){
   keypadPort |= 0xFF;
	 unsigned char c , r;
   for (r = 0 ; r < 4	 ; r++){
      keypadPort |= 0x0F;
      clearBit(keypadPort, r);
      for (c = 4 ; c <7; c++){
        while (readBit(keypadPin,c) == 0){
					key = keypad[r][c-4];
					if(t != key){
						t=key;
					  	return (key);
					}
        }
      }
    }
		t ='N';
		return 0xFF;
}
