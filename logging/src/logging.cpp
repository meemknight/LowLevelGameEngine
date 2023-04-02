#include <iostream>
#include <cstdarg>

#include <logging.h>
#include <fileManipulation.h>

namespace LLGE
{
	namespace Logging
	{
	

		void Logger::internalInit()
		{
			//clear file

			//todo (LowLevelGameDev vlod): a fucntion to create the path if it doesn't exist
			fileManipulation::writeEntireFileBinary(logFilePath, 0, 0);
		}


		std::string Logger::severityToString(const LogSeverity severity)
		{
			switch (severity)
			{
				case LogSeverity::LOG_INFO:
				return "INFO";

				case LogSeverity::LOG_WARNING:
				return "WARNING";

				case LogSeverity::LOG_ERROR:
				return "ERROR";

				case LogSeverity::LOG_FATAL:
				return "FATAL";

				case LogSeverity::LOG_NOT_IMPLEMENTED:
				return "NOT IMPLEMENTED";

				default:
				return "UNKNOWN";
			}
		}

		void Logger::logStd(const LogSeverity severity, const char *message, ...)
		{
			va_list args;

			va_start(args, message);

			std::string severity_string = severityToString(severity);
			std::string message_string = severity_string + ": " + message + "\n";

			vprintf(message_string.c_str(), args);
			va_end(args);
		}

		void Logger::logFile(const LogSeverity severity, const char *message, ...)
		{
			
			if (!alreadyInitialized)
			{
				internalInit();
				alreadyInitialized = true;
			}

			va_list args;

			va_start(args, message);

			char buffer[1024];

			std::string severity_string = severityToString(severity);
			std::string message_string = severity_string + ": " + message + "\n";

			vsprintf_s(buffer, sizeof(buffer), message_string.c_str(), args);

			const char *log_path = logFilePath.c_str();
			::LLGE::fileManipulation::appendToFileBinary(log_path, buffer, strlen(buffer));

			va_end(args);
		}

		void Logger::log(const LogSeverity severity, const char *message, ...)
		{
			va_list args;

			va_start(args, message);

			char buffer[1024];
			vsprintf_s(buffer, sizeof(buffer), message, args);

			logStd(severity, buffer);
			logFile(severity, buffer);

			va_end(args);
		}
	};
};
