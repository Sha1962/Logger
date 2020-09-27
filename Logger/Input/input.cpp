#include "input.h"

Input::Input(HINSTANCE dllInstance)
{
	this->hWndMain = dllInstance;
	ClearKeys();
	InstallKeyboardHook();
}

Input::Input(const Input&)
{
	ClearKeys();
	InstallKeyboardHook();
}

Input::~Input()
{
	if (hHook) {
		Removehook();
	}
}

bool  Input::InstallKeyboardHook()
{	
	HookProc = (HOOKPROC)InputProc;	
	hHook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProc, hWndMain, NULL);

	if (hHook)
		return TRUE;
	else
		return FALSE;
}

void  Input::Removehook()
{
	UnhookWindowsHookEx(hHook);
}

void Input::KeyDown(unsigned int input)
{
	m_keys[input] = true;
	return;
}

void Input::KeyUp(unsigned int input)
{
	m_keys[input] = false;
	return;
}

bool Input::IsKeyDown(unsigned int key)
{
	return m_keys[key];
}

void Input::ClearKeys()
{
	int i;

	for (i = 0; i < 256; i++)
	{
		m_keys[i] = false;
	}
	return;
}




