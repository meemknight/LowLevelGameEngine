#pragma once

#include <core.h>
#include <logSeverity.h>
#include <fileManipulation.h>
#include <logColors.h>


	// C++ SPECIFIC
#include <sstream>

namespace LLGE
{
	namespace Logging
	{

		struct Logger
		{
			Logger(std::string file);

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

			// shortcuts
			void logInfo(std::string_view message);
			void logWarning(std::string_view message);
			void logError(std::string_view message);
			void logFatal(std::string_view message);
			void logNotImplemented(std::string_view message);

			void internalInit();
			bool alreadyInitialized = 0;
			std::string loggerName;
		};

		Logger &defaultLogger();

		//prints to the console using colours
		void printColoured(std::string_view message, LogSeverity severity = LogSeverity::LOG_INFO);

	};
};