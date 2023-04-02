#pragma once
#include <core.h>
#include <string_view>
#include <unordered_set>

#define LLGE_LOG_TO_FILE
#define LLGE_LOG_TO_STD

//use namespaces
namespace LLGE
{
namespace logging
{


	struct LogManager
	{
		std::string fileName;

		bool firstLog = 0;

		//this will clear the last log file on the first log
		//make sure to create the folder and the files if they don't exist
		void log(std::string_view message, int type = 0, unsigned int id = 0);



	};

	void log(std::string_view message, int type = 0, unsigned int id = 0);


	void notImplementedAssert();

}; 
};