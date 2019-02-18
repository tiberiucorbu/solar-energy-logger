#ifndef _CURRENT_SENSOR_H_
#define _CURRENT_SENSOR_H_

#include <Arduino.h>
#include <Wire.h>
#include <time.h>
#include <sys/time.h>
#include "CurrentSensorConfiguration.h"
#include "CurrentSensorReadings.h"
#include "CurrentSensorReadingsQueue.h"
#include "../attachedHardware/currentSensor.h"
#include "../logger/LoggerEvent.h"

class CurrentSensor
{
public:
  CurrentSensor(CurrentSensorConfiguration *configuration, CurrentSensorDevice *currentSensorDevice);
  void initialize();
  void read();
  boolean testConnection();

private:
  CurrentSensorConfiguration *config;
  CurrentSensorDevice *device;
  void publishReadings(CurrentSensorReadings *readings);
};

#endif
