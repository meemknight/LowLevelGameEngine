#include <iostream>
#include <logger.h>
#include <window.h>

int main()
{

	LLGE::Window::load(); //load backend library

	LLGE::Window::Window window;
	window.create(100, 100, "test");

    LLGE::Logger::init();
    LOG_STD_TRACE("Welcome to Low Level Game Engine (LLGE)!\n");

    LOG_FILE_TRACE("-- Low Level Game Engine (LLGE) LOGS --\n");
    LOG_FILE_TRACE("Welcome to Low Level Game Engine (LLGE)!\n");

    bool running = 1;
	while (running)
	{
        // TODO: Add Keyboard Events (such as closing the Window on ESC-Press)
		window.update(0);
	}

	std::cin.get();
	return 0;


}