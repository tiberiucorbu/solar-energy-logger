#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
class Display {
  public:
    void setup();
    void loop();
    boolean testConnection();
    LiquidCrystal_PCF8574 lcd = LiquidCrystal_PCF8574(0x27);
  private:
    int menu = 1;
};

#endif
