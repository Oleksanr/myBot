#pragma once
#include"DlgBox.h"
class MainDlg: 
	public DlgBox
{
public:
	MainDlg(HINSTANCE hIstanc, LPCSTR dlgResName, HWND hwndParent);
	virtual ~MainDlg();
	void OnCreate();
	LRESULT RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam);
};

