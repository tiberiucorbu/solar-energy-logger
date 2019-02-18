#ifndef _MAIN_H_
#define _MAIN_H_
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SPIFFS.h>

#include "time/SyncTime.h"
#include "time/SyncTimeTask.h"
#include "logger/LoggerTask.h"
#include "display/Display.h"
#include "network/NetworkEvents.h"
#include "network/NetworkAutoConnectTask.h"
#include "network/Network.h"
#include "logger/Logger.h"

#include "sensor/CurrentSensor.h"
#include "sensor/CurrentSensorReadings.h"
#include "sensor/CurrentSensorReadingsTask.h"

#include "attachedHardware/clock.h"
#include "attachedHardware/currentSensor.h"
#include "attachedHardware/sdCard.h"

#include <Preferences.h>

#endif
