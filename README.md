# ESP SOLAR CHARGER Logger

A device that logs the solar panel output, playing with freertos while building a small tool

## Current development status 

SPIKE-ing

## Motivation

Logging the voltage and current output/input on the solar and the battery ends requires a lot of manual work, using traditional methods (a multimeter). So I started to build a dual chanel multimeter of voltage and current that stores at a certain tick the readings. Because we are in 2019 and wifi/ble MCU come in cheap 

---------- 

## Prototypes modules

- 1 x TTGO ESP32 Battery - a development board with an ESP32, a sd card slot, a battery charger and a joystick
- 2 x INA219 Module - a current and voltage sensor
- 1 x a real time clock


## Considering implementing

- BLE Interface
- TCP (MQTT) Interface

## Lessons Learned,

1. <strike> Wire lib is not working in tasks with low priority.</strike> because of #2.
2. CPP variables don't outlive the block scopes; that is why setup has a while(true) {noop();} at the end
3. QueueHandle_t is a pointer already, no nead to convert it to a pointer 
4. downside of INA219 is that you must connect a common ground with the MCU to measure the voltage (Hope I'm wrong)