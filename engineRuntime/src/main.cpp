#include <iostream>
#include <logging.h>
#include <window.h>
#include <conio.h>
#include "../../math/include/llm.h"



using namespace LLGE::Logging;

int main()
{
	
	
	bool running;

	LLGE::Window::load(); //load backend library

	LLGE::Window::Window window;
	window.create(100, 100, "test");


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