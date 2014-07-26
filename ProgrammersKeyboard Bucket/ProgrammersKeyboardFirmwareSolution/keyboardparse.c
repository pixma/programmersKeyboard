//
//Project title:			Programmer's Keyboard
//File name:				keyboardParse.C
//Content:					definations
//Type:						Document, Firmware source code.
//Author:					Annim Banerjee.
//Project Type:				Major Project 2013.
//compiler used:			sdcc.
//MCU Type:					8051
//MCU IC:					NXP 89V51RD2
//

/*
#define COLUMN1		P2_0
#define COLUMN2		P2_1
#define COLUMN3		P2_2
#define COLUMN4		P2_3
#define COLUMN5		P2_4
#define KEYBOARD	P1

*/

#include "keyboardparse.h"

void StartKeyboard()		//initialize the keyboard by setting the required default settings.
{
	//make rows as o/p and columns as i/p
	//column:	P2
	//row:		P1;KEYBOARD
	P2 &= 0x1f;	//set first 5 bits HIGH; setting col as i/p.
	KEYBOARD &= 0x00;	//set rows as o/p;	
}
unsigned char getKeycode()	//get the key code against the key pressed.
{
	unsigned char chKey=0, cCount, cKeyValue = 1;
	for( cCount = 0; cCount < 5; cCount++)				//loop for 5 rows.
	{
		KEYBOARD &= ~(0x10>>cCount);					//make rows low one by one...
		
		if(!COLUMN1)
		{
			chKey = cKeyValue + 0;						//setting key number. indexed format.
			while(!COLUMN1);							//wait until the key is been released.
			return chKey;
		}
		if(!COLUMN2)
		{
			chKey = cKeyValue + 1;						//setting key number. indexed format.
			while(!COLUMN2);							//wait until the key is been released.
			return chKey;
		}
		if(!COLUMN3)
		{
			chKey = cKeyValue + 2;						//setting key number. indexed format.
			while(!COLUMN3);							//wait until the key is been released.
			return chKey;
		}
		if(!COLUMN4)
		{
			chKey = cKeyValue + 3;						//setting key number. indexed format.
			while(!COLUMN4);							//wait until the key is been released.
			return chKey;
		}
		if(!COLUMN5)
		{
			chKey = cKeyValue + 4;						//setting key number. indexed format.
			while(!COLUMN5);							//wait until the key is been released.
			return chKey;
		}
		cKeyValue += 5;									//incrrease value for next row scanning.
		KEYBOARD |= 0x10>>cCount;						//make the rows HIGH again.
	}
	return FALSE;
}

unsigned char TranslatedKeyCodeToNumeric( unsigned char chCode)		//translated the keycode to numeric form from 0-9 range.
{
	unsigned char chKey;
	
	chKey = chCode + 47;
	
	return chKey;
}

unsigned char TranslatedKeyCodeToAlphabets( unsigned char chCode)		//translated the keycode to alphabetic form from A-Z;
{
	unsigned char chKey;
	
	chKey = chCode + 64;
	
	return chKey;
}



