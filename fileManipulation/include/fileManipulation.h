#pragma once
#include <core.h>
#include <string_view>

#include <fstream>
#include <filesystem>
#include <sys/stat.h>

#define LLGE_FILE_MANIPULATION_STD_BACKEND
//#define LLGE_FILE_MANIPULATION_WINDOWS_BACKEND

#pragma region define guard
#if defined(LLGE_FILE_MANIPULATION_STD_BACKEND) && defined(LLGE_FILE_MANIPULATION_WINDOWS_BACKEND)
	#error "Usage of multiple backends if forbidden."
#endif
#pragma endregion

namespace LLGE
{
namespace fileManipulation
{
	//try to reuse functions and not repeat yourself when writing this module

	//to open a file do this ---->  LLGE_RESOURCES_PATH "fileName.txt"  and put the file in the resource folder

	std::filesystem::path get_game_path();

	size_t getFileSize(std::string_view name);
	size_t readEntireFileBinary(std::string_view name, void *buffer, size_t s, size_t from = 0);

	bool writeEntireFileBinary(std::string_view name, void *buffer, size_t s);

	bool appendToFileBinary(std::string_view name, void *buffer, size_t s);
	bool appendToFileBinary(std::string_view name, std::string_view append);

	bool deleteFile(std::string_view path);
	bool createFile(std::string_view path);
}; 
};