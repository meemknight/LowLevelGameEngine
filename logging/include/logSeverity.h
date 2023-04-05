#pragma once

namespace LLGE::Logging {
    enum class LogSeverity
    {
        LOG_INFO = 0, //todo replace this with log_default and add a log_info that has blue text, and also add log_ok with green text
        LOG_WARNING,
        LOG_ERROR,
        LOG_FATAL,
        LOG_NOT_IMPLEMENTED, //for functions that are not implemented yet so they should not be called
    };
}