#include <iostream>
#include <cstdarg>
#include <utility>

#include <logging.h>
#include <fileManipulation.h>

namespace LLGE
{
	namespace Logging
	{
        Logger::Logger(std::string name)
        {
            loggerName = std::move(name);
        }

		void Logger::internalInit()
		{
			//clear file

			//todo (LowLevelGameDev vlod): a fucntion to create the path if it doesn't exist
			fileManipulation::writeEntireFileBinary(logFilePath, nullptr, 0);

            alreadyInitialized = true;
		}

        std::string Logger::constructLogPrefix(const LogSeverity severity)
        {
            // Get current time
            time_t now = time(nullptr);

            // Convert now to tm struct for local timezone
            tm *ltm = localtime(&now);

            // Convert time to string
            char time_str[128];
            sprintf(time_str, "%04d/%02d/%02d %02d:%02d:%02d",
                    1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

            std::string severity_string = severityToString(severity);

            std::stringstream ss;
            ss << "[" << time_str << "] " << severity_string << ", " << loggerName << ": ";

            return ss.str();
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

            logSeverityColor(severity);
			std::string severity_string = severityToString(severity);
            std::string prefix =
                    Logger::constructLogPrefix(severity);

            std::stringstream ss;
            ss << prefix << message << '\n';

			vprintf(ss.str().c_str(), args);
			va_end(args);
		}

		void Logger::logFile(const LogSeverity severity, const char *message, ...)
		{
			if (!alreadyInitialized)
			{
				internalInit();
			}

			va_list args;

			va_start(args, message);

			char buffer[1024];

			std::string severity_string = severityToString(severity);
            std::string prefix =
                    Logger::constructLogPrefix(severity);

            std::stringstream ss;
            ss << message << '\n';

			vsprintf_s(buffer, sizeof(buffer), ss.str().c_str(), args);

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

        #pragma region Shortcut Definitions

        void Logger::logInfo(std::string_view message)
        {
            log(LogSeverity::LOG_INFO, message.data());
        }

        void Logger::logWarning(std::string_view message)
        {
            log(LogSeverity::LOG_WARNING, message.data());
        }

        void Logger::logError(std::string_view message)
        {
            log(LogSeverity::LOG_ERROR, message.data());
        }

        void Logger::logFatal(std::string_view message)
        {
            log(LogSeverity::LOG_FATAL, message.data());
        }

        void Logger::logNotImplemented(std::string_view message)
        {
            log(LogSeverity::LOG_NOT_IMPLEMENTED, message.data());
        }

        #pragma endregion
    };
};
