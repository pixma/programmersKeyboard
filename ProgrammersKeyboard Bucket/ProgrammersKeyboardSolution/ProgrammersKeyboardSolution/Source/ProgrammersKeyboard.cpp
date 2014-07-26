/*

Author:			Annim Banerjee
File:			Programmer'sKeyboard.cpp(standard application source file)
Content:		Definations and implementations.
Project:		Programmer's Keyboard.
Dated:			Jan 2013.

*/

#include "..\Headers\ProgrammersKeyboard.h"
#include "..\Resources\resource.h"

//global vardiable declaration...
static HANDLE hThread[MAXTHREADS] = {0};
//writting the Entry point function of the application, code goes here...
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;		//variable:message.
	HWND hWnd;
	int pnButton = 0;

	//creating application main window, code goes here...
	hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_APPWINDOW), NULL, (DLGPROC)DlgCallBackProcedure );
	gHandleWindow = hWnd;
	if( hWnd == NULL )
	{
		TaskDialog(NULL, hInstance, MAKEINTRESOURCE(IDS_APPERR_CAPTION),
			MAKEINTRESOURCE(IDS_ERRWINDOWCREATIONFAIL), MAKEINTRESOURCE(IDS_ERRMSG), 
			TDCBF_OK_BUTTON , TD_ERROR_ICON, &pnButton);
		PostQuitMessage( 0 );	//post a quit message to quit the application from this point of execution.
	}
	
	ShowWindow( hWnd, SW_NORMAL);
	UpdateWindow( hWnd );


	//application message loop or say message pump code goes here...
	while( GetMessage( &msg, NULL, 0, 0) > 0)
	{
		if(!IsDialogMessage( hWnd, &msg ))
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
	}


	//the return value.
	return msg.wParam;
}

HINSTANCE GetWindowhandleInstance( HWND hWnd)
{
	return (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
}

//defination of the DlgCallbackProcedure() code goes here...
LRESULT WINAPI DlgCallBackProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HBRUSH hBackgroundbrush = CreateSolidBrush( RGB(0,0,0) );
	static NOTIFYICONDATA nidTrayIconInstance;
	int nStore=0;
	TCHAR sztCharStringOne[ONEKILO];
	WORD wPopUpCmd;
	POINT ptCursorPoint;
	HMENU hContextMenuPopUp, hSubLangContextMenuPopUp;
	HBITMAP hBitmapChecked, hBitmapUnChecked;
	DWORD dwThreadId[MAXTHREADS] = {0};
	

	switch( uMsg )
	{
	case DATA_RECEIVED_FROM_COMPORT_NOW:
		//to do something when data is received from COM port.
		//MessageBox( (HWND)wParam, (LPCWSTR)lParam, L"Message",MB_OK);
		RegulateButtonSendSnippet( gHandleWindow,  lParam, nLangSelectedIndex);

		return 0;
		break;
	case WM_INITDIALOG:
		// Dialog box procedures typically use this message to initialize controls 
		//and carry out any other initialization tasks that affect the appearance of the dialog box.
		//This message will be received only for onces.
		nLangSelectedIndex = -1;
		isConnected = false;
		PerformEssentials(hWnd, uMsg, wParam, lParam);
		break;	
	case APPLICATION_TRAYICON_CONTROL_MESSAGE:
		switch( lParam )
		{
		case WM_RBUTTONUP:
			GetCursorPos( &ptCursorPoint );
			hContextMenuPopUp = CreatePopupMenu();

			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_APPLICATION_EXIT ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_APPLICATION_EXIT, sztCharStringOne);			

			//appending a seprator in menu
			AppendMenu( hContextMenuPopUp, MF_SEPARATOR, NULL, NULL);

			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_ABOUT_APPLICATION ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_ABOUT_APPLICATION, sztCharStringOne);

			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_APPLICATION_RESTORE ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TPCM_APPLICATION_RESTORE, sztCharStringOne);

			
			hSubLangContextMenuPopUp = CreatePopupMenu();
			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_C_LANG ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hSubLangContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_LANGUAGE_C, sztCharStringOne);
			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_CPP_LANG ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hSubLangContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_LANGUAGE_CPP, sztCharStringOne);			
			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_JAVA_LANG ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hSubLangContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_LANUGAGE_JAVA, sztCharStringOne);				
			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_C_SHARP ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hSubLangContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_LANUGAGE_C_SHARP, sztCharStringOne);
			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_VB_LANG ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hSubLangContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_LANUGAGE_VISUAL_BASIC, sztCharStringOne);
			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_NOT_SPECIFIC_LANGUAGE ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu(hSubLangContextMenuPopUp, MF_ENABLED|MF_STRING|MF_POPUP, TCPM_LANGUAGE_NONE, sztCharStringOne);

			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_LANGUAGES ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu( hContextMenuPopUp,  MF_POPUP | MF_STRING, (UINT_PTR) hSubLangContextMenuPopUp, sztCharStringOne);

			LoadString( GetWindowhandleInstance( hWnd ), IDS_CMT_CONTEXT_MENU_DISSMISS ,
				sztCharStringOne, sizeof(sztCharStringOne)/sizeof(TCHAR));
			AppendMenu( hContextMenuPopUp,  MF_POPUP | MF_STRING, TCPM_CONTEXTMENU_DISMISS, sztCharStringOne);

			
			//configuring for checkmark code goes here...
			hBitmapChecked = LoadBitmap( GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE(IDB_IS_CONNECTED));
			hBitmapUnChecked = LoadBitmap( GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE(IDB_NOT_CONNECTED));
			//default configuration goes here, code goes below...
			
			switch( nLangSelectedIndex )
			{
			case 0:
				CheckMenuItem( hSubLangContextMenuPopUp, 
					TCPM_LANGUAGE_C,
					MF_BYCOMMAND|MF_CHECKED);
				break;
			case 1:
				CheckMenuItem( hSubLangContextMenuPopUp, 
					TCPM_LANGUAGE_CPP,
					MF_BYCOMMAND|MF_CHECKED);
				break;
			case 2:
				CheckMenuItem( hSubLangContextMenuPopUp, 
					TCPM_LANUGAGE_JAVA,
					MF_BYCOMMAND|MF_CHECKED);
				break;
			case 3:
				CheckMenuItem( hSubLangContextMenuPopUp, 
					TCPM_LANUGAGE_C_SHARP,
					MF_BYCOMMAND|MF_CHECKED);
				break;
			case 4:
				CheckMenuItem( hSubLangContextMenuPopUp, 
					TCPM_LANUGAGE_VISUAL_BASIC,
					MF_BYCOMMAND|MF_CHECKED);
				break;
			case -1:
				CheckMenuItem( hSubLangContextMenuPopUp, 
					TCPM_LANGUAGE_NONE,
					MF_BYCOMMAND|MF_CHECKED);
				break;
			}
			wPopUpCmd  = TrackPopupMenu(hContextMenuPopUp, TPM_LEFTALIGN | TPM_VERNEGANIMATION | TPM_RIGHTBUTTON ,
				ptCursorPoint.x, ptCursorPoint.y ,0, hWnd, 0);

			return false;
			break;
		}
		break;
	case WM_COMMAND:

		switch( HIWORD(wParam) )
		{
		
		case BN_CLICKED:
			switch(LOWORD(wParam))
			{
			case TCPM_LANGUAGE_C:
				//routine for LANGUAGE C Keystroke handling.

				//nLangSelectedIndex = 0
				//for marking the index and also marking on context menu.
				nLangSelectedIndex = 0;
				break;
			case TCPM_LANGUAGE_CPP:
				//routine for LANGUAGE C++ keystroke handling.
				
				//for marking the index and also marking on context menu.
				nLangSelectedIndex = 1;
				break;
			case TCPM_LANUGAGE_JAVA:
				//routine for  LANGUAGE JAVA keystroke handling.

				//for marking the index and also marking on context menu.
				nLangSelectedIndex = 2;
				break;
			case TCPM_LANUGAGE_C_SHARP:
				//routine for LANGUAGE C SHARP keystroke handling.

				//for marking the index and also marking on context menu.
				nLangSelectedIndex = 3;
				break;
			case TCPM_LANUGAGE_VISUAL_BASIC:
				//routine for LANGUAGE VB keystroke handling.

				//for marking the index and also marking on context menu.
				nLangSelectedIndex = 4;
				break;
			case TCPM_LANGUAGE_NONE:
				//routine for NONE LANGUAGE keystroke handling.

				//for marking the index and also marking on context menu.
				nLangSelectedIndex = -1;
				break;
			case TCPM_CONTEXTMENU_DISMISS:
				DestroyMenu( GetMenu(hWnd) );
				break;
			case TCPM_ABOUT_APPLICATION:
				DialogBox( GetWindowhandleInstance( hWnd), MAKEINTRESOURCE(IDD_ABOUT_APP), hWnd, (DLGPROC)AboutDialogProcedure);
				return false;
				break;
			case TCPM_APPLICATION_EXIT:
				SendMessage( hWnd, WM_CLOSE, 0, 0);
				return false;
				break;
			case TPCM_APPLICATION_RESTORE:
				ShowWindow(hWnd, SW_NORMAL);
				return false;
				break;
			case IDC_REFRESH_COM_BUTTON:
				PopulateCOMPort( hWnd, 0, 0, 0);
				return false;
				break;
			case COMMANDLINK_BUTTON_CONNECT_DISCONNECT:
				if( isConnected == false )
				{
					//sztCharStringOne
					LoadString( GetWindowhandleInstance( hWnd ), IDS_DISCONNECT_NOW_CAPTION, 
						sztCharStringOne, sizeof( sztCharStringOne )/sizeof( TCHAR ));
					SendDlgItemMessage( hWnd, COMMANDLINK_BUTTON_CONNECT_DISCONNECT, WM_SETTEXT, 0, (LPARAM) sztCharStringOne);
					LoadString( GetWindowhandleInstance( hWnd ), IDS_DISCONNECT_NOW_NOTE, 
						sztCharStringOne, sizeof( sztCharStringOne )/sizeof( TCHAR ));
					SendDlgItemMessage( hWnd, COMMANDLINK_BUTTON_CONNECT_DISCONNECT, BCM_SETNOTE, 0, (LPARAM) sztCharStringOne);

					hBitmapChecked = LoadBitmap( GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE( IDB_IS_CONNECTED ));
					SendDlgItemMessage( hWnd, IDC_PICTURE_SIGNAL_CONNECT, STM_SETIMAGE, 
						(WPARAM)IMAGE_BITMAP, (LPARAM) hBitmapChecked);
				
					hThread[0] = CreateThread( 
																	NULL,              // default security attributes
																	0,                 // use default stack size  
																	ReadExistingFromComPort,          // thread function 
																	NULL,             // argument to thread function 
																	0,                 // use default creation flags 
																	&dwThreadId[0]);   // returns the thread identifier of the communication thread.


					isConnected = true;
					return false;
				}
				if( isConnected == true )
				{
					LoadString( GetWindowhandleInstance( hWnd ), IDS_CONNECT_NOW_CAPTION, 
						sztCharStringOne, sizeof( sztCharStringOne )/sizeof( TCHAR ));
					SendDlgItemMessage( hWnd, COMMANDLINK_BUTTON_CONNECT_DISCONNECT, WM_SETTEXT, 0, (LPARAM) sztCharStringOne);
					LoadString( GetWindowhandleInstance( hWnd ), IDS_CONNECT_NOW_NOTE, 
						sztCharStringOne, sizeof( sztCharStringOne )/sizeof( TCHAR ));
					SendDlgItemMessage( hWnd, COMMANDLINK_BUTTON_CONNECT_DISCONNECT, BCM_SETNOTE, 0, (LPARAM) sztCharStringOne);
					
					hBitmapChecked = LoadBitmap( GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE( IDB_NOT_CONNECTED ));
					SendDlgItemMessage( hWnd, IDC_PICTURE_SIGNAL_CONNECT, STM_SETIMAGE, 
						(WPARAM)IMAGE_BITMAP, (LPARAM) hBitmapChecked);

					//kills the thread which communicates with keyboard.
					CloseHandle( hThread[0]);
					CloseHandle( hPortHandle );
									
					isConnected = false;
					return false;
				}
				return false;
				break;
			case COMMANDLINK_BUTTON_MINIMIZE:
				//routine for making tray icon, code goes here.
				ZeroMemory( &nidTrayIconInstance, sizeof( nidTrayIconInstance ));
				nidTrayIconInstance.cbSize = sizeof( nidTrayIconInstance );
				nidTrayIconInstance.uID	= APPLICATION_TRAYICON_CONTROL_ID;
				nidTrayIconInstance.hWnd = hWnd;
				nidTrayIconInstance.uFlags = NIF_ICON | NIF_MESSAGE | NIF_INFO | NIF_TIP;
				
				nidTrayIconInstance.hIcon = LoadIcon(GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE(IDI_APPICON));
				LoadString( GetWindowhandleInstance( hWnd ), IDS_TRAYICON_TOOLTIP_TEXT, 
					sztCharStringOne, sizeof( sztCharStringOne )/sizeof( TCHAR));
				wsprintf(nidTrayIconInstance.szInfoTitle,L"%s", sztCharStringOne);
				wsprintf(nidTrayIconInstance.szTip,L"%s", sztCharStringOne);

				LoadString( GetWindowhandleInstance( hWnd ), IDS_TRAYICON_MESSAGE_TEXT, 
					sztCharStringOne, sizeof( sztCharStringOne )/sizeof( TCHAR));
				wsprintf(nidTrayIconInstance.szInfo,L"%s", sztCharStringOne);

				nidTrayIconInstance.uTimeout = 10000;
				nidTrayIconInstance.dwInfoFlags = NIIF_USER;
				nidTrayIconInstance.uVersion = NOTIFYICON_VERSION_4;				
				nidTrayIconInstance.uCallbackMessage = APPLICATION_TRAYICON_CONTROL_MESSAGE;

				//now create Tray Icon by adding icon to notification area .
				//using Shell APIs
				Shell_NotifyIcon(NIM_ADD, &nidTrayIconInstance);
				ShowWindow(hWnd, SW_HIDE);
				
				return false;
				break;
			}
			break;
		}
		break;
		
	case WM_CLOSE:
	case WM_DESTROY:
		Shell_NotifyIcon( NIM_DELETE, &nidTrayIconInstance);
		DestroyWindow( hWnd );
		PostQuitMessage(0);
		break;
	}
	return false;
}
//defination of creating commandLink Button code goes here...
void WINAPI CreateCommandLinkButton( HWND hParentWnd, int x, int y, int nHeight, int nWidth, int nButtonType)
{
	TCHAR szButtonCaption[MAXLEN], szButtonNote[MAXLEN];
	HWND hwndCommandLink;
	if( nButtonType == 1)
	{
		hwndCommandLink = CreateWindow(
		L"BUTTON",  // Class; Unicode assumed.
		L"",        // Text will be defined later.
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_COMMANDLINK,  // Styles.
		x,         // x position. 
		y,         // y position. 
		nWidth,        // Button width.
		nHeight,        // Button height.
		hParentWnd,       // Parent window.
		(HMENU)COMMANDLINK_BUTTON_CONNECT_DISCONNECT,       
		GetWindowhandleInstance( hParentWnd ), 
		NULL);      // Pointer not needed.

		LoadString(GetWindowhandleInstance( hParentWnd ), IDS_CONNECT_NOW_CAPTION, szButtonCaption, sizeof( szButtonCaption )/sizeof(TCHAR));
		LoadString( GetWindowhandleInstance( hParentWnd), IDS_CONNECT_NOW_NOTE, szButtonNote, sizeof( szButtonNote )/ sizeof( TCHAR ));

		SendMessage(hwndCommandLink, WM_SETTEXT, 0, (LPARAM)szButtonCaption);
		SendMessage(hwndCommandLink, BCM_SETNOTE, 0, (LPARAM)szButtonNote);
	}
	else if( nButtonType == 2)
	{
		//creation of minimizing command button.
		hwndCommandLink = CreateWindow(
		L"BUTTON",  // Class; Unicode assumed.
		L"",        // Text will be defined later.
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_COMMANDLINK,  // Styles.
		x,         // x position. 
		y,         // y position. 
		nWidth,        // Button width.
		nHeight,        // Button height.
		hParentWnd,       // Parent window.
		(HMENU)COMMANDLINK_BUTTON_MINIMIZE,       
		GetWindowhandleInstance( hParentWnd ), 
		NULL);      // Pointer not needed.

		LoadString(GetWindowhandleInstance( hParentWnd ), IDS_MINIMIZEBUTTON_CAPTION, szButtonCaption, sizeof( szButtonCaption )/sizeof(TCHAR));
		LoadString( GetWindowhandleInstance( hParentWnd), IDS_MINIMIZEBUTTON_NOTE, szButtonNote, sizeof( szButtonNote )/ sizeof( TCHAR ));

		SendMessage(hwndCommandLink, WM_SETTEXT, 0, (LPARAM)szButtonCaption);
		SendMessage(hwndCommandLink, BCM_SETNOTE, 0, (LPARAM)szButtonNote);
	}

}

//defination of the PerformEssentials() code goes here...
void WINAPI PerformEssentials(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR szAppWord[MAXLEN];
	HICON hAppIcon_Big, hAppIcon_Small;
	HBITMAP hBmp;

	//loading string from resource
	LoadString(GetWindowhandleInstance(hWnd), IDS_APPWORD, szAppWord, sizeof(szAppWord)/sizeof(TCHAR));
	SetWindowText( hWnd, szAppWord);

	hAppIcon_Small = LoadIcon(GetWindowhandleInstance(hWnd), MAKEINTRESOURCE(IDI_APPICON));
	hAppIcon_Big = LoadIcon( GetWindowhandleInstance(hWnd), MAKEINTRESOURCE(IDI_APPICON));

	SendMessage( hWnd, WM_SETICON, ICON_SMALL, (LPARAM) hAppIcon_Small);
	SendMessage( hWnd, WM_SETICON, ICON_BIG, (LPARAM) hAppIcon_Big);

	//creation of commandLink Button for connecting and disconnecting the 
	//Programmer's Keyboard.
	CreateCommandLinkButton(hWnd, 145, 65, 75, 150, 1);
	//creation of minimizing commandLinkButton
	CreateCommandLinkButton(hWnd, 145, 165, 55, 175, 2);

	//initial painting of signal as picture, bmp from resource.
	hBmp = LoadBitmap( GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE( IDB_NOT_CONNECTED ));	
	SendMessage(GetDlgItem( hWnd, IDC_PICTURE_SIGNAL_CONNECT ), STM_SETIMAGE,  (WPARAM)IMAGE_BITMAP, (LPARAM)hBmp);	

	hBmp = LoadBitmap( GetWindowhandleInstance( hWnd ), MAKEINTRESOURCE( IDB_REFRESH_BITMAP ));
	SendDlgItemMessage( hWnd, IDC_REFRESH_COM_BUTTON, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM) hBmp);

	PopulateCOMPort(hWnd, uMsg, wParam, lParam);

	return;
}
void WINAPI PopulateCOMPort( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nComPortNumbers=255, nComCounter = 0;
	TCHAR szComNumber[MAXLEN];
	SendDlgItemMessage(hWnd, IDC_COMBO_COMLIST, CB_RESETCONTENT, 0, 0); 
	HANDLE hFIlehandle;
	for(int i=1;i<=nComPortNumbers;i++)
	{
		wsprintf(szComNumber,L"%s%d",L"COM",i);		
		hFIlehandle = CreateFile( szComNumber,GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if(SUCCEEDED(hFIlehandle))
		{
			CloseHandle( hFIlehandle );
			//here the list will be prepared of COM port.
			SendDlgItemMessage(hWnd, IDC_COMBO_COMLIST, CB_ADDSTRING, 0, (LPARAM) szComNumber); 
			nComCounter++;
		}
		else
		{
			CloseHandle( hFIlehandle );
		}
	}
	
	if(nComCounter == 0)
	{
		wsprintf(szComNumber,L"Not Found");
		
		SendDlgItemMessage(hWnd, IDC_COMBO_COMLIST, CB_ADDSTRING, 0, (LPARAM) szComNumber); 
		SendDlgItemMessage(hWnd, IDC_COMBO_COMLIST, CB_SETCURSEL ,(WPARAM) 0, NULL); 

		EnableWindow( GetDlgItem( hWnd, COMMANDLINK_BUTTON_CONNECT_DISCONNECT), false);
	}
	else
	{
		SendDlgItemMessage(hWnd, IDC_COMBO_COMLIST, CB_SETCURSEL ,(WPARAM) 0, NULL); 
		EnableWindow( GetDlgItem( hWnd, COMMANDLINK_BUTTON_CONNECT_DISCONNECT), true);
	}
}


//LRESULT WINAPI AboutDialogProcedure(HWND, UINT, WPARAM, LPARAM);
//About DialogBox Message handling Routine code goes here...
LRESULT WINAPI AboutDialogProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{	
	switch( uMsg )
	{
	
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return false;
		break;
	}
	return false;
}

//void WINAPI ReadExistingFromComPort( LPVOID );
//this is the threaded function which keeps on checking for any data is present in COM port or not?!
DWORD WINAPI WINAPI ReadExistingFromComPort( void * lpParameter)
{
	TCHAR szDataBuffer[MAXLEN], sztCharStringOne[MAXLEN];
	TCHAR szCharText[MAXLEN];
	DWORD nBytesRead;
	HANDLE hComPort;
	int nStore = 0;
	COMMTIMEOUTS timeouts;				//for setting the reading timeouts.
	DCB dcbConfig;										//to configure the 8250. as mentioned in Miscrosoft API Documentation.

	SendDlgItemMessage( gHandleWindow, IDC_COMBO_COMLIST, CB_GETLBTEXT, (WPARAM)0, (LPARAM)(LPSTR)szCharText);
	ZeroMemory( &timeouts, sizeof( COMMTIMEOUTS ));

	hComPort = CreateFile(szCharText ,GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
					if( hComPort == INVALID_HANDLE_VALUE )
					{
						TaskDialog(gHandleWindow,  GetWindowhandleInstance( gHandleWindow ), 
							MAKEINTRESOURCE(IDS_ERROR_WINDOWTITLE),
							MAKEINTRESOURCE(IDS_ERRORTITLE_CANNOTOPENPORT), 
							MAKEINTRESOURCE(IDS_ERRMSG), 
							TDCBF_OK_BUTTON ,
							MAKEINTRESOURCE( IDI_APPICON), 
							&nStore);
						return 0;
					}
					//DCB configuration setting code goes here...
					SecureZeroMemory( &dcbConfig, sizeof( DCB ));
					dcbConfig.DCBlength = sizeof( DCB );
					
					if(GetCommState( hComPort, &dcbConfig))
					{						
						dcbConfig.BaudRate = CBR_9600;
						dcbConfig.ByteSize = 8;
						dcbConfig.Parity	 = NOPARITY;
						dcbConfig.StopBits = ONESTOPBIT;
						/*dcbConfig.fBinary = TRUE;
						dcbConfig.fParity = TRUE;*/
						dcbConfig.fAbortOnError = TRUE;						
					}
					else
					{
						FormatMessage(
														FORMAT_MESSAGE_ALLOCATE_BUFFER | 
														FORMAT_MESSAGE_FROM_SYSTEM |
														FORMAT_MESSAGE_IGNORE_INSERTS,
														NULL,
														GetLastError(),
														MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
														(LPTSTR) &sztCharStringOne,
														0, NULL );
						TaskDialog(gHandleWindow,  GetWindowhandleInstance(gHandleWindow), 
							MAKEINTRESOURCE(IDS_ERROR_WINDOWTITLE),
							sztCharStringOne, 
							MAKEINTRESOURCE(IDS_ERRMSG), 
							TDCBF_OK_BUTTON ,
							MAKEINTRESOURCE( IDI_APPICON), 
							&nStore);
						return 0;
					}


					//setting the communication setting.					
					if(!SetCommState( hComPort, &dcbConfig ) )
					{
						FormatMessage(
														FORMAT_MESSAGE_ALLOCATE_BUFFER | 
														FORMAT_MESSAGE_FROM_SYSTEM |
														FORMAT_MESSAGE_IGNORE_INSERTS,
														NULL,
														GetLastError(),
														MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
														(LPTSTR) &sztCharStringOne,
														0, NULL );
						TaskDialog(gHandleWindow,  GetWindowhandleInstance( gHandleWindow ), 
							MAKEINTRESOURCE(IDS_ERROR_WINDOWTITLE),
							sztCharStringOne, 
							MAKEINTRESOURCE(IDS_ERRMSG), 
							TDCBF_OK_BUTTON ,
							MAKEINTRESOURCE( IDI_APPICON), 
							&nStore);
						return 0;

					}				
					timeouts.ReadIntervalTimeout = 1;
					timeouts.ReadTotalTimeoutMultiplier = 1;
					timeouts.ReadTotalTimeoutConstant = 1;
					timeouts.WriteTotalTimeoutMultiplier = 1;
					timeouts.WriteTotalTimeoutConstant = 1;
					if (!SetCommTimeouts(hComPort, &timeouts))
					{
						FormatMessage(
														FORMAT_MESSAGE_ALLOCATE_BUFFER | 
														FORMAT_MESSAGE_FROM_SYSTEM |
														FORMAT_MESSAGE_IGNORE_INSERTS,
														NULL,
														GetLastError(),
														MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
														(LPTSTR) &sztCharStringOne,
														0, NULL );
						TaskDialog(gHandleWindow,  GetWindowhandleInstance( gHandleWindow ), 
							MAKEINTRESOURCE(IDS_ERROR_WINDOWTITLE),
							sztCharStringOne, 
							MAKEINTRESOURCE(IDS_ERRMSG), 
							TDCBF_OK_BUTTON ,
							MAKEINTRESOURCE( IDI_APPICON), 
							&nStore);
						return 0;
					}
					
				hPortHandle = hComPort;
				while( 1 )	//an endless loop...
					{
						// Attempt a synchronous read operation.
						ZeroMemory( &szDataBuffer, sizeof( szDataBuffer )/sizeof(TCHAR));
						ReadFile(hComPort,   &szDataBuffer,  1,   &nBytesRead,   NULL) ; 
						 if( nBytesRead != 0 )
						 {
							 SendMessage(gHandleWindow , DATA_RECEIVED_FROM_COMPORT_NOW, (WPARAM)gHandleWindow, (LPARAM)szDataBuffer );
						 }
					}
	return 0;
}

DWORD WINAPI RegulateButtonSendSnippet( HWND hWnd, LPARAM lParam, int nLangId)
{

	switch( nLangId )
	{
	case -1:
		//not Specified...
		FillForNotSpecified( lParam);
		break;
	case 1:
		// C language
		FillForCLanguage();
		break;
	case 2:
		//C++ Lang.
		break;
	case 3:
		//JavaLang.
		break;
	case 4:
		//C# Lang.
		break;
	case 5:
		//VB . NET
		break;
	}
	return 0;

}


DWORD WINAPI FillForNotSpecified(  LPARAM lParam)
{
	WCHAR szWStr[ONEKILO];		
	wsprintf( szWStr, L"%s", (LPSTR)lParam);

	if( szWStr[0] == 'A' )
	{			
		//if-else statement button.
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"if(test condition){E}{{}{E}{T}//your code goes here{E}{}}{E}else{E}{{}{E}{T}//else body code goes here...{E}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'B' )
	{
		//your code goes here...
		//if-else if-else.
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"if(test condition){E}{{}{E}{T}//your code goes here{E}{}}{E}else if(test condition){E}{{}{E}{T}//else-if  body code goes here...{E}{}}{E}else{E}{{}{E}{T}//else body goes here...{E}{}}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'C' )
	{
		//your code goes here...
		//switch
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}switch(<var>){E}{{}{E}{T}case <case>:{E}//body goes here...{E}break;{E}default:{E}//body goes here...{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'D' )
	{
		//your code goes here...
		//while loop
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}while( < condition > ){E}{{}{E}{T}//loop body code goes here...{E}//<increment or decrement code line goes inside the body.{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'E' )
	{
		//your code goes here...
		//do loop
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}do{E}{{}{T}//body goes here...{E}//increment or decrement statement goes here, inside the body.{E}{B}{}}while(<test condition>);{E}{E}");		
		SendData( szWStr );
	}
	else if( szWStr[0] == 'F' )
	{
		//your code goes here...
		//for loop
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}for( int i = 0;{T}//initialization{E}i <> <condition>;{T}//test condition{E}i++{T}\\increment or decrement.{E}){E}{{}{T}//body of loop goes here...{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'G' )
	{
		//your code goes here...
		//entry point main block code ...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}int main( char args[]){E}{{}{E}{T}//entry point body code goes here...{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'H' )
	{
		//your code goes here...
		//structure code bock...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}typedef struct <structTagName>{E}{{}{E}{T}<data type> <var name>;{E}{T}<data type> <var name>{E}{}}<structure variable>;{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'I' )
	{
		//your code goes here...
		//union code bock...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}union <unionName>{E}{{}{E}{T}<data type> <variable name>;{E}{}}<union variable>;{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'J' )
	{
		//your code goes here...
		//enum code bock...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}enum <enumDataType>{E}{{}{E}{T} var1, {E}var2, {E}var3{E}{}} <enumVariable>;{E}");
		SendData( szWStr );
	}
	return 0;
}
DWORD WINAPI FillForCLanguage( TCHAR )
{
	WCHAR szWStr[ONEKILO];		
	wsprintf( szWStr, L"%s", (LPSTR)lParam);

	if( szWStr[0] == 'A' )
	{			
		//if-else statement button.
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"if(test condition){E}{{}{E}{T}//your code goes here{E}{}}{E}else{E}{{}{E}{T}//else body code goes here...{E}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'B' )
	{
		//your code goes here...
		//if-else if-else.
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"if(test condition){E}{{}{E}{T}//your code goes here{E}{}}{E}else if(test condition){E}{{}{E}{T}//else-if  body code goes here...{E}{}}{E}else{E}{{}{E}{T}//else body goes here...{E}{}}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'C' )
	{
		//your code goes here...
		//switch
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}switch(<var>){E}{{}{E}{T}case <case>:{E}//body goes here...{E}break;{E}default:{E}//body goes here...{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'D' )
	{
		//your code goes here...
		//while loop
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}while( < condition > ){E}{{}{E}{T}//loop body code goes here...{E}//<increment or decrement code line goes inside the body.{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'E' )
	{
		//your code goes here...
		//do loop
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}do{E}{{}{T}//body goes here...{E}//increment or decrement statement goes here, inside the body.{E}{B}{}}while(<test condition>);{E}{E}");		
		SendData( szWStr );
	}
	else if( szWStr[0] == 'F' )
	{
		//your code goes here...
		//for loop
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}for( int i = 0;{T}//initialization{E}i <> <condition>;{T}//test condition{E}i++{T}\\increment or decrement.{E}){E}{{}{T}//body of loop goes here...{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'G' )
	{
		//your code goes here...
		//entry point main block code ...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}int main( char args[]){E}{{}{E}{T}//entry point body code goes here...{E}{B}{}}{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'H' )
	{
		//your code goes here...
		//structure code bock...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}typedef struct <structTagName>{E}{{}{E}{T}<data type> <var name>;{E}{T}<data type> <var name>{E}{}}<structure variable>;{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'I' )
	{
		//your code goes here...
		//union code bock...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}union <unionName>{E}{{}{E}{T}<data type> <variable name>;{E}{}}<union variable>;{E}");
		SendData( szWStr );
	}
	else if( szWStr[0] == 'J' )
	{
		//your code goes here...
		//enum code bock...
		ZeroMemory( &szWStr, sizeof( szWStr )/sizeof(WCHAR));
		wsprintf( szWStr, L"{E}enum <enumDataType>{E}{{}{E}{T} var1, {E}var2, {E}var3{E}{}} <enumVariable>;{E}");
		SendData( szWStr );
	}
	return 0;
}
//DWORD WINAPI FillForCPPLanguage( TCHAR );
//DWORD WINAPI FillForJavaLanguage( TCHAR );
//DWORD WINAPI FillForCSharpLanguage( TCHAR );
//DWORD WINAPI FillForVisualBasicLanguage( TCHAR );

DWORD WINAPI SendData(WCHAR szData[ONEKILO])
{
	int szLen = 0;
	for( int i = 0; szData[i] != NULL; i ++)
		szLen ++;

	for( int i = 0; i< szLen ; i ++)
	{		
		if( (int)szData[i] == 32)
		{
			HitSpaceKey();
			continue;
		}
		else if( szData[i] == '{')
		{
			if(szData[i+1] == 'E')
			{
				//enter hit		
				HitEnterKey();
				i = i+2;
				continue;
			}
			else if( szData[i] == 'B')
			{
				//hit backspace
				hitBackSpace();
				i = i +2;
				continue;
			}
			else if( szData[i+1] == 'T')
			{
				//tab hit
				HitTabKey();
				i = i + 2;
				continue;
			}
			else if( szData[i+1] == '{')
			{
				i = i + 2;
				SendKeyData('{');
				continue;
			}
			else if( szData[i+1] == '}')
			{
				i = i + 2;
				SendKeyData('}');
				continue;
			}
		}
		else
		{
			SendKeyData((char)szData[i]);
		}
	}
	return 0;
}
DWORD WINAPI SendKeyData( char kValue)
{
	INPUT inputValue[2];
	INPUT inputCapsVal[2];
    memset( inputValue, 0, sizeof( INPUT ));
	memset( inputCapsVal, 0, sizeof( INPUT));	

	inputValue[0].type = inputValue[1].type = inputCapsVal[0].type = inputCapsVal[1].type= INPUT_KEYBOARD;	
	if( (int)kValue >=97 && ((int) kValue) <=122 )
	{
		//for CAPS characters.
		
		inputCapsVal[0].ki.wVk = ((int) kValue ) - 32;
		inputCapsVal[1].ki.wVk = ((int) kValue ) - 32;
		inputCapsVal[1].ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput( 2, inputCapsVal, sizeof( INPUT));
		
		return 0;
	}
	else if( (int)kValue >=65 && (int)kValue <=90 )
	{
		PressShiftKey();
		inputValue[0].ki.wVk = ((int) kValue );
		inputValue[1].ki.wVk = (int) kValue;
		inputValue[1].ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(2, inputValue, sizeof( INPUT) );
		ReleaseShiftKey();
		return 0;
	}
	else
	{
		//characters oftenly used here.
		// {, }, (, ). /
		
		if( (int)kValue == (int)'{')
		{
			PressShiftKey();			
			inputValue[0].ki.wVk =  inputValue[1].ki.wVk = 219;
			inputValue[1].ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(2, inputValue, sizeof( INPUT) );
			ReleaseShiftKey();
			return 0;
		}
		else if( (int)kValue == (int)'}')
		{
			PressShiftKey();
			inputValue[0].ki.wVk =	inputValue[1].ki.wVk = 221;
			inputValue[1].ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(2, inputValue, sizeof( INPUT) );
			ReleaseShiftKey();
			return 0;
		}
		else if( (int)kValue == (int)'(' )
		{
			PressShiftKey();
			inputValue[0].ki.wVk = inputValue[1].ki.wVk = 57;
			inputValue[1].ki.dwFlags = KEYEVENTF_KEYUP ;
			SendInput(2, inputValue, sizeof( INPUT) );
			ReleaseShiftKey();
			return 0;
		}
		else if( (int)kValue == (int)')' )
		{
			PressShiftKey();
			inputValue[0].ki.wVk =	inputValue[1].ki.wVk = 48;
			inputValue[1].ki.dwFlags = KEYEVENTF_KEYUP ;
			SendInput(2, inputValue, sizeof( INPUT) );
			ReleaseShiftKey();
			return 0;
		}
		else if( (int)kValue == (int)'/' )
		{
			inputValue[0].ki.wVk = inputValue[1].ki.wVk = VK_DIVIDE;
			inputValue[1].ki.dwFlags = KEYEVENTF_KEYUP ;
			SendInput(2, inputValue, sizeof( INPUT) );
			return 0;
		}
		return 0;
	}
	
	return 0;
}

DWORD WINAPI PressShiftKey()
{
	INPUT input;
	memset( &input, 0, sizeof(INPUT));
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = VK_SHIFT;
	SendInput( 1, &input, sizeof(INPUT));
	return 0;
}
DWORD WINAPI ReleaseShiftKey()
{
	INPUT input;
	memset( &input, 0, sizeof(INPUT));
	input.type = INPUT_KEYBOARD;
	input.ki.dwFlags	 = KEYEVENTF_KEYUP;
	input.ki.wVk = VK_SHIFT;
	SendInput( 1, &input, sizeof(INPUT));
	return 0;
}
DWORD WINAPI HitEnterKey()
{
	INPUT inpt[2];
	memset( &inpt, 0, sizeof( INPUT));
	inpt[0].type = inpt[1].type = INPUT_KEYBOARD;
	inpt[0].ki.wVk = inpt[1].ki.wVk = VK_RETURN;
	inpt[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput( 2, inpt, sizeof( INPUT ));
	return 0;
}
DWORD WINAPI HitTabKey()
	{
	INPUT inpt[2];
	memset( &inpt, 0, sizeof( INPUT));
	inpt[0].type = inpt[1].type = INPUT_KEYBOARD;
	inpt[0].ki.wVk = inpt[1].ki.wVk = VK_TAB;
	inpt[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput( 2, inpt, sizeof( INPUT ));
	return 0;
}
DWORD WINAPI HitSpaceKey()
{
	INPUT inpt[2];
	memset( &inpt, 0, sizeof( INPUT));
	inpt[0].type = inpt[1].type = INPUT_KEYBOARD;
	inpt[0].ki.wVk = inpt[1].ki.wVk = VK_SPACE;
	inpt[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput( 2, inpt, sizeof( INPUT ));
	return 0;
}
DWORD WINAPI hitBackSpace()
{
	INPUT inpt[2];
	memset( &inpt, 0, sizeof( INPUT));
	inpt[0].type = inpt[1].type = INPUT_KEYBOARD;
	inpt[0].ki.wVk = inpt[1].ki.wVk = VK_BACK;
	inpt[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput( 2, inpt, sizeof( INPUT ));
	return 0;
}