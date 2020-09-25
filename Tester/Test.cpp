
#include "Imports.h"

int main() {
	LogToConsole(LOG_WARN, "TESTER", "TEST");
	LogToConsole(LOG_INFO, "TESTER", "TEST");
	LogToConsole(LOG_TRACE, "TESTER", "TEST");
	LogToConsole(LOG_EVENT, "TESTER", "TEST");
	LogToFile(true, LOG_INFO, "TESTER", "TEST");

	system("pause");
	return 0;
}





