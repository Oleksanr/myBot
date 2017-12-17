#include "MainDlg.h"

#include <Windows.h>
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR     lpCmdLine, int nCmdShow)
{
	MSG msg;

	MainDlg* Main = new MainDlg(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL);
	Main->showDlg(SW_SHOW);

	while (FALSE != GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
