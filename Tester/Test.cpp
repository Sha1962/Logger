
#include "Imports.h"


using namespace std;

int main() {
	MSG msg = { 0 };
	ZeroMemory(&msg, sizeof(msg));

	LoggerInit();
	LogToConsole(1, "TESTER", "TEST");
	
	while (!GetExit()) {
		
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}

	return 0;
}





