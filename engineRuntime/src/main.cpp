#include <iostream>
#include <logging.h>
#include <window.h>
#include <windows.h>
#include <conio.h>
#include "../../math/include/llm.h"
#include "../../logging/include/readyLogs.h"




using namespace LLGE::Logging;

int main()
{
{}{}
	bool running;

	LLGE::Window::load(); //load backend library

	LLGE::Window::Window window;
	LLGE::Window::Input input;
	LLGE::Window::Internal internal;

	window.create(100, 100, "llge");

	Logger logger("LLGE Runtime");
	// Explicit severity method:
	// logger.log(LogSeverity::LOG_INFO, "Welcome to LowLevelGameEngine (LLGE)!");

	// Shortcut method:
	logger.logInfo("Welcome to LowLevelGameEngine (LLGE)!");


	running = 1;

	if (running == 1) {

		while (running)
		{
#pragma region Editor Keyboard Input for Windows

			/*TODO: Add Keyboard Events in Windows (such as closing the Window on ESC-Press) */

										/*TODO; Log system: No log fix it */
			/* Working*/ if (input.WindowExit(VK_ESCAPE) !=true) { logger.logFatal(EXIT_INFO1); }

#pragma endregion

			
			window.update(0);
		}
	}

	else {
		logger.logError("Window not responding, running variables not worked.");
	}

	std::cin.get();
	return 0;


}