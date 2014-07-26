//
//Project title:			Programmer's Keyboard
//File name:				uart_communication_8051.c
//Content:					definations
//Type:						Document, Firmware source code.
//Author:					Annim Banerjee.
//Project Type:				Major Project 2013.
//compiler used:			sdcc.
//MCU Type:					8051
//MCU IC:					NXP 89V51RD2
//

//including headers here...
#include "uart_communication_8051.h"

void init_uart()
{
	TMOD = 0x20;	//set timer2 to 8 bit Auto-reload mode.
	SCON = 0x50;	//enable reception, set serial port mode to 8 bit UART.
	TH1 = 0xfd;		//set baud rate to 9600 for 11.0592MHz.
	TL1 = 0xfd;
	
	//start timer
	TR1 = 1;
}

unsigned char serial_read()
{
	while(!RI);		//wait for receive interrupt flag
	RI=0;			//now clear the flag if data received.
	return SBUF;
}

void serial_send( unsigned char cchText)
{
	
	SBUF=cchText;		//set new data to send now.
	while(!TI);			//wait for last data to send .
	TI=0;				//clear the flag.
}