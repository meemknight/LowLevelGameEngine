#include <iostream>
#include <moduleExample.h>
#include <window.h>

int main()
{

	LLGE::Window::load(); //load backend library
		
	LLGE::Window::Window window;
	window.create(0, 0, "");

	while (true)
	{
		window.update(0);
	}

	std::cout << "Hello from the Low Level Game Dev Comunity\n";

	std::cin.get();
	return 0;


}