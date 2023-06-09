#pragma once
#include <core.h>
#include <string_view>

#include <fstream>
#include <filesystem>
#include <sys/stat.h>

#ifdef LLGE_LINUX

#define LLGE_FILE_MANIPULATION_STD_BACKEND

#else

//#define LLGE_FILE_MANIPULATION_STD_BACKEND
#define LLGE_FILE_MANIPULATION_WINDOWS_BACKEND

#endif




#pragma region define guard
#if defined(LLGE_FILE_MANIPULATION_STD_BACKEND) && defined(LLGE_FILE_MANIPULATION_WINDOWS_BACKEND)
	#error "Usage of multiple backends if forbidden."
#endif
#pragma endregion

namespace LLGE
{
namespace fileManipulation
{
	const char *getBackendName();

	std::filesystem::path get_game_path();

	size_t getFileSize(std::string_view name);
	size_t readEntireFileBinary(std::string_view name, void *buffer, size_t s, size_t from = 0);

	//an empty buffer or null s will clear the file;
	bool writeEntireFileBinary(std::string_view name, void *buffer, size_t s);

	bool appendToFileBinary(std::string_view name, void *buffer, size_t s);
	bool appendToFileBinary(std::string_view name, std::string_view append);

	bool deleteFile(std::string_view path);
	bool createFile(std::string_view path);
}; 
};