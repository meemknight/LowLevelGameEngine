#pragma once
#include <core.h>
#include <fileManipulation.h>

#define LOG_INFO(...) LLGE::Logging::logger.log(LLGE::Logging::LogSeverity::LOG_INFO, __VA_ARGS__)
#define LOG_WARNING(...) LLGE::Logging::logger.log(LLGE::Logging::LogSeverity::LOG_WARNING, __VA_ARGS__)
#define LOG_ERROR(...) LLGE::Logging::logger.log(LLGE::Logging::LogSeverity::LOG_ERROR, __VA_ARGS__)
#define LOG_FATAL(...) LLGE::Logging::logger.log(LLGE::Logging::LogSeverity::LOG_FATAL, __VA_ARGS__)

namespace LLGE
{
    namespace Logging
    {
        enum class LogSeverity
        {
            LOG_INFO,
            LOG_WARNING,
            LOG_ERROR,
            LOG_FATAL,
        };

        struct Logger
        {
            Logger();

            std::string log_file_path = LLGE_RESOURCES_PATH "logs.txt";
            std::string severity_to_string(const LogSeverity severity) const;

            void init();

            void log_std(const LogSeverity severity, const char *message, ...) const;
            void log_file(const LogSeverity severity, const char *message, ...) const;

            void log(const LogSeverity severity, const char *message, ...) const;

            // Hardcoded Serverities
            void log_info(const char *message, ...) const;
            void log_warning(const char *message, ...) const;
            void log_error(const char *message, ...) const;
            void log_fatal(const char *message, ...) const;

            void cleanup();
        };
    };
};