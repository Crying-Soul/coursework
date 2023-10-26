#include <stdio.h>
#include <stdarg.h>

void logErr(const char *format, ...)
{
    va_list args;
    va_start(args, format);

#ifdef LOG_USE_COLOR
    printf("\033[1;33mError: \033[0m");
    printf("\033[1;31m");
    vprintf(format, args);
    printf("\033[0m");
#else
    printf("Error: ");
    vprintf(format, args);
    printf("\n");
#endif

    va_end(args);
}

void logInfo(const char *format, ...)
{
    va_list args;
    va_start(args, format);

#ifdef LOG_USE_COLOR
    printf("\033[92m");
    vprintf(format, args);
    printf("\033[0m\n");
#else
    vprintf(format, args);
    printf("\n");
#endif
    va_end(args);
}

void logWarn(const char *format, ...)
{
    va_list args;
    va_start(args, format);

#ifdef LOG_USE_COLOR
    printf("\033[1;33mError: \033[0m");
    printf("\033[38;5;214m");
    vprintf(format, args);
    printf("\033[0m\n");
#else
    printf("Warning: ");
    vprintf(format, args);
#endif

    va_end(args);
}
void logInfoDefault(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    vprintf(format, args);
    printf("\n");

    va_end(args);
}