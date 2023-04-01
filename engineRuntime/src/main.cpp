#include <iostream>
#include <moduleExample.h>
#include <window.h>

int main()
{

	LLGE::ModuleExample::foo();
	LLGE::Window::Window window;
	window.create(100, 100, "test");

	std::cout << "Hello from the Low Level Game Dev Comunity\n";

	std::cin.get();
	return 0;

}