
#include "Imports.h"

int main() {
	Logger* logger;
	logger = new Logger;

	logger->LogToConsole(LOG_WARN, "TESTER", "TEST");
	logger->LogToConsole(LOG_INFO, "TESTER", "TEST");
	logger->LogToConsole(LOG_TRACE, "TESTER", "TEST");
	logger->LogToConsole(LOG_EVENT, "TESTER", "TEST");
	logger->LogToFile(true, LOG_INFO, "TESTER", "TEST");

	system("pause");

	delete logger;
	logger = 0;
	return 0;
}





