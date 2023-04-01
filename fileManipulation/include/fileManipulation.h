#pragma once
#include <core.h>
#include <string_view>

//#define LLGE_FILE_MANIPULATION_STD_BACKEND
#define LLGE_FILE_MANIPULATION_WINDOWS_BACKEND

#pragma region define guard
#if defined(LLGE_FILE_MANIPULATION_STD_BACKEND) && defined(LLGE_FILE_MANIPULATION_WINDOWS_BACKEND)
#error "you can't use multiple backends'
#endif
#pragma endregion

#include <fstream>
#include <filesystem>
#include <sys/stat.h>

namespace LLGE
{
namespace fileManipulation
{
	//try to reuse functions and not repeat yourself when writing this module

	//to open a file do this ---->  LLGE_RESOURCES_PATH "fileName.txt"  and put the file in the resource folder

    std::string get_game_path();

	size_t getFileSize(std::string name);
	size_t readEntireFileBinary(std::string name, void *buffer, size_t s, size_t from = 0);

	bool writeEntireFileBinary(std::string name, void *buffer, size_t s);

	bool appendToFileBinary(std::string name, void *buffer, size_t s);
	bool appendToFileBinary(std::string name, std::string append);

	bool deleteFile(std::string path);
	bool createFile(std::string path);
}; 
};