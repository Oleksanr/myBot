#include "MainDlg.h"
#include <iostream>
#include <Shellapi.h>
#include <fstream>

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
	m_textbox1 = new TextBox(m_hWnd, IDC_EDIT2);

}

LRESULT MainDlg::RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if (wParam == IDOK)
		{
			m_textbox->SetText("* _ _ _ _ _ _ * _ _\r\n* _ _ * _ _ * _ _ _\r\n_ _ _ _ * _ _ _ _ _\r\n* * * _ _ _ _ * _ _\r\n* _ _ _ * * * _ _ _\r\n* _ * _ _ _ _ * * _\r\n_ _ _ _ _ _ _ _ _ *\r\n* _ * _ _ * _ _ _ *\r\n* _ _ _ _ _ _ _ _ *\r\n* _ _ _ _ _ _ _ _ *");

		}
		if (wParam == IDCANCEL)
		{
			exit(0);
		}
		if (wParam == IDC_BUTTON1)
		{
			char resultTex[210];
			std::ifstream result1;

				result1.open("rez.txt");
				int i = 0; 
					char ch;
			while (result1.get(ch))
				{
				if(ch == '\n')
				{
					resultTex[i] = '\r';
					i++;
				}
					resultTex[i] = ch;
					i++;
				}
			result1.close();
			m_textbox1->SetText(resultTex);
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
			CreateProcess(NULL, "ConsoleApplication1 10 10 F:/result.txt v.txt k.txt ", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
			
			
		}
		break;
	}
	return DlgBox::RealDlgProc(hwnd,uMsg,wParam,lParam);
	
}
