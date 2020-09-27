#include "Logger.h"
using namespace std;

SYSTEMTIME GetSystemTime() {

	SYSTEMTIME SystemTime;
	FILETIME LocalTime;
	FILETIME FileTimeStamp;
	GetSystemTimeAsFileTime(&FileTimeStamp);
	FileTimeToLocalFileTime(&FileTimeStamp, &LocalTime);
	FileTimeToSystemTime(&LocalTime, &SystemTime);

	return SystemTime;
}

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::LogToConsole(int messageType, const char* MessageFrom, const char* Message)
{
	int Text_Color = LOG_BRIGHTWHITE;

	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SYSTEMTIME SystemTime = GetSystemTime();

	SetConsoleTextAttribute(hConsole, LOG_BRIGHTWHITE);
	cout << "[";
	cout << setw(2) << setfill('0') << SystemTime.wDay << "/";
	cout << setw(2) << setfill('0') << SystemTime.wMonth << "/";
	cout << setw(2) << setfill('0') << SystemTime.wYear;
	cout << "] ";

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

void Logger::LogToFile(bool Console, int messageType, const char* MessageFrom, const char* Message) {
	const int bufferSize = 520;
	WCHAR oldDir[bufferSize];
	GetCurrentDirectory(bufferSize, (LPWSTR)oldDir);

	if (_chdir("Logs")) {
		if (_mkdir("Logs")) {
		}
	}

	SetCurrentDirectory((LPWSTR)oldDir);

	ofstream LogFile;
	LogFile.open("Logs/Logger.log", ios::app);

	SYSTEMTIME SystemTime = GetSystemTime();

	LogFile << "[";
	LogFile << setw(2) << setfill('0') << SystemTime.wDay << "/";
	LogFile << setw(2) << setfill('0') << SystemTime.wMonth << "/";
	LogFile << setw(2) << setfill('0') << SystemTime.wYear;
	LogFile << "] ";

	LogFile << "[";
	LogFile << setw(2) << setfill('0') << SystemTime.wHour << ":";
	LogFile << setw(2) << setfill('0') << SystemTime.wMinute << ":";
	LogFile << setw(2) << setfill('0') << SystemTime.wSecond;
	LogFile << "] ";
	LogFile << "FROM : ";
	LogFile << MessageFrom;

	string MsgType;
	switch (messageType) {
	case 0: {
		MsgType = "INFORMATION ";
		break;
	}
	case 1: {
		MsgType = "WARNING     ";
		break;
	}
	case 2: {
		MsgType = "TRACE       ";
		break;
	}
	case 3: {
		MsgType = "EVENT       ";
		break;
	}
	default:
		break;
	}

	LogFile << " : TYPE : ";
	LogFile << MsgType;
	LogFile << " : MESSAGE : ";
	LogFile << Message << endl;
	LogFile.close();

	if (Console) {
		LogToConsole(messageType, MessageFrom, Message);
	}
}

void Logger::ShowWindow()
{
	if (!loggerWindow) {
		loggerWindow = new LoggerWindow;
	}
}

void Logger::CloseWindow()
{
	if (loggerWindow) {
		loggerWindow->CloseWindow();
		delete loggerWindow;
		loggerWindow = 0;
	}

}