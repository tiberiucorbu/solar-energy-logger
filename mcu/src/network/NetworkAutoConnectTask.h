#ifndef _NETWORK_AUTO_CONNECT_TASK_
#define _NETWORK_AUTO_CONNECT_TASK_

  #include "Network.h"
  #include "NetworkEvents.h"
  #include "NetworkAutoConnectTaskParameters.h"

  static void networkAutoConnectTask(void * pvParameter){
    NetworkAutoConnectTaskParameters * params = (NetworkAutoConnectTaskParameters *) pvParameter;
    while(true) {
      Serial.println("NetworkAutoConnectTask loop");
      // Use external clock to sync the time
      // params->instance->syncTimeFromExternalClock();
      // NetworkEvent networkEvent;
      params->instance->searchKnownNetworks();
      // xQueueReceive(networkEvents, &networkEvent, portMAX_DELAY);

      // if (networkEvent.eventType == NETWORK_CONNECTED) {
      //     // params->instance->syn();
      // }
      vTaskDelay(60000 / portTICK_RATE_MS);
    }
  }

#endif
