//
//Project title:			Programmer's Keyboard
//File name:				uart_communication_8051.h
//Content:					prototypes
//Type:						Document, Firmware source code.
//Author:					Annim Banerjee.
//Project Type:				Major Project 2013.
//compiler used:			sdcc.
//MCU Type:					8051
//MCU IC:					NXP 89V51RD2
//

#ifndef UART_COMMUNICATION_8051_H
#define UART_COMMUNICATION_8051_H

void init_uart();								//initialize the uart communication by setting up the environment in 8051.
unsigned char serial_read();					//for serial read.
void serial_send( unsigned char );				//for serial send operation.

#endif