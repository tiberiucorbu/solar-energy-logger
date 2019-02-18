#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(CurrentSensorConfiguration *configuration, CurrentSensorDevice *currentSensorDevice)
{
  config = configuration;
  device = currentSensorDevice;
}

void CurrentSensor::initialize()
{
  device->begin();
  //ESP_LOGI(TAG, "Initialized current sennsor device\n");
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  // currentSensorDevice->setCalibration_16V_400mA();
}

void CurrentSensor::read()
{
  CurrentSensorReadings readings;
  ESP_LOGI(TAG, "Start readings");
  if (device)
  {
    readings.busvoltage = device->busVoltage();
    readings.current_mA = device->shuntCurrent();
    readings.power_mW = device->busPower();
    readings.loadvoltage = readings.busvoltage + (readings.shuntvoltage / 1000);
    publishReadings(&readings);
  }
  else
  {
    ESP_LOGW(TAG, "For some reason the currentDevice instance is null");
  }
}

void CurrentSensor::publishReadings(CurrentSensorReadings *readings)
{
  if (config->loggerQueue)
  { // has to be initialized
    ESP_LOGI(TAG, "Sending messages");
    char data[100];
    sprintf(data, "%f, %f", readings->current_mA, readings->busvoltage);
    time_t t;
    time(&t);
    LoggerEvent event = {
        1,
        t,
        data,
        100};
    ESP_LOGI(TAG, "Sending messages: %s", event.data);
    xQueueSend(config->loggerQueue, &event, portMAX_DELAY);
  }
}

boolean CurrentSensor::testConnection()
{
  // ESP_LOGI(TAG, "Check hardware connection on address %#08x", HARDWARE_CURRENT_SENSOR_ADDRESS);
  Wire.beginTransmission(HARDWARE_CURRENT_SENSOR_ADDRESS);
  byte error = Wire.endTransmission();
  return error == 0;
}
