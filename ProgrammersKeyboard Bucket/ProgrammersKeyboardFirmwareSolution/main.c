//
//Project title:			Programmer's Keyboard
//File name:				main.c
//Content:					The main source code startup file.
//Type:						Document, Firmware source code.
//Author:					Annim Banerjee.
//Project Type:				Major Project 2013.
//compiler used:			sdcc.
//MCU Type:					8051
//MCU IC:					NXP 89V51RD2
//


//headers included here.
#include "stdafx.h"
#include "main.h"
#include "uart_communication_8051.c"
#include "keyboardparse.c"

//declaring global variables here
unsigned char cKeyPressed;

//entry point function code goes here...
void main()
{
	//start uart communication...
	init_uart();
	
	//start keypad...
	StartKeyboard();
	//program loop goes heree...
	while( 1 )		//an infinite loop.
	{
		cKeyPressed = getKeycode();
		if( cKeyPressed > 0 )
		{
			serial_send( TranslatedKeyCodeToAlphabets(cKeyPressed) );
			delayGenericSeconds( 500 );
		}
	}
}


void delayGenericSeconds( int value)
{
	int i,j;
	for(i=0;i<value;i++)
		for(j=0;j<123;j++);
}

