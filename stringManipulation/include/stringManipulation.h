#pragma once
#include <core.h>
#include <string>
#include <string_view>
#include <vector>

namespace LLGE
{
namespace stringManipulation
{

	//todo add other things that might be usefull

	//dest can be also source
	void removeCharacters(std::string_view source, char *dest, std::string_view charsToRemove, size_t destSize);


	//dest can be also source
	void toLower(std::string_view source, char *dest, size_t destSize);
	void toLower(std::string_view source, std::string &dest);

	//dest can be also source
	void toUpper(std::string_view source, char *dest, size_t destSize);
	void toUpper(std::string_view source, std::string &dest);

	//checks if char is in source, returns pozition or -1 if not found
	size_t findChar(std::string_view source, char c);

	//returns char coppied (will be at max size-1)
	size_t strlcpy(std::string_view source, char *dst, size_t size);


	std::vector<std::string> split(std::string_view source, char c);


}; 
};