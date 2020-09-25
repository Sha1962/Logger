#pragma once 
#include "PlatformDetection.h"
#include <memory>

#define LOG_INFO		0
#define LOG_WARN		1
#define LOG_TRACE		2
#define LOG_EVENT		3

#define LOG_BLACK		0
#define LOG_BLUE		1
#define LOG_GREEN		2
#define LOG_AQUA		3
#define LOG_RED			4
#define LOG_PURPLE		5
#define LOG_YELLOW		6
#define LOG_WHITE		7
#define LOG_GRAY		8
#define LOG_LIGHTBLUE	9
#define LOG_LIGHTGREEN	10
#define LOG_LIGHTAQUA	11
#define LOG_LIGHTRED	12
#define LOG_LIGHTPURPLE	13
#define LOG_LIGHTYELLOW	14
#define LOG_BRIGHTWHITE	15


#ifdef PLATFORM_WINDOWS

	#ifdef BUILD_DLL
	#define DLL_PORTING __declspec(dllexport)
	#else
	#define DLL_PORTING __declspec(dllimport)
	#endif

#endif

DLL_PORTING void LogToFile(bool Console, int messageType, const char* MessageFrom, const char* Message);
DLL_PORTING void LogToConsole(int messageType, const char* MessageFrom, const char* Message);