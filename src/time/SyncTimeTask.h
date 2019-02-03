#ifndef _SYNC_TIME_TASK_
#define _SYNC_TIME_TASK_

  #include "SyncTimeTaskParameters.h"
  #include "SyncTime.h"
  #include "../network/NetworkEvents.h"

  static void syncTimeTask(void * pvParameter){
    SyncTimeTaskParameters * params = (SyncTimeTaskParameters *) pvParameter;

    while(true) {
      // Use external clock to sync the time
      Serial.println("SyncTimeTask loop");
      params->instance->syncTimeFromExternalClock();
      NetworkEvent networkEvent;
      xQueueReceive(networkEvents, &networkEvent, portMAX_DELAY);
      if (networkEvent.eventType == NETWORK_CONNECTED) {
          // params->instance->syn();
      }
      vTaskDelay(60000 / portTICK_RATE_MS);
    }
  }

#endif
