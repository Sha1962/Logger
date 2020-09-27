#pragma once 
#include "PlatformDetection.h"
#include <memory>
#include "Defines.h"

#ifdef PLATFORM_WINDOWS

	#ifdef BUILD_DLL
	#define DLL_PORTING __declspec(dllexport)
	#else
	#define DLL_PORTING __declspec(dllimport)
	#endif

#endif

DLL_PORTING bool GetExit();
DLL_PORTING void LoggerInit();
DLL_PORTING void LogToConsole(int messageType, const char* MessageFrom, const char* Message);
DLL_PORTING void LogToFile(bool Console, int messageType, const char* MessageFrom, const char* Message);