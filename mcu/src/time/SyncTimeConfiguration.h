#ifndef _SYNC_TIME_CONFIGURATION_
#define _SYNC_TIME_CONFIGURATION_
  #include <Arduino.h>

  #define NTP_SERVER "time1.google.com"
  #define TZ_INFO "WEST-1DWEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00" // Western European Time

  struct SyncTimeConfiguration {
    char * ntpServer;
    long  gmtOffset_sec;
    int   daylightOffset_sec;
  };

#endif