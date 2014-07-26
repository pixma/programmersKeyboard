;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
; This file was generated Wed Feb 06 12:00:12 2013
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _cKeyPressed
	.globl _init_uart
	.globl _serial_read
	.globl _serial_send
	.globl _StartKeyboard
	.globl _getKeycode
	.globl _TranslatedKeyCodeToNumeric
	.globl _TranslatedKeyCodeToAlphabets
	.globl _delayGenericSeconds
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_cKeyPressed::
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'init_uart'
;------------------------------------------------------------
;	uart_communication_8051.c:16: void init_uart()
;	-----------------------------------------
;	 function init_uart
;	-----------------------------------------
_init_uart:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	uart_communication_8051.c:18: TMOD = 0x20;	//set timer2 to 8 bit Auto-reload mode.
	mov	_TMOD,#0x20
;	uart_communication_8051.c:19: SCON = 0x50;	//enable reception, set serial port mode to 8 bit UART.
	mov	_SCON,#0x50
;	uart_communication_8051.c:20: TH1 = 0xfd;		//set baud rate to 9600 for 11.0592MHz.
	mov	_TH1,#0xFD
;	uart_communication_8051.c:21: TL1 = 0xfd;
	mov	_TL1,#0xFD
;	uart_communication_8051.c:24: TR1 = 1;
	setb	_TR1
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'serial_read'
;------------------------------------------------------------
;	uart_communication_8051.c:27: unsigned char serial_read()
;	-----------------------------------------
;	 function serial_read
;	-----------------------------------------
_serial_read:
;	uart_communication_8051.c:29: while(!RI);		//wait for receive interrupt flag
00101$:
;	uart_communication_8051.c:30: RI=0;			//now clear the flag if data received.
	jbc	_RI,00110$
	sjmp	00101$
00110$:
;	uart_communication_8051.c:31: return SBUF;
	mov	dpl,_SBUF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'serial_send'
;------------------------------------------------------------
;cchText                   Allocated to registers 
;------------------------------------------------------------
;	uart_communication_8051.c:34: void serial_send( unsigned char cchText)
;	-----------------------------------------
;	 function serial_send
;	-----------------------------------------
_serial_send:
	mov	_SBUF,dpl
;	uart_communication_8051.c:38: while(!TI);			//wait for last data to send .
00101$:
;	uart_communication_8051.c:39: TI=0;				//clear the flag.
	jbc	_TI,00110$
	sjmp	00101$
00110$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'StartKeyboard'
;------------------------------------------------------------
;	keyboardparse.c:25: void StartKeyboard()		//initialize the keyboard by setting the required default settings.
;	-----------------------------------------
;	 function StartKeyboard
;	-----------------------------------------
_StartKeyboard:
;	keyboardparse.c:30: P2 &= 0x1f;	//set first 5 bits HIGH; setting col as i/p.
	anl	_P2,#0x1F
;	keyboardparse.c:31: KEYBOARD &= 0x00;	//set rows as o/p;	
	mov	a,_P1
	mov	_P1,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getKeycode'
;------------------------------------------------------------
;chKey                     Allocated to registers r3 
;cCount                    Allocated to registers r5 
;cKeyValue                 Allocated to registers r7 
;------------------------------------------------------------
;	keyboardparse.c:33: unsigned char getKeycode()	//get the key code against the key pressed.
;	-----------------------------------------
;	 function getKeycode
;	-----------------------------------------
_getKeycode:
;	keyboardparse.c:35: unsigned char chKey=0, cCount, cKeyValue = 1;
	mov	r7,#0x01
;	keyboardparse.c:36: for( cCount = 0; cCount < 5; cCount++)				//loop for 5 rows.
	mov	r6,#0x01
	mov	r5,#0x00
00126$:
	cjne	r5,#0x05,00166$
00166$:
	jnc	00129$
;	keyboardparse.c:38: KEYBOARD &= ~(0x10>>cCount);					//make rows low one by one...
	mov	b,r5
	inc	b
	mov	a,#0x10
	sjmp	00169$
00168$:
	clr	c
	rrc	a
00169$:
	djnz	b,00168$
	mov	r4,a
	cpl	a
	mov	r3,a
	anl	_P1,a
;	keyboardparse.c:39: if(!COLUMN1)
	jb	_P2_0,00105$
;	keyboardparse.c:41: chKey = cKeyValue + 0;						//setting key number. indexed format.
	mov	ar3,r7
;	keyboardparse.c:42: while(!COLUMN1);							//wait until the key is been released.
00101$:
	jnb	_P2_0,00101$
;	keyboardparse.c:43: return chKey;
	mov	dpl,r3
	ret
00105$:
;	keyboardparse.c:45: if(!COLUMN2)
	jb	_P2_1,00110$
;	keyboardparse.c:47: chKey = cKeyValue + 1;						//setting key number. indexed format.
	mov	a,r7
	inc	a
	mov	r3,a
;	keyboardparse.c:48: while(!COLUMN2);							//wait until the key is been released.
00106$:
	jnb	_P2_1,00106$
;	keyboardparse.c:49: return chKey;
	mov	dpl,r3
	ret
00110$:
;	keyboardparse.c:51: if(!COLUMN3)
	jb	_P2_2,00115$
;	keyboardparse.c:53: chKey = cKeyValue + 2;						//setting key number. indexed format.
	mov	a,#0x02
	add	a,r7
	mov	r3,a
;	keyboardparse.c:54: while(!COLUMN3);							//wait until the key is been released.
00111$:
	jnb	_P2_2,00111$
;	keyboardparse.c:55: return chKey;
	mov	dpl,r3
	ret
00115$:
;	keyboardparse.c:57: if(!COLUMN4)
	jb	_P2_3,00120$
;	keyboardparse.c:59: chKey = cKeyValue + 3;						//setting key number. indexed format.
	mov	a,#0x03
	add	a,r7
	mov	r3,a
;	keyboardparse.c:60: while(!COLUMN4);							//wait until the key is been released.
00116$:
	jnb	_P2_3,00116$
;	keyboardparse.c:61: return chKey;
	mov	dpl,r3
	ret
00120$:
;	keyboardparse.c:63: if(!COLUMN5)
	jb	_P2_4,00125$
;	keyboardparse.c:65: chKey = cKeyValue + 4;						//setting key number. indexed format.
	mov	a,#0x04
	add	a,r7
	mov	r3,a
;	keyboardparse.c:66: while(!COLUMN5);							//wait until the key is been released.
00121$:
	jnb	_P2_4,00121$
;	keyboardparse.c:67: return chKey;
	mov	dpl,r3
	ret
00125$:
;	keyboardparse.c:69: cKeyValue += 5;									//incrrease value for next row scanning.
	mov	a,#0x05
	add	a,r6
	mov	r6,a
	mov	r7,a
;	keyboardparse.c:70: KEYBOARD |= 0x10>>cCount;						//make the rows HIGH again.
	mov	a,r4
	orl	_P1,a
;	keyboardparse.c:36: for( cCount = 0; cCount < 5; cCount++)				//loop for 5 rows.
	inc	r5
	sjmp	00126$
00129$:
;	keyboardparse.c:72: return FALSE;
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TranslatedKeyCodeToNumeric'
;------------------------------------------------------------
;chCode                    Allocated to registers r7 
;chKey                     Allocated to registers 
;------------------------------------------------------------
;	keyboardparse.c:75: unsigned char TranslatedKeyCodeToNumeric( unsigned char chCode)		//translated the keycode to numeric form from 0-9 range.
;	-----------------------------------------
;	 function TranslatedKeyCodeToNumeric
;	-----------------------------------------
_TranslatedKeyCodeToNumeric:
	mov	r7,dpl
;	keyboardparse.c:79: chKey = chCode + 47;
	mov	a,#0x2F
	add	a,r7
	mov	dpl,a
;	keyboardparse.c:81: return chKey;
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TranslatedKeyCodeToAlphabets'
;------------------------------------------------------------
;chCode                    Allocated to registers r7 
;chKey                     Allocated to registers 
;------------------------------------------------------------
;	keyboardparse.c:84: unsigned char TranslatedKeyCodeToAlphabets( unsigned char chCode)		//translated the keycode to alphabetic form from A-Z;
;	-----------------------------------------
;	 function TranslatedKeyCodeToAlphabets
;	-----------------------------------------
_TranslatedKeyCodeToAlphabets:
	mov	r7,dpl
;	keyboardparse.c:88: chKey = chCode + 64;
	mov	a,#0x40
	add	a,r7
	mov	dpl,a
;	keyboardparse.c:90: return chKey;
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	main.c:24: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c:27: init_uart();
	lcall	_init_uart
;	main.c:30: StartKeyboard();
	lcall	_StartKeyboard
;	main.c:32: while( 1 )		//an infinite loop.
00104$:
;	main.c:34: cKeyPressed = getKeycode();
	lcall	_getKeycode
;	main.c:35: if( cKeyPressed > 0 )
	mov	a,dpl
	mov	_cKeyPressed,a
	jz	00104$
;	main.c:37: serial_send( TranslatedKeyCodeToAlphabets(cKeyPressed) );
	mov	dpl,_cKeyPressed
	lcall	_TranslatedKeyCodeToAlphabets
	lcall	_serial_send
;	main.c:38: delayGenericSeconds( 500 );
	mov	dptr,#0x01F4
	lcall	_delayGenericSeconds
	sjmp	00104$
;------------------------------------------------------------
;Allocation info for local variables in function 'delayGenericSeconds'
;------------------------------------------------------------
;value                     Allocated to registers r6 r7 
;i                         Allocated to registers r4 r5 
;j                         Allocated to registers r2 r3 
;------------------------------------------------------------
;	main.c:44: void delayGenericSeconds( int value)
;	-----------------------------------------
;	 function delayGenericSeconds
;	-----------------------------------------
_delayGenericSeconds:
	mov	r6,dpl
	mov	r7,dph
;	main.c:47: for(i=0;i<value;i++)
	mov	r4,#0x00
	mov	r5,#0x00
00104$:
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00108$
;	main.c:48: for(j=0;j<123;j++);
	mov	r2,#0x7B
	mov	r3,#0x00
00103$:
	dec	r2
	cjne	r2,#0xFF,00121$
	dec	r3
00121$:
	mov	a,r2
	orl	a,r3
	jnz	00103$
;	main.c:47: for(i=0;i<value;i++)
	inc	r4
	cjne	r4,#0x00,00104$
	inc	r5
	sjmp	00104$
00108$:
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
