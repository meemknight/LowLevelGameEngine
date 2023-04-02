#include <iostream>
#include <cstdarg>

#include <logging.h>

namespace LLGE
{
    namespace Logging
    {
        Logger::Logger()
        {
            init();
        }

        void Logger::init()
        {
            char *buffer = "-- LOG FILE --\n";
            fileManipulation::writeEntireFileBinary(log_file_path(), buffer, strlen(buffer));
        }

        void Logger::cleanup() { }

        std::string Logger::log_file_path() const
        {
            return "log.txt";
        }

        std::string Logger::severity_to_string(const LogSeverity severity) const
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

                default:
                return "UNKNOWN";
            }
        }

        void Logger::log_std(const LogSeverity severity, const char *message, ...) const
        {
            va_list args;

            va_start(args, message);

            std::string severity_string = severity_to_string(severity);
            std::string message_string = severity_string + ": " + message + "\n";

            vprintf(message_string.c_str(), args);
            va_end(args);
        }

        static void Logger::log_file(const LogSeverity severity, const char *message, ...)
        {
            va_list args;

            va_start(args, message);

            char buffer[1024];

            std::string severity_string = severity_to_string(severity);
            std::string message_string = severity_string + ": " + message + "\n";

            vsprintf(buffer, message_string.c_str(), args);

            const char *log_path = log_file_path().c_str();
            fileManipulation::appendToFileBinary(log_path, buffer, strlen(buffer));

            va_end(args);
        }

        void Logger::log(const LogSeverity severity, const char *message, ...) const
        {
            va_list args;

            va_start(args, message);

            char buffer[1024];
            vsprintf(buffer, message, args);

            log_std(severity, buffer);
            log_file(severity, buffer);

            va_end(args);
        }
    };
};