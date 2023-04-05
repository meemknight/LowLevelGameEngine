#include <iostream>
#include <logging.h>
#include <window.h>

using namespace LLGE::Logging;

int main()
{

	LLGE::Window::load(); //load backend library

	LLGE::Window::Window window;
	window.create(100, 100, "test");

	Logger logger("LLGE Runtime");
	logger.logInfo("Welcome to LowLevelGameEngine (LLGE)!");
	logger.log(LogSeverity::LOG_ERROR, "Test");


	bool running = 1;
	while (running)
	{
		// TODO: Add Keyboard Events (such as closing the Window on ESC-Press)
		window.update(0);
	}

	std::cin.get();
	return 0;


}