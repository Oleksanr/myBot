#include "TextBox.h"
#include <fstream>

static void FaliWrite(char *var)
{
	std::ofstream result;
	result.open("F:/result.txt");
	result << var;
	result.close();
}

TextBox::TextBox(HWND hParent, int control_id) : Control(hParent, control_id)
{
	txt = NULL;
}
TextBox::~TextBox(void)
{
	if (txt)
	{
		delete(txt);
	}
}

char* TextBox::GetText()
{
	if (txt)
	{
		delete(txt);
		txt = NULL;
	}

	int len = SendMessage(m_hWnd, EM_LINELENGTH, 0, 0);
	if (len)
	{
		txt = new char[len + 1];
		txt[len] = 0;

		SendMessage(m_hWnd, EM_GETLINE, 0, (LPARAM)txt);

		return txt;
	}

	return "";
}

char* TextBox::GetMultiText()
{
	if (txt)
	{
		delete(txt);
		txt = NULL;
	}

	int count = SendMessage(m_hWnd, EM_GETLINECOUNT, 0, 0);
	if (count)
	{
		int len = count;
		for (int i = 0; i < count; i++)
		{
			len += SendMessage(m_hWnd, EM_LINELENGTH, SendMessage(m_hWnd, EM_LINEINDEX, i, 0), 0);
		}

		txt = new char[len + 10];
		txt[len] = 0;
		GetWindowText(m_hWnd, (LPTSTR)txt, (len+10));
		FaliWrite(txt);
		/*for (int i = 0; i < count; i++)
		{
			int currentLen = SendMessage(m_hWnd, EM_LINELENGTH, SendMessage(m_hWnd, EM_LINEINDEX, i, 0), 0);
			
			SendMessage(m_hWnd, LB_GETTEXT, i, (LPARAM)txt);
			
			 GetWindowText(m_hWnd, (LPTSTR) txt,len);
			txt[currentLen] = '\n';
			

			txt += currentLen + 1;
		}
		*/
		txt -= len;
		return txt;
	}
	return "";
}

void TextBox::SetText(char* text) { SendMessage(m_hWnd, WM_SETTEXT, 0, (LPARAM)text); }
void TextBox::AppendText(char* text)
{
	DWORD startPos, endPos = 0;
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&startPos, (LPARAM)&endPos);

	int outLenght = GetWindowTextLength(m_hWnd);
	SendMessage(m_hWnd, EM_SETSEL, outLenght, outLenght);

	SendMessage(m_hWnd, EM_REPLACESEL, TRUE, (LPARAM)text);

	SendMessage(m_hWnd, EM_SETSEL, startPos, endPos);
}
