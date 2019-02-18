#ifndef _NETWORK_EVENTS_
#define _NETWORK_EVENTS_

 #include "freertos/FreeRTOS.h"

 #define NETWORK_CONNECTED 1
 #define NETWORK_DISCONNECTED 2
 #define NETWORK_RECEIVED_IP 3

 struct NetworkEvent {
   char eventType;
 };

 QueueHandle_t networkEvents = xQueueCreate( 10, sizeof( NetworkEvent ) );

#endif
