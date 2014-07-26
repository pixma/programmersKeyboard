/*

Author:			Annim Banerjee
File:			stdafx.h(standard application header file)
Content:		Essestial header files includes goes in this document file.
Project:		Programmer's Keyboard.
Dated:			Jan 2013.

*/

//defining MACROS and some other essentials preprocessors compiler directives.

#ifndef STDAFX_H
#define STDAFX_H
//asuring for Vista control libraries to link.
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' \"\"version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#endif

#define _WIN32_WINNT_ 0x0601
#define MAXLEN	100
#define MAXTHREADS	10
#define ONEKILO 1024

//#include <WinUser.h>
#include <Windows.h>
#include <commctrl.h>
#include <ShellAPI.h>
#include <stdlib.h>

#endif