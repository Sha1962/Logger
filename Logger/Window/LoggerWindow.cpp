#include "LoggerWindow.h"

#define IDM_MYMENURESOURCE   3

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

	Objs[0] = CreateWindowW(L"Button", 
							L"Button Group",
							WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
							5, 5, 
							117, 97, 
							m_hwnd, 
							(HMENU)0, hinstance, NULL);

	Objs[3] = CreateWindowW(WindowName,
							TEXT("Buttons"),
							WS_VISIBLE | WS_CHILD | WS_DLGFRAME ,
							130, 13,
							120, 91,
							m_hwnd,
							(HMENU)3, hinstance, NULL);

	Objs[1] = CreateWindowW(TEXT("button"),
							TEXT("Button 1"),        
							WS_VISIBLE | WS_CHILD | SS_NOTIFY,
							12, 27,               
							105, 33,              
							m_hwnd,
							(HMENU)1, hinstance, NULL);

	Objs[2] = CreateWindowW(TEXT("button"),
							TEXT("Button 2"),
							WS_VISIBLE | WS_CHILD | SS_NOTIFY,
							12, 65,
							105, 33,
							m_hwnd,
							(HMENU)2, hinstance, NULL);
	Objs[4] = CreateWindowW(TEXT("button"),
							TEXT("Button 3"),
							WS_VISIBLE | WS_CHILD | SS_NOTIFY,
							5, 11,
							105, 33,
							Objs[3],
							(HMENU)4, hinstance, NULL);

	Objs[5] = CreateWindowW(TEXT("button"),
							TEXT("Button 4"),
							WS_VISIBLE | WS_CHILD | SS_NOTIFY,
							5, 49,
							105, 33,
							Objs[3],
							(HMENU)5, hinstance, NULL);
	AddMenus(m_hwnd);
}

void LoggerWindow::AddMenus(HWND hwnd) {

	HMENU hMenubar;
	HMENU hMenu;

	hMenubar = CreateMenu();
	hMenu = CreateMenu();

	AppendMenuW(hMenu, MF_STRING, 6, L"&New");
	AppendMenuW(hMenu, MF_STRING, 7, L"&Open");
	AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenuW(hMenu, MF_STRING, 8, L"&Quit");

	AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR)hMenu, L"&File");
	SetMenu(hwnd, hMenubar);
}

LoggerWindow::~LoggerWindow()
{
	CloseWindow();
}


