#include "pch.h"

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

SYSTEMTIME GetSystemTime() {

	SYSTEMTIME SystemTime;
	FILETIME LocalTime;
	FILETIME FileTimeStamp;
	GetSystemTimeAsFileTime(&FileTimeStamp);
	FileTimeToLocalFileTime(&FileTimeStamp, &LocalTime);
	FileTimeToSystemTime(&LocalTime, &SystemTime);

	return SystemTime;
}

DLL_PORTING void LogToConsole(int messageType, const char* MessageFrom, const char* Message)
{
	int Text_Color = LOG_BRIGHTWHITE;

	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SYSTEMTIME SystemTime = GetSystemTime();

	SetConsoleTextAttribute(hConsole, LOG_BRIGHTWHITE);
	cout << "[";
	cout << setw(2) << setfill('0') << SystemTime.wHour << ":";
	cout << setw(2) << setfill('0') << SystemTime.wMinute << ":";
	cout << setw(2) << setfill('0') << SystemTime.wSecond;
	cout << "] ";

	SetConsoleTextAttribute(hConsole, LOG_LIGHTGREEN);
	cout << "FROM : ";
	SetConsoleTextAttribute(hConsole, LOG_BRIGHTWHITE);
	cout << MessageFrom;
	
	string MsgType;
	switch (messageType) {
	case 0: {
		MsgType = "INFORMATION ";
		Text_Color = LOG_BRIGHTWHITE;
		break;
	}
	case 1: {
		MsgType = "WARNING     ";
		Text_Color = LOG_LIGHTRED;
		break;
	}
	case 2: {
		MsgType = "TRACE       ";
		Text_Color = LOG_LIGHTAQUA;
		break;
	}
	case 3: {
		MsgType = "EVENT       ";
		Text_Color = LOG_LIGHTBLUE;
		break;
	}
	default:
		break;
	}

	SetConsoleTextAttribute(hConsole, LOG_LIGHTGREEN);
	cout << " : TYPE : ";
	SetConsoleTextAttribute(hConsole, Text_Color);
	cout << MsgType;
	SetConsoleTextAttribute(hConsole, LOG_LIGHTGREEN);
	cout << " : MESSAGE : ";
	SetConsoleTextAttribute(hConsole, Text_Color);
	cout << Message << endl;
	SetConsoleTextAttribute(hConsole, LOG_BRIGHTWHITE);
}

DLL_PORTING void LogToFile(bool Console, int messageType, const char* MessageFrom, const char* Message) {
	const int bufferSize = MAX_PATH;
	char oldDir[bufferSize];
	GetCurrentDirectory(bufferSize, oldDir);

	if (_chdir("Logs")) {
		if (_mkdir("Logs")) {
		}
	}

	// create file and write

	SetCurrentDirectory(oldDir);

	if (Console) {
		LogToConsole(messageType, MessageFrom, Message);
	}
}




