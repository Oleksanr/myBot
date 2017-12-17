#include "MainDlg.h"



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
	MessageBox(m_hWnd, "OnCreate called", "!!!", MB_OK);
}

LRESULT MainDlg::RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if (wParam == IDOK )
		{
			MessageBox(m_hWnd, "Buton is pushed!", "!!!", MB_OK);

		}
		break;
	}
	return DlgBox::RealDlgProc(hwnd,uMsg,wParam,lParam);
	
}