#ifndef _CURRENT_SENSOR_READINGS_H_
#define _CURRENT_SENSOR_READINGS_H_
  struct CurrentSensorReadings {
    float shuntvoltage;
    float busvoltage;
    float current_mA ;
    float loadvoltage;
    float power_mW;
  };
#endif
