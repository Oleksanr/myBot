#pragma once
#pragma once
#include <Windows.h>

class Control
{
public:
	Control(HWND hParent, int control_id);
	virtual ~Control(void);

	void SetFont(HFONT hFont);
	HFONT GetFont();
	RECT GetPositionRect();

	HWND getHandle();
	HWND getParent();
	int getID();
protected:
	HWND m_hWnd;
	HWND m_hParent;
	int m_id;
};

