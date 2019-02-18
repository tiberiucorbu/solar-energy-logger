#ifndef _LOGGER_TASK_
#define _LOGGER_TASK_

#include "LoggerTaskParameters.h"
#include "LoggerEvent.h"
#include "LoggerEntry.h"
static void loggerTask(void *pvParameters)
{
  LoggerTaskParameters *params = (LoggerTaskParameters *)pvParameters;
  LoggerEvent event;
  LoggerEntry entry;
  ESP_LOGI(TAG, "Start logger task");
  while (true)
  {
    ESP_LOGI(TAG, "Logger wating for queue event");
    xQueueReceive(params->loggerQueue, &event, portMAX_DELAY);
    ESP_LOGI(TAG, "Recieved log event %d", event.timestamp);
    entry.timestamp = event.timestamp;
    entry.data = event.data;
    entry.size = event.size;
    entry.category = event.eventType;
    params->logger->store(&entry);
    vTaskDelay(50 / portTICK_RATE_MS);
  }
}
#endif
