#include "SyncTime.h"

SyncTime::SyncTime(SyncTimeConfiguration * c, RealTimeClock * r) {
  config = c;
  externalClock=r;
}

void SyncTime::syncTimeFromExternalClock(){
  if (hasExternalRtc()){
    // Unpack date and set it back
    HardwareDateTime now = externalClock->GetDateTime();
    LocalTime tm;
    tm.tm_year = now.Year();
    tm.tm_mon = now.Month();
    tm.tm_mday = now.Day();
    tm.tm_hour = now.Hour();
    tm.tm_min = now.Minute();
    tm.tm_sec = now.Second();

    time_t t = mktime(&tm);
    struct timeval timeofday = { .tv_sec = t };
    ESP_LOGI(TAG, "Setting time from external clock: %s", asctime(&tm));
    settimeofday(&timeofday, NULL);
  } else {
    ESP_LOGI(TAG, "External clock not found");
  }
}

boolean SyncTime::isTimeConfigured(){
  struct tm timeinfo;
  return getLocalTime(&timeinfo);
}

void SyncTime::syncFromNetworkTime() {
    configTime(config->gmtOffset_sec, config->daylightOffset_sec, config->ntpServer);
    uint8_t retry;
    while(!isTimeConfigured() && ++retry < 10) {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d)", retry);
        delay(2000);
    }
    if(isTimeConfigured()){
      setRtcTimeFromSystemTime();
    }
}

void SyncTime::setRtcTimeFromSystemTime(){
  struct tm localTime;
  if (getLocalTime(&localTime)) {
    HardwareDateTime adjustDateTime = HardwareDateTime(localTime.tm_year, localTime.tm_mon, localTime.tm_mday, localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    externalClock->SetDateTime(adjustDateTime);
  }
}

boolean SyncTime::hasExternalRtc(){
  Wire.beginTransmission(HARDWARE_CLOCK_WIRE_ADDRESS);
  byte error = Wire.endTransmission();
  return error == 0;
}
