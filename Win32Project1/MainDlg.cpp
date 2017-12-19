#include "MainDlg.h"
#include <iostream>
#include <Shellapi.h>

MainDlg::MainDlg(HINSTANCE hIstanc, LPCSTR dlgResName, HWND hwndParent)
	:DlgBox(hIstanc,dlgResName,hwndParent)
{
	OnCreate();
}


MainDlg::~MainDlg(void)
{
}
void MainDlg::OnCreate()
{
	m_textbox = new TextBox(m_hWnd,IDNO);
}

LRESULT MainDlg::RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if (wParam == IDOK ||wParam== IDCANCEL)
		{
			MessageBox(m_hWnd, "Buton is pushed!", "!!!", MB_OK);
			m_textbox->SetText("* _ _ _ _ _ _ * _ _\r\n* _ _ * _ _ * _ _ _\r\n_ _ _ _ * _ _ _ _ _\r\n* * * _ _ _ _ * _ _\r\n* _ _ _ * * * _ _ _\r\n* _ * _ _ _ _ * * _\r\n_ _ _ _ _ _ _ _ _ *\r\n* _ * _ _ * _ _ _ *\r\n* _ _ _ _ _ _ _ _ *\r\n* _ _ _ _ _ _ _ _ *");

		
		}
		if (wParam== IDC_BUTTON2)
		{

			 m_textbox->GetMultiText();
			/*STARTUPINFO si = { sizeof(si) };
			PROCESS_INFORMATION pi;
			TCHAR czCommandLine[] = "cmd bb 10 10 src.txt v.txt";
			CreateProcess(NULL, czCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
			//bb 10 10 src.txt v.txt*/
			//system("bb 10 10 src.txt v.txt");
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(STARTUPINFO));
			//CreateProcess(NULL, "bbb 10 10 src.txt v.txt k.txt ", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
			Sleep(1500);
			
		}
		break;
	}
	return DlgBox::RealDlgProc(hwnd,uMsg,wParam,lParam);
	
}
