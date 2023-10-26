#ifndef LOGGING_H
#define LOGGING_H
void logErr(const char *format, ...);
void logWarn(const char *format, ...);
void logInfo(const char *format, ...);
void logInfoDefault(const char *format, ...);
#endif