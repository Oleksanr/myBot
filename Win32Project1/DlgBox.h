#pragma once
#include <Windows.h>
#include "resource.h"
class DlgBox
{
public:
	DlgBox(HINSTANCE hIstanc, LPCSTR dlgResName, HWND hwndParent);	
	virtual ~DlgBox(void);
	void  showDlg(int nCmdShow);
private:
	virtual void OnCreate() = 0;
	void CreateDlg(HINSTANCE hIstanc, LPCSTR dlgResName, HWND parent);
	static LRESULT WINAPI StDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam);
protected:
	virtual LRESULT RealDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam);
	HWND m_hWnd;
};

