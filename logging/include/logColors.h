#pragma once

#include <core.h>
#include <logSeverity.h>

#if defined(LLGE_WINDOWS)
    #include <windows.h>
#endif

namespace LLGE::Logging
{
    void logSeverityColor(const LogSeverity severity);
}