#include "pch.h"
#include "Logger.h"
#include "Input.h"

#define DOWN input->IsKeyDown
#define VK_O 79
#define VK_C 67

using namespace std;

HINSTANCE dllInstance = NULL;

Logger* logger;
Input* input;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH:
			dllInstance = (HINSTANCE)hModule;
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

LRESULT CALLBACK loggerProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam) {
	PAINTSTRUCT ps;
	HDC hdc;
	switch (umessage)
	{ 
		case WM_COMMAND:
		{
			switch (HIWORD(wparam))
			{
			case BN_CLICKED:
			{
				switch (LOWORD(wparam))
				{
				case 1:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "BUTTON 1 CLICKED");
					break;
				}
				case 2:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "BUTTON 2 CLICKED");
					break;
				}
				case 4:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "BUTTON 3 CLICKED");
					break;
				}
				case 5:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "BUTTON 4 CLICKED");
					break;
				}
				case 6:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "NEW CLICKED");
					break;
				}
				case 7:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "OPEN CLICKED");
					break;
				}
				case 8:
				{
					logger->LogToFile(true, LOG_EVENT, "LOG WINDOW", "QUIT CLICKED");
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case WM_CLOSE:
			logger->LogToConsole(LOG_INFO, "LOGGER", "LOGGER WINDOW CLOSED");
			logger->CloseWindow();
			break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			// TODO: Add any drawing code here...
			EndPaint(hwnd, &ps);
			break;
		default:
			return DefWindowProc(hwnd, umessage, wparam, lparam);
	}
	return 0;
}

LRESULT CALLBACK InputProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
	switch (wParam)
	{
		case WM_KEYUP:
		case WM_SYSKEYUP:
		{
			input->KeyUp(p->vkCode);
			break;
		}
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		{
			input->KeyDown(p->vkCode);
			break;
		}
	}

	if (DOWN(VK_ESCAPE)) {
		logger->ExitLogger = true;
	}

	if ((DOWN(VK_LCONTROL)) && (DOWN(VK_O)) && (DOWN(VK_LMENU))) {
		logger->LogToConsole(LOG_INFO, "LOGGER", "LOGGER WINDOW OPENED");
		logger->ShowWindow();
	}

	if ((DOWN(VK_LCONTROL)) && (DOWN(VK_C)) && (DOWN(VK_LMENU))) {
		logger->LogToConsole(LOG_INFO, "LOGGER", "LOGGER WINDOW CLOSED");
		logger->CloseWindow();
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

DLL_PORTING void LoggerInit() {
	logger = new Logger;
	input = new Input(dllInstance);
}

DLL_PORTING void LogToConsole(int messageType, const char* MessageFrom, const char* Message) {
	if (logger) {
		logger->LogToConsole(messageType, MessageFrom, Message);
	}
	else {
		MessageBox(NULL, L"You need to Initialize Logger", L"Logger Error!", MB_OK);
	}
}

DLL_PORTING void LogToFile(bool Console, int messageType, const char* MessageFrom, const char* Message) {
	if (logger) {
		logger->LogToFile(Console, messageType, MessageFrom, Message);
	}
	else {
		MessageBox(NULL, L"You need to Initialize Logger", L"Logger Error!", MB_OK);
	}
}

DLL_PORTING bool GetExit() {
	if (logger) {
		return logger->ExitLogger;
	}
	return true;
}







