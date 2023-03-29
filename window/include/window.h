#pragma once
#include <core.h>

#define LLGE_GLFW_BACKEND
//#define LLGE_WINDOWS_BACKEND

#pragma region define guard
#if defined(LLGE_GLFW_BACKEND) && defined(LLGE_WINDOWS_BACKEND)
#error "you can't use multiple backends'
#endif
#pragma endregion

#pragma region internal

#ifdef LLGE_GLFW_BACKEND
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

#ifdef LLGE_WINDOWS_BACKEND
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace LLGE
{
	namespace Window
	{

		struct Internal
		{
			;
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
		bool create();
		
		bool update(float deltaTime);

		bool close();

		Input input;

		WindowState state;


		//different per api so don't acces it outside the class
		Internal internal; 

	};


	




	

}; 
};




