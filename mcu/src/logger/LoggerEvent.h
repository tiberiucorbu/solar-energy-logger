#ifndef _LOGGER_QUEUE_
#define _LOGGER_QUEUE_

#include "Arduino.h"

struct LoggerEvent
{
  char eventType;
  time_t timestamp;
  char *data;
  int size;
};

#endif
