
#include "Imports.h"


using namespace std;

int main() {
	MSG msg = { 0 };
	ZeroMemory(&msg, sizeof(msg));

	LoggerInit();
	LogToConsole(LOG_INFO, "TESTER", "CONSOLE TEST");
	LogToConsole(LOG_WARN, "TESTER", "CONSOLE TEST");
	LogToConsole(LOG_TRACE, "TESTER", "CONSOLE TEST");
	LogToConsole(LOG_EVENT, "TESTER", "CONSOLE TEST");
	LogToFile(true, LOG_INFO, "TESTER", "FILE TEST");
	LogToFile(true, LOG_WARN, "TESTER", "FILE TEST");
	LogToFile(true, LOG_TRACE, "TESTER", "FILE TEST");
	LogToFile(true, LOG_EVENT, "TESTER", "FILE TEST");

	while (!GetExit()) {
		
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}

	return 0;
}





