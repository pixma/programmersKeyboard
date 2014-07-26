/*

Author:			Annim Banerjee
File:			Programmer'sKeyboard.h(standard application header file)
Content:		Prototypes and pre-declaration of functions, structures macros etc.
Project:		Programmer's Keyboard.
Dated:			Jan 2013.

*/

#include "stdafx.h"

//defining custom macros
#define DATA_RECEIVED_FROM_COMPORT_NOW												WM_APP+2
#define APPLICATION_TRAYICON_CONTROL_MESSAGE										WM_APP+1
#define APPLICATION_TRAYICON_CONTROL_ID													37999
#define COMMANDLINK_BUTTON_CONNECT_DISCONNECT								38000
#define COMMANDLINK_BUTTON_MINIMIZE														38001
#define TPCM_LANGUAGE																						38002
#define TPCM_APPLICATION_RESTORE																	38003
#define TCPM_LANGUAGE_C																					38004
#define TCPM_LANGUAGE_CPP																				38005
#define TCPM_ABOUT_APPLICATION																	38006
#define TCPM_APPLICATION_EXIT																			38007
#define TCPM_LANGUAGE_NONE																			38008
#define TCPM_LANUGAGE_JAVA																				38009
#define TCPM_LANUGAGE_C_SHARP																		38010
#define TCPM_LANUGAGE_VISUAL_BASIC															38011
#define TCPM_CONTEXTMENU_DISMISS																38012



//writting prototype for the application.
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT WINAPI DlgCallBackProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT WINAPI AboutDialogProcedure(HWND, UINT, WPARAM, LPARAM);
void WINAPI PerformEssentials(HWND, UINT, WPARAM, LPARAM);
HINSTANCE GetWindowhandleInstance( HWND );
void WINAPI CreateCommandLinkButton( HWND, int, int, int, int, int);
void WINAPI PopulateCOMPort( HWND, UINT, WPARAM, LPARAM);
void WINAPI CheckMyContextMenu( HWND, HMENU, int);
void WINAPI UnCheckMyContextMenu( HWND, HMENU, int);
DWORD WINAPI  ReadExistingFromComPort( void * );
DWORD WINAPI RegulateButtonSendSnippet( HWND, LPARAM, int);
DWORD WINAPI FillForNotSpecified( LPARAM );
DWORD WINAPI FillForCLanguage( LPARAM );
DWORD WINAPI FillForCPPLanguage( LPARAM );
DWORD WINAPI FillForJavaLanguage( LPARAM );
DWORD WINAPI FillForCSharpLanguage( LPARAM );
DWORD WINAPI FillForVisualBasicLanguage( LPARAM );
DWORD WINAPI SendData(WCHAR szData[ONEKILO]);
DWORD WINAPI SendKeyData( char );
DWORD WINAPI PressShiftKey();
DWORD WINAPI ReleaseShiftKey();
DWORD WINAPI HitEnterKey();
DWORD WINAPI HitTabKey();
DWORD WINAPI HitSpaceKey();
DWORD WINAPI hitBackSpace();


//global structure,enum declaration...


//defining global variable.
static int nLangSelectedIndex;
static bool isConnected;
static HWND gHandleWindow;
static HANDLE hPortHandle;