#pragma once
#include "framework.h"
#include "Defines.h"
#include "LoggerWindow.h"



SYSTEMTIME GetSystemTime();

class Logger {
public:
	Logger();
	Logger(const Logger&) {};
	~Logger();
	void LogToConsole(int messageType, const char* MessageFrom, const char* Message);
	void LogToFile(bool Console, int messageType, const char* MessageFrom, const char* Message);
	void ShowWindow();
	void CloseWindow();

	bool ExitLogger = false;
private:
	LoggerWindow* loggerWindow = NULL;
};
