#include "Display.h"
//
struct {

} Control;

struct Menu {
  String label;
  Menu * parent;
};

void Display::setup() {
  lcd.begin(16, 2); // initialize the lcd
  menu = 0;
  lcd.setBacklight(255);
}

void Display::loop() {
  lcd.home(); lcd.clear();
  lcd.printf("*** LINE. %d \n", menu);
  menu = (menu + 1) % 12;
}
boolean Display::testConnection() {
   Wire.beginTransmission(0x27);
   int err = Wire.endTransmission();
   return err = 0;
}
