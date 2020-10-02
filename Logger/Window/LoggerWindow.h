#pragma once
#include "windows.h"

LRESULT CALLBACK loggerProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

class LoggerWindow {
public:
	LoggerWindow();
	LoggerWindow(const LoggerWindow&);
	void CloseWindow();
	void CreateObjects();
	void AddMenus(HWND hwnd);
	~LoggerWindow();
	HWND Objs[9];
	HWND m_hwnd;
private:
	HINSTANCE hinstance = NULL;
	LPWSTR WindowName = L"Logger";
	LPWSTR ICON = L"";
	LPCWSTR TITLE = L"Logger";
	int WIDTH = 400;
	int HEIGHT = 800;
	
	
	void CreateLoggerWindow();
};