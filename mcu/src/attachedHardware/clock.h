#ifndef _CLOCK_H_
#define _CLOCK_H_

  #include <Wire.h> // must be included here so that Arduino library object file references work
  #include <RtcDS3231.h>
  #define HARDWARE_CLOCK_WIRE_ADDRESS 0x68
  typedef struct tm LocalTime;
  typedef RtcDS3231<TwoWire> RealTimeClock;
  typedef RtcDateTime HardwareDateTime;

#endif
