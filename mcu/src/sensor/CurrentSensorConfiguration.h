#ifndef _CURRENT_SENSOR_CONFIG_
#define _CURRENT_SENSOR_CONFIG_

  #include "../attachedHardware/currentSensor.h"

  struct CurrentSensorConfiguration {
      QueueHandle_t loggerQueue;
  };

#endif
