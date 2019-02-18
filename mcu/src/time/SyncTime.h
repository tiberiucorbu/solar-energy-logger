#ifndef _SYNC_TIME_H_
#define _SYNC_TIME_H_

#include <Arduino.h>
#include <time.h>
#include <sys/time.h>
#include "SyncTimeConfiguration.h"
#include "../attachedHardware/clock.h"

#define NTP_SERVER "time1.google.com"
#define TZ_INFO "WEST-1DWEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00" // Western European Time

  class SyncTime {
    public:
      SyncTime(SyncTimeConfiguration * configuration, RealTimeClock * realTimeClock);
      boolean isTimeConfigured();
      void syncFromNetworkTime();
      boolean hasExternalRtc();
      void syncTimeFromExternalClock();
      void setRtcTimeFromSystemTime();
    private:
      SyncTimeConfiguration * config;
      String TAG = "SyncTime";
      RealTimeClock * externalClock;
  };

#endif
