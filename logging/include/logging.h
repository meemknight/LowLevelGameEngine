#pragma once
#include <core.h>
#include <fileManipulation.h>

namespace LLGE
{
	namespace Logging
	{
		enum class LogSeverity
		{
			LOG_INFO = 0,
			LOG_WARNING,
			LOG_ERROR,
			LOG_FATAL,
			LOG_NOT_IMPLEMENTED, //for functions that are not implemented yet so they should not be called
		};

		//todo (vlod lowLevelGameDev) add a global default log 

		struct Logger
		{
			Logger() {};

			//the logger will keep some state internally and will print some stuff to files so we want to only pass it by refference (have one instance to a file)
			Logger(Logger &other) = delete;
			Logger(Logger &&other) = delete;
			Logger operator=(Logger &other) = delete;
			Logger operator=(Logger &&other) = delete;

			std::string logFilePath = LLGE_RESOURCES_PATH "/logs.txt";
			std::string severityToString(const LogSeverity severity);


			void logStd(const LogSeverity severity, const char *message, ...);
			void logFile(const LogSeverity severity, const char *message, ...);

			void log(const LogSeverity severity, const char *message, ...);

			// Hardcoded Serverities
			void logInfo(const char *message, ...);
			void logWarning(const char *message, ...);
			void logError(const char *message, ...);
			void logFatal(const char *message, ...);
			void logNotImplemented(const char *message, ...);

			void internalInit();
			bool alreadyInitialized = 0;
		};




	};
};