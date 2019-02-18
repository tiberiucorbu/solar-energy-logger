#ifndef _LOGGER_ENTRY_
#define _LOGGER_ENTRY_

#include <Arduino.h>

struct LoggerEntry
{
    char category;
    time_t timestamp;
    char *data;
    int size;
};

#endif