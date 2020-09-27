#pragma once
#include <Windows.h>

LRESULT CALLBACK loggerProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

class LoggerWindow {
public:
	LoggerWindow();
	LoggerWindow(const LoggerWindow&) {};
	void CloseWindow();
	~LoggerWindow();

	HWND m_hwnd = NULL;
private:
	HINSTANCE hinstance = NULL;
	LPWSTR WindowName = L"Logger";
	LPWSTR ICON = L"";
	LPCWSTR TITLE = L"Logger";
	int WIDTH = 400;
	int HEIGHT = 800;

	void CreateLoggerWindow();
};