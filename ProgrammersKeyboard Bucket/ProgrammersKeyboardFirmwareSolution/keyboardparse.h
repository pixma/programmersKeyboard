//
//Project title:			Programmer's Keyboard
//File name:				keyboardParse.h
//Content:					prototypes
//Type:						Document, Firmware source code.
//Author:					Annim Banerjee.
//Project Type:				Major Project 2013.
//compiler used:			sdcc.
//MCU Type:					8051
//MCU IC:					NXP 89V51RD2
//

#ifndef KEYBOARDPARSE_H
#define KEYBOARDPARSE_H

//macros defined here...
#define COLUMN1		P2_0
#define COLUMN2		P2_1
#define COLUMN3		P2_2
#define COLUMN4		P2_3
#define COLUMN5		P2_4
#define KEYBOARD	P1

void StartKeyboard();		//initialize the keyboard by setting the required default settings.
unsigned char getKeycode();	//get the key code against the key pressed.
unsigned char TranslatedKeyCodeToNumeric( unsigned char );		//translated the keycode to numeric form from 0-9 range.
unsigned char TranslatedKeyCodeToAlphabets( unsigned char );		//translated the keycode to alphabetic form from A-Z;

#endif
