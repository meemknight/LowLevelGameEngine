#include <window.h>


#ifdef LLGE_WINDOWS_BACKEND


namespace LLGE
{
	namespace Window
	{


		bool load()
		{
			

			return true;
		}

		LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

		LRESULT CALLBACK windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
		{

			return DefWindowProc(wind, msg, wp, lp);
		}

		bool Window::create(uint16_t width, uint16_t height, std::string title)
		{
			close();

			auto INST = GetModuleHandle(0);

			//create window class
			const char *className = "llgdwnd";
			{
				WNDCLASS wc = {};

				wc.hCursor = LoadCursor(0, IDC_ARROW);
				wc.hInstance = INST;
				wc.lpszClassName = className;
				wc.lpfnWndProc = windProc;

				if (!RegisterClass(&wc))
				{
					return false;
				}

			}

			//create window
			{
				internal.wind = CreateWindow(className, "Hello from LLGE community", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					CW_USEDEFAULT, CW_USEDEFAULT,
					CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, INST, 0);
			
				if (!internal.wind)
				{
					return false;
				}


			}

			return true;
		}

		bool Window::update(float deltaTime)
		{


			MSG msg = {};
			while (PeekMessage(&msg, internal.wind, 0, 0, PM_REMOVE) > 0)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

			}

			return true;
		}

		//Todo this should return void
		bool Window::close()
		{
			return true;
		}


	};
};

#endif
