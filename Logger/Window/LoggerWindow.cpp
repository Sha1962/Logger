#include "LoggerWindow.h"

void LoggerWindow::CreateLoggerWindow()
{
	hinstance = GetModuleHandle(L"Tester.exe");

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = loggerProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hinstance;
	wc.hIcon = (HICON)LoadImageW(NULL, ICON, IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WindowName;

	RegisterClassEx(&wc);

	int posX = (GetSystemMetrics(SM_CXSCREEN) - WIDTH);
	int posY = 5;

	int Style = WS_OVERLAPPED| WS_SYSMENU | WS_MINIMIZEBOX | WS_THICKFRAME;

	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		WindowName,
		TITLE,
		Style,
		posX,
		posY,
		WIDTH,
		HEIGHT,
		NULL,
		NULL,
		hinstance,
		NULL);

	ShowWindow(m_hwnd, SW_SHOW);
	//SetForegroundWindow(m_hwnd);
	//SetFocus(m_hwnd);
}

LoggerWindow::LoggerWindow()
{
	CreateLoggerWindow();
}

void LoggerWindow::CloseWindow()
{

	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	UnregisterClass(WindowName, hinstance);
	hinstance = NULL;

	return;
}

LoggerWindow::~LoggerWindow()
{
	CloseWindow();
}

LRESULT CALLBACK loggerProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam) {
	switch (umessage)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, umessage, wparam, lparam);
	}
	return 0;
}
