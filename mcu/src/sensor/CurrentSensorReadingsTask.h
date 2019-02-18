#ifndef _CURRENT_SENSOR_READINS_TASK_H_
#define _CURRENT_SENSOR_READINS_TASK_H_

#include "CurrentSensorReadingsTaskParameters.h"

static void currentSensorReadingsTask(void *pvParameters)
{
  CurrentSensorReadingsTaskParameters *params = (CurrentSensorReadingsTaskParameters *)pvParameters;
  ESP_LOGI(TAG, "Task started\n");
  CurrentSensor *instance = params->instance;
  while (true)
  {
    if (instance->testConnection())
    {
      instance->read();
      
    }
    else
    {
       ESP_LOGV(TAG, "Device not connected");
    }
    vTaskDelay(1000 / portTICK_RATE_MS);
  }
}
#endif
