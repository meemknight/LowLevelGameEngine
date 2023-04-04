#pragma once

#include <core.h>
#include <fileManipulation.h>
#include <logSeverity.h>
#include <logColors.h>

// C++ SPECIFIC
#include <sstream>

namespace LLGE
{
	namespace Logging
	{
		struct Logger
		{
			Logger(std::string name);

			//the logger will keep some state internally and will print some stuff to files so we want to only pass it by refference (have one instance to a file)
			Logger() = delete;
			Logger(Logger &other) = delete;
			Logger(Logger &&other) = delete;
			Logger operator=(Logger &other) = delete;
			Logger operator=(Logger &&other) = delete;

			std::string logFilePath = LLGE_RESOURCES_PATH "/logs.txt";
			static std::string severityToString(const LogSeverity severity);

            std::string constructLogPrefix(const LogSeverity severity);

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
            std::string loggerName;
		};
	};
};