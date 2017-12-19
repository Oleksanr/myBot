#pragma once
#include <Windows.h>
#include "Control.h"

class TextBox
	: public Control
{
public:
	TextBox(HWND hParent, int control_id);
	~TextBox(void);

	char* GetText();
	char* GetMultiText();
	void SetText(char* text);
	void AppendText(char* text);
private:
	char* txt;
};

