#include "DlgBox.h"



DlgBox::DlgBox(HINSTANCE hIstanc, LPCSTR dlgResName, HWND hwndParent)
{
	CreateDlg(hIstanc, dlgResName, hwndParent);
}


DlgBox::~DlgBox()
{
}

void  DlgBox::CreateDlg(HINSTANCE hIstanc, LPCSTR dlgResName, HWND parent)
{
	m_hWnd = CreateDialog(hIstanc, dlgResName, parent, (DLGPROC)StDlgProc);
	SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
}
LRESULT CALLBACK  DlgBox::StDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	DlgBox* pDlgBox = NULL;
	pDlgBox = (DlgBox*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	if (pDlgBox != NULL)
	{
		return pDlgBox->RealDlgProc(hwnd, uMsg, wParam, lParam);
	}
	
		return 0;
}
LRESULT DlgBox::RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_CLOSE:
		EndDialog(hwnd, wParam);
		PostQuitMessage(0);
		break;

	}
	return 0;
}

void DlgBox::showDlg(int nCmdShow) 
{
	ShowWindow(m_hWnd, nCmdShow);
}
