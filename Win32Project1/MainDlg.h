#pragma once
#include"DlgBox.h"
#include"TextBox.h"
#include "resource.h"
class MainDlg: 
	public DlgBox
{
public:
	MainDlg(HINSTANCE hIstanc, LPCSTR dlgResName, HWND hwndParent);
	virtual ~MainDlg();
	void OnCreate();
	LRESULT RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam);
	TextBox* m_textbox;
};

