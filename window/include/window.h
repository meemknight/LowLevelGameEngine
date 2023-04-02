#pragma once
#include <core.h>
#include <string>
#include <string_view>

//#define LLGE_WINDOW_GLFW_BACKEND
#define LLGE_WINDOW_WINDOWS_BACKEND

#pragma region define guard
#if defined(LLGE_WINDOW_GLFW_BACKEND) && defined(LLGE_WINDOW_WINDOWS_BACKEND)
#error "Usage of multiple backends if forbidden."
#endif
#pragma endregion

#pragma region internal

#ifdef LLGE_WINDOW_GLFW_BACKEND
#include <GLFW/glfw3.h>

namespace LLGE
{
namespace Window
{

	struct Internal
	{
		GLFWwindow *window;
	};

};
};


#endif

#ifdef LLGE_WINDOW_WINDOWS_BACKEND
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace LLGE
{
	namespace Window
	{

		struct Internal
		{
			HWND wind;
		};

	};
};


#endif

#pragma endregion


//use namespaces
namespace LLGE
{
namespace Window
{

	bool load();

	struct Button
	{
		bool pressed();
		bool released();
		bool held();
		bool doublePressed(); //maybe
		bool typed(); //maybe
	};

	struct Input
	{
		//hold all the buttons here

		//char[20] typedInput
	};

	struct WindowState
	{
		//position
	};

	struct Window
	{

		//api
		bool create(uint16_t width, uint16_t height, std::string title);
		
		bool update(float deltaTime);

		bool close();

		Input input;

		WindowState state;


		//different per api so don't acces it outside the class
		Internal internal; 

	};


	




	

}; 
};




