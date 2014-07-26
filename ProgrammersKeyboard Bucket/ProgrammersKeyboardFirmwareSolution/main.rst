                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
                              4 ; This file was generated Wed Feb 06 12:00:12 2013
                              5 ;--------------------------------------------------------
                              6 	.module main
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _CY
                             14 	.globl _AC
                             15 	.globl _F0
                             16 	.globl _RS1
                             17 	.globl _RS0
                             18 	.globl _OV
                             19 	.globl _F1
                             20 	.globl _P
                             21 	.globl _PS
                             22 	.globl _PT1
                             23 	.globl _PX1
                             24 	.globl _PT0
                             25 	.globl _PX0
                             26 	.globl _RD
                             27 	.globl _WR
                             28 	.globl _T1
                             29 	.globl _T0
                             30 	.globl _INT1
                             31 	.globl _INT0
                             32 	.globl _TXD
                             33 	.globl _RXD
                             34 	.globl _P3_7
                             35 	.globl _P3_6
                             36 	.globl _P3_5
                             37 	.globl _P3_4
                             38 	.globl _P3_3
                             39 	.globl _P3_2
                             40 	.globl _P3_1
                             41 	.globl _P3_0
                             42 	.globl _EA
                             43 	.globl _ES
                             44 	.globl _ET1
                             45 	.globl _EX1
                             46 	.globl _ET0
                             47 	.globl _EX0
                             48 	.globl _P2_7
                             49 	.globl _P2_6
                             50 	.globl _P2_5
                             51 	.globl _P2_4
                             52 	.globl _P2_3
                             53 	.globl _P2_2
                             54 	.globl _P2_1
                             55 	.globl _P2_0
                             56 	.globl _SM0
                             57 	.globl _SM1
                             58 	.globl _SM2
                             59 	.globl _REN
                             60 	.globl _TB8
                             61 	.globl _RB8
                             62 	.globl _TI
                             63 	.globl _RI
                             64 	.globl _P1_7
                             65 	.globl _P1_6
                             66 	.globl _P1_5
                             67 	.globl _P1_4
                             68 	.globl _P1_3
                             69 	.globl _P1_2
                             70 	.globl _P1_1
                             71 	.globl _P1_0
                             72 	.globl _TF1
                             73 	.globl _TR1
                             74 	.globl _TF0
                             75 	.globl _TR0
                             76 	.globl _IE1
                             77 	.globl _IT1
                             78 	.globl _IE0
                             79 	.globl _IT0
                             80 	.globl _P0_7
                             81 	.globl _P0_6
                             82 	.globl _P0_5
                             83 	.globl _P0_4
                             84 	.globl _P0_3
                             85 	.globl _P0_2
                             86 	.globl _P0_1
                             87 	.globl _P0_0
                             88 	.globl _B
                             89 	.globl _ACC
                             90 	.globl _PSW
                             91 	.globl _IP
                             92 	.globl _P3
                             93 	.globl _IE
                             94 	.globl _P2
                             95 	.globl _SBUF
                             96 	.globl _SCON
                             97 	.globl _P1
                             98 	.globl _TH1
                             99 	.globl _TH0
                            100 	.globl _TL1
                            101 	.globl _TL0
                            102 	.globl _TMOD
                            103 	.globl _TCON
                            104 	.globl _PCON
                            105 	.globl _DPH
                            106 	.globl _DPL
                            107 	.globl _SP
                            108 	.globl _P0
                            109 	.globl _cKeyPressed
                            110 	.globl _init_uart
                            111 	.globl _serial_read
                            112 	.globl _serial_send
                            113 	.globl _StartKeyboard
                            114 	.globl _getKeycode
                            115 	.globl _TranslatedKeyCodeToNumeric
                            116 	.globl _TranslatedKeyCodeToAlphabets
                            117 	.globl _delayGenericSeconds
                            118 ;--------------------------------------------------------
                            119 ; special function registers
                            120 ;--------------------------------------------------------
                            121 	.area RSEG    (ABS,DATA)
   0000                     122 	.org 0x0000
                    0080    123 _P0	=	0x0080
                    0081    124 _SP	=	0x0081
                    0082    125 _DPL	=	0x0082
                    0083    126 _DPH	=	0x0083
                    0087    127 _PCON	=	0x0087
                    0088    128 _TCON	=	0x0088
                    0089    129 _TMOD	=	0x0089
                    008A    130 _TL0	=	0x008a
                    008B    131 _TL1	=	0x008b
                    008C    132 _TH0	=	0x008c
                    008D    133 _TH1	=	0x008d
                    0090    134 _P1	=	0x0090
                    0098    135 _SCON	=	0x0098
                    0099    136 _SBUF	=	0x0099
                    00A0    137 _P2	=	0x00a0
                    00A8    138 _IE	=	0x00a8
                    00B0    139 _P3	=	0x00b0
                    00B8    140 _IP	=	0x00b8
                    00D0    141 _PSW	=	0x00d0
                    00E0    142 _ACC	=	0x00e0
                    00F0    143 _B	=	0x00f0
                            144 ;--------------------------------------------------------
                            145 ; special function bits
                            146 ;--------------------------------------------------------
                            147 	.area RSEG    (ABS,DATA)
   0000                     148 	.org 0x0000
                    0080    149 _P0_0	=	0x0080
                    0081    150 _P0_1	=	0x0081
                    0082    151 _P0_2	=	0x0082
                    0083    152 _P0_3	=	0x0083
                    0084    153 _P0_4	=	0x0084
                    0085    154 _P0_5	=	0x0085
                    0086    155 _P0_6	=	0x0086
                    0087    156 _P0_7	=	0x0087
                    0088    157 _IT0	=	0x0088
                    0089    158 _IE0	=	0x0089
                    008A    159 _IT1	=	0x008a
                    008B    160 _IE1	=	0x008b
                    008C    161 _TR0	=	0x008c
                    008D    162 _TF0	=	0x008d
                    008E    163 _TR1	=	0x008e
                    008F    164 _TF1	=	0x008f
                    0090    165 _P1_0	=	0x0090
                    0091    166 _P1_1	=	0x0091
                    0092    167 _P1_2	=	0x0092
                    0093    168 _P1_3	=	0x0093
                    0094    169 _P1_4	=	0x0094
                    0095    170 _P1_5	=	0x0095
                    0096    171 _P1_6	=	0x0096
                    0097    172 _P1_7	=	0x0097
                    0098    173 _RI	=	0x0098
                    0099    174 _TI	=	0x0099
                    009A    175 _RB8	=	0x009a
                    009B    176 _TB8	=	0x009b
                    009C    177 _REN	=	0x009c
                    009D    178 _SM2	=	0x009d
                    009E    179 _SM1	=	0x009e
                    009F    180 _SM0	=	0x009f
                    00A0    181 _P2_0	=	0x00a0
                    00A1    182 _P2_1	=	0x00a1
                    00A2    183 _P2_2	=	0x00a2
                    00A3    184 _P2_3	=	0x00a3
                    00A4    185 _P2_4	=	0x00a4
                    00A5    186 _P2_5	=	0x00a5
                    00A6    187 _P2_6	=	0x00a6
                    00A7    188 _P2_7	=	0x00a7
                    00A8    189 _EX0	=	0x00a8
                    00A9    190 _ET0	=	0x00a9
                    00AA    191 _EX1	=	0x00aa
                    00AB    192 _ET1	=	0x00ab
                    00AC    193 _ES	=	0x00ac
                    00AF    194 _EA	=	0x00af
                    00B0    195 _P3_0	=	0x00b0
                    00B1    196 _P3_1	=	0x00b1
                    00B2    197 _P3_2	=	0x00b2
                    00B3    198 _P3_3	=	0x00b3
                    00B4    199 _P3_4	=	0x00b4
                    00B5    200 _P3_5	=	0x00b5
                    00B6    201 _P3_6	=	0x00b6
                    00B7    202 _P3_7	=	0x00b7
                    00B0    203 _RXD	=	0x00b0
                    00B1    204 _TXD	=	0x00b1
                    00B2    205 _INT0	=	0x00b2
                    00B3    206 _INT1	=	0x00b3
                    00B4    207 _T0	=	0x00b4
                    00B5    208 _T1	=	0x00b5
                    00B6    209 _WR	=	0x00b6
                    00B7    210 _RD	=	0x00b7
                    00B8    211 _PX0	=	0x00b8
                    00B9    212 _PT0	=	0x00b9
                    00BA    213 _PX1	=	0x00ba
                    00BB    214 _PT1	=	0x00bb
                    00BC    215 _PS	=	0x00bc
                    00D0    216 _P	=	0x00d0
                    00D1    217 _F1	=	0x00d1
                    00D2    218 _OV	=	0x00d2
                    00D3    219 _RS0	=	0x00d3
                    00D4    220 _RS1	=	0x00d4
                    00D5    221 _F0	=	0x00d5
                    00D6    222 _AC	=	0x00d6
                    00D7    223 _CY	=	0x00d7
                            224 ;--------------------------------------------------------
                            225 ; overlayable register banks
                            226 ;--------------------------------------------------------
                            227 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     228 	.ds 8
                            229 ;--------------------------------------------------------
                            230 ; internal ram data
                            231 ;--------------------------------------------------------
                            232 	.area DSEG    (DATA)
   0008                     233 _cKeyPressed::
   0008                     234 	.ds 1
                            235 ;--------------------------------------------------------
                            236 ; overlayable items in internal ram 
                            237 ;--------------------------------------------------------
                            238 	.area	OSEG    (OVR,DATA)
                            239 	.area	OSEG    (OVR,DATA)
                            240 	.area	OSEG    (OVR,DATA)
                            241 	.area	OSEG    (OVR,DATA)
                            242 	.area	OSEG    (OVR,DATA)
                            243 ;--------------------------------------------------------
                            244 ; Stack segment in internal ram 
                            245 ;--------------------------------------------------------
                            246 	.area	SSEG	(DATA)
   0009                     247 __start__stack:
   0009                     248 	.ds	1
                            249 
                            250 ;--------------------------------------------------------
                            251 ; indirectly addressable internal ram data
                            252 ;--------------------------------------------------------
                            253 	.area ISEG    (DATA)
                            254 ;--------------------------------------------------------
                            255 ; absolute internal ram data
                            256 ;--------------------------------------------------------
                            257 	.area IABS    (ABS,DATA)
                            258 	.area IABS    (ABS,DATA)
                            259 ;--------------------------------------------------------
                            260 ; bit data
                            261 ;--------------------------------------------------------
                            262 	.area BSEG    (BIT)
                            263 ;--------------------------------------------------------
                            264 ; paged external ram data
                            265 ;--------------------------------------------------------
                            266 	.area PSEG    (PAG,XDATA)
                            267 ;--------------------------------------------------------
                            268 ; external ram data
                            269 ;--------------------------------------------------------
                            270 	.area XSEG    (XDATA)
                            271 ;--------------------------------------------------------
                            272 ; absolute external ram data
                            273 ;--------------------------------------------------------
                            274 	.area XABS    (ABS,XDATA)
                            275 ;--------------------------------------------------------
                            276 ; external initialized ram data
                            277 ;--------------------------------------------------------
                            278 	.area XISEG   (XDATA)
                            279 	.area HOME    (CODE)
                            280 	.area GSINIT0 (CODE)
                            281 	.area GSINIT1 (CODE)
                            282 	.area GSINIT2 (CODE)
                            283 	.area GSINIT3 (CODE)
                            284 	.area GSINIT4 (CODE)
                            285 	.area GSINIT5 (CODE)
                            286 	.area GSINIT  (CODE)
                            287 	.area GSFINAL (CODE)
                            288 	.area CSEG    (CODE)
                            289 ;--------------------------------------------------------
                            290 ; interrupt vector 
                            291 ;--------------------------------------------------------
                            292 	.area HOME    (CODE)
   0000                     293 __interrupt_vect:
   0000 02 00 08            294 	ljmp	__sdcc_gsinit_startup
                            295 ;--------------------------------------------------------
                            296 ; global & static initialisations
                            297 ;--------------------------------------------------------
                            298 	.area HOME    (CODE)
                            299 	.area GSINIT  (CODE)
                            300 	.area GSFINAL (CODE)
                            301 	.area GSINIT  (CODE)
                            302 	.globl __sdcc_gsinit_startup
                            303 	.globl __sdcc_program_startup
                            304 	.globl __start__stack
                            305 	.globl __mcs51_genXINIT
                            306 	.globl __mcs51_genXRAMCLEAR
                            307 	.globl __mcs51_genRAMCLEAR
                            308 	.area GSFINAL (CODE)
   0061 02 00 03            309 	ljmp	__sdcc_program_startup
                            310 ;--------------------------------------------------------
                            311 ; Home
                            312 ;--------------------------------------------------------
                            313 	.area HOME    (CODE)
                            314 	.area HOME    (CODE)
   0003                     315 __sdcc_program_startup:
   0003 12 01 08            316 	lcall	_main
                            317 ;	return from main will lock up
   0006 80 FE               318 	sjmp .
                            319 ;--------------------------------------------------------
                            320 ; code
                            321 ;--------------------------------------------------------
                            322 	.area CSEG    (CODE)
                            323 ;------------------------------------------------------------
                            324 ;Allocation info for local variables in function 'init_uart'
                            325 ;------------------------------------------------------------
                            326 ;	uart_communication_8051.c:16: void init_uart()
                            327 ;	-----------------------------------------
                            328 ;	 function init_uart
                            329 ;	-----------------------------------------
   0064                     330 _init_uart:
                    0007    331 	ar7 = 0x07
                    0006    332 	ar6 = 0x06
                    0005    333 	ar5 = 0x05
                    0004    334 	ar4 = 0x04
                    0003    335 	ar3 = 0x03
                    0002    336 	ar2 = 0x02
                    0001    337 	ar1 = 0x01
                    0000    338 	ar0 = 0x00
                            339 ;	uart_communication_8051.c:18: TMOD = 0x20;	//set timer2 to 8 bit Auto-reload mode.
   0064 75 89 20            340 	mov	_TMOD,#0x20
                            341 ;	uart_communication_8051.c:19: SCON = 0x50;	//enable reception, set serial port mode to 8 bit UART.
   0067 75 98 50            342 	mov	_SCON,#0x50
                            343 ;	uart_communication_8051.c:20: TH1 = 0xfd;		//set baud rate to 9600 for 11.0592MHz.
   006A 75 8D FD            344 	mov	_TH1,#0xFD
                            345 ;	uart_communication_8051.c:21: TL1 = 0xfd;
   006D 75 8B FD            346 	mov	_TL1,#0xFD
                            347 ;	uart_communication_8051.c:24: TR1 = 1;
   0070 D2 8E               348 	setb	_TR1
   0072 22                  349 	ret
                            350 ;------------------------------------------------------------
                            351 ;Allocation info for local variables in function 'serial_read'
                            352 ;------------------------------------------------------------
                            353 ;	uart_communication_8051.c:27: unsigned char serial_read()
                            354 ;	-----------------------------------------
                            355 ;	 function serial_read
                            356 ;	-----------------------------------------
   0073                     357 _serial_read:
                            358 ;	uart_communication_8051.c:29: while(!RI);		//wait for receive interrupt flag
   0073                     359 00101$:
                            360 ;	uart_communication_8051.c:30: RI=0;			//now clear the flag if data received.
   0073 10 98 02            361 	jbc	_RI,00110$
   0076 80 FB               362 	sjmp	00101$
   0078                     363 00110$:
                            364 ;	uart_communication_8051.c:31: return SBUF;
   0078 85 99 82            365 	mov	dpl,_SBUF
   007B 22                  366 	ret
                            367 ;------------------------------------------------------------
                            368 ;Allocation info for local variables in function 'serial_send'
                            369 ;------------------------------------------------------------
                            370 ;cchText                   Allocated to registers 
                            371 ;------------------------------------------------------------
                            372 ;	uart_communication_8051.c:34: void serial_send( unsigned char cchText)
                            373 ;	-----------------------------------------
                            374 ;	 function serial_send
                            375 ;	-----------------------------------------
   007C                     376 _serial_send:
   007C 85 82 99            377 	mov	_SBUF,dpl
                            378 ;	uart_communication_8051.c:38: while(!TI);			//wait for last data to send .
   007F                     379 00101$:
                            380 ;	uart_communication_8051.c:39: TI=0;				//clear the flag.
   007F 10 99 02            381 	jbc	_TI,00110$
   0082 80 FB               382 	sjmp	00101$
   0084                     383 00110$:
   0084 22                  384 	ret
                            385 ;------------------------------------------------------------
                            386 ;Allocation info for local variables in function 'StartKeyboard'
                            387 ;------------------------------------------------------------
                            388 ;	keyboardparse.c:25: void StartKeyboard()		//initialize the keyboard by setting the required default settings.
                            389 ;	-----------------------------------------
                            390 ;	 function StartKeyboard
                            391 ;	-----------------------------------------
   0085                     392 _StartKeyboard:
                            393 ;	keyboardparse.c:30: P2 &= 0x1f;	//set first 5 bits HIGH; setting col as i/p.
   0085 53 A0 1F            394 	anl	_P2,#0x1F
                            395 ;	keyboardparse.c:31: KEYBOARD &= 0x00;	//set rows as o/p;	
   0088 E5 90               396 	mov	a,_P1
   008A 75 90 00            397 	mov	_P1,#0x00
   008D 22                  398 	ret
                            399 ;------------------------------------------------------------
                            400 ;Allocation info for local variables in function 'getKeycode'
                            401 ;------------------------------------------------------------
                            402 ;chKey                     Allocated to registers r3 
                            403 ;cCount                    Allocated to registers r5 
                            404 ;cKeyValue                 Allocated to registers r7 
                            405 ;------------------------------------------------------------
                            406 ;	keyboardparse.c:33: unsigned char getKeycode()	//get the key code against the key pressed.
                            407 ;	-----------------------------------------
                            408 ;	 function getKeycode
                            409 ;	-----------------------------------------
   008E                     410 _getKeycode:
                            411 ;	keyboardparse.c:35: unsigned char chKey=0, cCount, cKeyValue = 1;
   008E 7F 01               412 	mov	r7,#0x01
                            413 ;	keyboardparse.c:36: for( cCount = 0; cCount < 5; cCount++)				//loop for 5 rows.
   0090 7E 01               414 	mov	r6,#0x01
   0092 7D 00               415 	mov	r5,#0x00
   0094                     416 00126$:
   0094 BD 05 00            417 	cjne	r5,#0x05,00166$
   0097                     418 00166$:
   0097 50 5B               419 	jnc	00129$
                            420 ;	keyboardparse.c:38: KEYBOARD &= ~(0x10>>cCount);					//make rows low one by one...
   0099 8D F0               421 	mov	b,r5
   009B 05 F0               422 	inc	b
   009D 74 10               423 	mov	a,#0x10
   009F 80 02               424 	sjmp	00169$
   00A1                     425 00168$:
   00A1 C3                  426 	clr	c
   00A2 13                  427 	rrc	a
   00A3                     428 00169$:
   00A3 D5 F0 FB            429 	djnz	b,00168$
   00A6 FC                  430 	mov	r4,a
   00A7 F4                  431 	cpl	a
   00A8 FB                  432 	mov	r3,a
   00A9 52 90               433 	anl	_P1,a
                            434 ;	keyboardparse.c:39: if(!COLUMN1)
   00AB 20 A0 08            435 	jb	_P2_0,00105$
                            436 ;	keyboardparse.c:41: chKey = cKeyValue + 0;						//setting key number. indexed format.
   00AE 8F 03               437 	mov	ar3,r7
                            438 ;	keyboardparse.c:42: while(!COLUMN1);							//wait until the key is been released.
   00B0                     439 00101$:
   00B0 30 A0 FD            440 	jnb	_P2_0,00101$
                            441 ;	keyboardparse.c:43: return chKey;
   00B3 8B 82               442 	mov	dpl,r3
   00B5 22                  443 	ret
   00B6                     444 00105$:
                            445 ;	keyboardparse.c:45: if(!COLUMN2)
   00B6 20 A1 09            446 	jb	_P2_1,00110$
                            447 ;	keyboardparse.c:47: chKey = cKeyValue + 1;						//setting key number. indexed format.
   00B9 EF                  448 	mov	a,r7
   00BA 04                  449 	inc	a
   00BB FB                  450 	mov	r3,a
                            451 ;	keyboardparse.c:48: while(!COLUMN2);							//wait until the key is been released.
   00BC                     452 00106$:
   00BC 30 A1 FD            453 	jnb	_P2_1,00106$
                            454 ;	keyboardparse.c:49: return chKey;
   00BF 8B 82               455 	mov	dpl,r3
   00C1 22                  456 	ret
   00C2                     457 00110$:
                            458 ;	keyboardparse.c:51: if(!COLUMN3)
   00C2 20 A2 0A            459 	jb	_P2_2,00115$
                            460 ;	keyboardparse.c:53: chKey = cKeyValue + 2;						//setting key number. indexed format.
   00C5 74 02               461 	mov	a,#0x02
   00C7 2F                  462 	add	a,r7
   00C8 FB                  463 	mov	r3,a
                            464 ;	keyboardparse.c:54: while(!COLUMN3);							//wait until the key is been released.
   00C9                     465 00111$:
   00C9 30 A2 FD            466 	jnb	_P2_2,00111$
                            467 ;	keyboardparse.c:55: return chKey;
   00CC 8B 82               468 	mov	dpl,r3
   00CE 22                  469 	ret
   00CF                     470 00115$:
                            471 ;	keyboardparse.c:57: if(!COLUMN4)
   00CF 20 A3 0A            472 	jb	_P2_3,00120$
                            473 ;	keyboardparse.c:59: chKey = cKeyValue + 3;						//setting key number. indexed format.
   00D2 74 03               474 	mov	a,#0x03
   00D4 2F                  475 	add	a,r7
   00D5 FB                  476 	mov	r3,a
                            477 ;	keyboardparse.c:60: while(!COLUMN4);							//wait until the key is been released.
   00D6                     478 00116$:
   00D6 30 A3 FD            479 	jnb	_P2_3,00116$
                            480 ;	keyboardparse.c:61: return chKey;
   00D9 8B 82               481 	mov	dpl,r3
   00DB 22                  482 	ret
   00DC                     483 00120$:
                            484 ;	keyboardparse.c:63: if(!COLUMN5)
   00DC 20 A4 0A            485 	jb	_P2_4,00125$
                            486 ;	keyboardparse.c:65: chKey = cKeyValue + 4;						//setting key number. indexed format.
   00DF 74 04               487 	mov	a,#0x04
   00E1 2F                  488 	add	a,r7
   00E2 FB                  489 	mov	r3,a
                            490 ;	keyboardparse.c:66: while(!COLUMN5);							//wait until the key is been released.
   00E3                     491 00121$:
   00E3 30 A4 FD            492 	jnb	_P2_4,00121$
                            493 ;	keyboardparse.c:67: return chKey;
   00E6 8B 82               494 	mov	dpl,r3
   00E8 22                  495 	ret
   00E9                     496 00125$:
                            497 ;	keyboardparse.c:69: cKeyValue += 5;									//incrrease value for next row scanning.
   00E9 74 05               498 	mov	a,#0x05
   00EB 2E                  499 	add	a,r6
   00EC FE                  500 	mov	r6,a
   00ED FF                  501 	mov	r7,a
                            502 ;	keyboardparse.c:70: KEYBOARD |= 0x10>>cCount;						//make the rows HIGH again.
   00EE EC                  503 	mov	a,r4
   00EF 42 90               504 	orl	_P1,a
                            505 ;	keyboardparse.c:36: for( cCount = 0; cCount < 5; cCount++)				//loop for 5 rows.
   00F1 0D                  506 	inc	r5
   00F2 80 A0               507 	sjmp	00126$
   00F4                     508 00129$:
                            509 ;	keyboardparse.c:72: return FALSE;
   00F4 75 82 00            510 	mov	dpl,#0x00
   00F7 22                  511 	ret
                            512 ;------------------------------------------------------------
                            513 ;Allocation info for local variables in function 'TranslatedKeyCodeToNumeric'
                            514 ;------------------------------------------------------------
                            515 ;chCode                    Allocated to registers r7 
                            516 ;chKey                     Allocated to registers 
                            517 ;------------------------------------------------------------
                            518 ;	keyboardparse.c:75: unsigned char TranslatedKeyCodeToNumeric( unsigned char chCode)		//translated the keycode to numeric form from 0-9 range.
                            519 ;	-----------------------------------------
                            520 ;	 function TranslatedKeyCodeToNumeric
                            521 ;	-----------------------------------------
   00F8                     522 _TranslatedKeyCodeToNumeric:
   00F8 AF 82               523 	mov	r7,dpl
                            524 ;	keyboardparse.c:79: chKey = chCode + 47;
   00FA 74 2F               525 	mov	a,#0x2F
   00FC 2F                  526 	add	a,r7
   00FD F5 82               527 	mov	dpl,a
                            528 ;	keyboardparse.c:81: return chKey;
   00FF 22                  529 	ret
                            530 ;------------------------------------------------------------
                            531 ;Allocation info for local variables in function 'TranslatedKeyCodeToAlphabets'
                            532 ;------------------------------------------------------------
                            533 ;chCode                    Allocated to registers r7 
                            534 ;chKey                     Allocated to registers 
                            535 ;------------------------------------------------------------
                            536 ;	keyboardparse.c:84: unsigned char TranslatedKeyCodeToAlphabets( unsigned char chCode)		//translated the keycode to alphabetic form from A-Z;
                            537 ;	-----------------------------------------
                            538 ;	 function TranslatedKeyCodeToAlphabets
                            539 ;	-----------------------------------------
   0100                     540 _TranslatedKeyCodeToAlphabets:
   0100 AF 82               541 	mov	r7,dpl
                            542 ;	keyboardparse.c:88: chKey = chCode + 64;
   0102 74 40               543 	mov	a,#0x40
   0104 2F                  544 	add	a,r7
   0105 F5 82               545 	mov	dpl,a
                            546 ;	keyboardparse.c:90: return chKey;
   0107 22                  547 	ret
                            548 ;------------------------------------------------------------
                            549 ;Allocation info for local variables in function 'main'
                            550 ;------------------------------------------------------------
                            551 ;	main.c:24: void main()
                            552 ;	-----------------------------------------
                            553 ;	 function main
                            554 ;	-----------------------------------------
   0108                     555 _main:
                            556 ;	main.c:27: init_uart();
   0108 12 00 64            557 	lcall	_init_uart
                            558 ;	main.c:30: StartKeyboard();
   010B 12 00 85            559 	lcall	_StartKeyboard
                            560 ;	main.c:32: while( 1 )		//an infinite loop.
   010E                     561 00104$:
                            562 ;	main.c:34: cKeyPressed = getKeycode();
   010E 12 00 8E            563 	lcall	_getKeycode
                            564 ;	main.c:35: if( cKeyPressed > 0 )
   0111 E5 82               565 	mov	a,dpl
   0113 F5 08               566 	mov	_cKeyPressed,a
   0115 60 F7               567 	jz	00104$
                            568 ;	main.c:37: serial_send( TranslatedKeyCodeToAlphabets(cKeyPressed) );
   0117 85 08 82            569 	mov	dpl,_cKeyPressed
   011A 12 01 00            570 	lcall	_TranslatedKeyCodeToAlphabets
   011D 12 00 7C            571 	lcall	_serial_send
                            572 ;	main.c:38: delayGenericSeconds( 500 );
   0120 90 01 F4            573 	mov	dptr,#0x01F4
   0123 12 01 28            574 	lcall	_delayGenericSeconds
   0126 80 E6               575 	sjmp	00104$
                            576 ;------------------------------------------------------------
                            577 ;Allocation info for local variables in function 'delayGenericSeconds'
                            578 ;------------------------------------------------------------
                            579 ;value                     Allocated to registers r6 r7 
                            580 ;i                         Allocated to registers r4 r5 
                            581 ;j                         Allocated to registers r2 r3 
                            582 ;------------------------------------------------------------
                            583 ;	main.c:44: void delayGenericSeconds( int value)
                            584 ;	-----------------------------------------
                            585 ;	 function delayGenericSeconds
                            586 ;	-----------------------------------------
   0128                     587 _delayGenericSeconds:
   0128 AE 82               588 	mov	r6,dpl
   012A AF 83               589 	mov	r7,dph
                            590 ;	main.c:47: for(i=0;i<value;i++)
   012C 7C 00               591 	mov	r4,#0x00
   012E 7D 00               592 	mov	r5,#0x00
   0130                     593 00104$:
   0130 C3                  594 	clr	c
   0131 EC                  595 	mov	a,r4
   0132 9E                  596 	subb	a,r6
   0133 ED                  597 	mov	a,r5
   0134 64 80               598 	xrl	a,#0x80
   0136 8F F0               599 	mov	b,r7
   0138 63 F0 80            600 	xrl	b,#0x80
   013B 95 F0               601 	subb	a,b
   013D 50 14               602 	jnc	00108$
                            603 ;	main.c:48: for(j=0;j<123;j++);
   013F 7A 7B               604 	mov	r2,#0x7B
   0141 7B 00               605 	mov	r3,#0x00
   0143                     606 00103$:
   0143 1A                  607 	dec	r2
   0144 BA FF 01            608 	cjne	r2,#0xFF,00121$
   0147 1B                  609 	dec	r3
   0148                     610 00121$:
   0148 EA                  611 	mov	a,r2
   0149 4B                  612 	orl	a,r3
   014A 70 F7               613 	jnz	00103$
                            614 ;	main.c:47: for(i=0;i<value;i++)
   014C 0C                  615 	inc	r4
   014D BC 00 E0            616 	cjne	r4,#0x00,00104$
   0150 0D                  617 	inc	r5
   0151 80 DD               618 	sjmp	00104$
   0153                     619 00108$:
   0153 22                  620 	ret
                            621 	.area CSEG    (CODE)
                            622 	.area CONST   (CODE)
                            623 	.area XINIT   (CODE)
                            624 	.area CABS    (ABS,CODE)
