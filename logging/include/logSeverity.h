#pragma once

namespace LLGE::Logging {
    enum class LogSeverity
    {
        LOG_INFO = 0,
        LOG_WARNING,
        LOG_ERROR,
        LOG_FATAL,
        LOG_NOT_IMPLEMENTED, //for functions that are not implemented yet so they should not be called
    };
}