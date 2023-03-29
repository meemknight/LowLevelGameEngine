#include <window.h>
#include <iostream>

#ifdef LLGE_GLFW_BACKEND

namespace LLGE
{
	namespace Window
	{

		void glfw_error_callback(int id, const char* desc)
		{
			std::cout << "GLFW Error! ID: " << id << " DESCRIPTION: " << desc << "\n";
		}

		//glfw implementation

		bool load() 
		{
			glfwSetErrorCallback(glfw_error_callback);

			if (!glfwInit())
			{
				//TODO: Move initialization outside of create function
				//TODO: Move logging to some log module
				std::cout << "Failed to create GLFW window\n";
				glfwTerminate();
				return false;
			}

			return true;
		}

		bool Window::create(uint16_t width, uint16_t height, std::string title)
		{


			// TODO: Add support for different moniters
			GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			if (!window)
			{
				std::cout << "Failed to create GLFW window!\n";
				glfwTerminate();
				return false;
			}

			return true;
		}


	};
};

#endif