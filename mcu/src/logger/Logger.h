#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <FS.h>
#include "./LoggerEntry.h"
#include "./LoggerParameters.h"
using namespace fs;

class Logger
{
  public:
    Logger(LoggerParameters *loggerParameters);
    void store(LoggerEntry *entry);

  private:
   LoggerParameters * parameters;
   
    void computeFileName(char *filename, int category);
};

#endif