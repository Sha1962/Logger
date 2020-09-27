#pragma once
#include "windows.h"

LRESULT CALLBACK InputProc(int nCode, WPARAM wParam, LPARAM lParam);

class Input {
public:
	Input(HINSTANCE dllInstance);
	Input(const Input&);
	~Input();

	bool InstallKeyboardHook();
	void Removehook();
	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	bool IsKeyDown(unsigned int);
	void ClearKeys();
	bool KeyPressed = false;
	bool KeyRepeat = true;
private:
	bool m_keys[256];
	HOOKPROC HookProc = 0;
	HINSTANCE  hWndMain = 0;
	HHOOK hHook = 0;
};