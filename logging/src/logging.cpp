#include <iostream>
#include <cstdarg>

#include <logging.h>
#include <fileManipulation.h>

#if defined(LLGE_WINDOWS)
#include <Windows.h>
#endif

namespace LLGE
{
	namespace Logging
	{
        Logger::Logger(std::string name)
        {
            loggerName = name;
        }

		void Logger::internalInit()
		{
			//clear file

			//todo (LowLevelGameDev vlod): a fucntion to create the path if it doesn't exist
			fileManipulation::writeEntireFileBinary(logFilePath, 0, 0);

            alreadyInitialized = true;
		}

#if defined(LLGE_WINDOWS)
        void Logger::logSeverityColor(const LogSeverity severity)
        {
            int color = 0;

            switch (severity)
            {
                case LogSeverity::LOG_INFO:
                color = 0xF;
                break;

                case LogSeverity::LOG_WARNING:
                color = 0xE;
                break;

                case LogSeverity::LOG_ERROR:
                color = 0xC;
                break;

                case LogSeverity::LOG_FATAL:
                color = 0x4;
                break;

                case LogSeverity::LOG_NOT_IMPLEMENTED:
                color = 0x8;
                break;

                default:
                color = 0xF;
                break;
            }

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, color);
        }
#elif
        void Logger::logSeverityColor(const LogSeverity severity)
        {
            //todo (AveryOcean avery): implement for other platforms
        }
#else
        void Logger::logSeverityColor(const LogSeverity severity) { }
#endif

        std::string Logger::constructLogPrefix(const LogSeverity severity)
        {
            // Get current time
            time_t now = time(0);

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

			std::string severity_string = severityToString(severity);
            std::string prefix =
                    Logger::constructLogPrefix(severity);

            logSeverityColor(LogSeverity::LOG_INFO);
            std::cout << prefix;

            std::stringstream ss;
            ss << message << '\n';

            logSeverityColor(severity);
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
	};
};
