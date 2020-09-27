#include "LoggerWindow.h"

#define IDBut1 1
#define IDBut2 2

LRESULT CALLBACK InputProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK loggerProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam);

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
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WindowName;

	RegisterClassEx(&wc);

	int posX = 5;//(GetSystemMetrics(SM_CXSCREEN) - WIDTH);
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

	CreateObjects();

	ShowWindow(m_hwnd, SW_SHOW);
	UpdateWindow(m_hwnd);
}

LoggerWindow::LoggerWindow()
{
	CreateLoggerWindow();
}

LoggerWindow::LoggerWindow(const LoggerWindow&)
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

void LoggerWindow::CreateObjects() {

	Objs[0] = CreateWindowW(TEXT("button"),
							TEXT("Button 1"),        
							WS_VISIBLE | WS_CHILD,  
							10, 10,               
							105, 33,              
							m_hwnd,                   
							(HMENU)0, NULL, NULL);   

	Objs[1] = CreateWindowW(TEXT("button"),
							TEXT("Button 2"),
							WS_VISIBLE | WS_CHILD,
							10, 45,
							105, 33,
							m_hwnd,
							(HMENU)1, NULL, NULL);
}

LoggerWindow::~LoggerWindow()
{
	CloseWindow();
}


