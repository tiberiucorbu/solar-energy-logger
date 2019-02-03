#ifndef _CURRENT_SENSOR_HARDWARE_H_
#define _CURRENT_SENSOR_HARDWARE_H_

  #include <Wire.h>
  #include <INA219.h>

  #define R_SHUNT 0.00375
  #define V_SHUNT_MAX 0.075
  #define V_BUS_MAX 16
  #define I_MAX_EXPECTED 20

  #define HARDWARE_CURRENT_SENSOR_ADDRESS 0x40
  typedef INA219 CurrentSensorDevice;


#endif
