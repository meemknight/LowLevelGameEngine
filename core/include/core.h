#pragma once


#pragma region Platform

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(__NT__)
#define LLGE_WINDOWS 1
#elif defined(__linux__)
#define LLGE_LINUX 1
#else
#error "LLGE supports only windows and linux"
#endif

#if defined(LLGE_WINDOWS) && defined(LLGE_LINUX)
#error "Error, both window and linux platforms are defined"
#endif

#pragma endregion
