#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
	USARTInit(51);
	InitLCD(0);
	char data;
	DDRB=0xFF;
	LCDWriteStringXY(0,0,"LABVIEW GUI");
	LCDWriteStringXY(0,1,"With PROTEUS");
	_delay_ms(1000);
	LCDClear();
	LCDWriteStringXY(0,0,"waiting--------");
	while(1)
	{
	data= USARTReadChar();
	if(data=='W')
	   {
	    LCDClear();
	 	PORTB=0b00001010;
		LCDWriteStringXY(0,0,"FORWARD");
		//USARTWriteChar('a');
    	}
	else if(data=='Z')
	   {
	    LCDClear();
	 	PORTB=0b00000101;
		LCDWriteStringXY(0,0,"REVERSE");
		//USARTWriteChar('b');
    	}
	else if(data=='X')
	   {
	    LCDClear();
	 	PORTB=0b00000010;
		LCDWriteStringXY(0,0,"RIGHT");
		//USARTWriteChar('c');
		}

	else if(data=='Y')
	   {
	    LCDClear();
	 	PORTB=0b00001000;
		LCDWriteStringXY(0,0,"LEFT");
		//USARTWriteChar('d');
		}
	else if(data=='E') 
	   {
	    LCDClear();
	    PORTB=0b00000000;
		LCDWriteStringXY(0,0,"STOP");
    	//USARTWriteChar('e');
    	}
	}
	}
