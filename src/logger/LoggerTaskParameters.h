#ifndef _LOGGER_TASK_PARAMETERS_
#define _LOGGER_TASK_PARAMETERS_
  #include "Logger.h"

  struct LoggerTaskParameters {
     Logger * logger;
     QueueHandle_t loggerQueue;
  };

#endif
