#include <logColors.h>

namespace LLGE::Logging {
#if defined(LLGE_LINUX)

    #define RST "\x1B[0m"
    #define KINFO "\x1B[37m"
    #define KWARN "\x1B[33m"
    #define KERR "\x1B[91m"
    #define KFTL "\x1B[31m"
    #define KUNIMPL "\x1B[90m"

    #define COLOR(CLR, x) CLR x RST

    // TODO: Test this on Linux
    void logSeverityColor(const LogSeverity severity)
    {
        switch(severity)
        {
            case LogSeverity::LOG_INFO:
                std::cout << COLOR(KINFO, "");
                break;
            case LogSeverity::LOG_WARNING:
                std::cout << COLOR(KWARN, "");
                break;
            case LogSeverity::LOG_ERROR:
                std::cout << COLOR(KERR, "");
                break;
            case LogSeverity::LOG_FATAL:
                std::cout << COLOR(KFTL, "");
                break;
            case LogSeverity::LOG_NOT_IMPLEMENTED:
                std::cout << COLOR(KUNIMPL, "");
                break;
        }

    }

#elif defined(LLGE_WINDOWS)

    void logSeverityColor(const LogSeverity severity)
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

#endif
}