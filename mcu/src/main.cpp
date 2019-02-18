#include "main.h"

SemaphoreHandle_t xWireSemaphore = NULL;
QueueHandle_t loggerQueue = xQueueCreate(1, sizeof(LoggerEvent));

static const char *TAG = "Main";

Preferences preferences;

CurrentSensorDevice currentSensorDevice = INA219();
CurrentSensorConfiguration currentSensorConfiguration = {
    loggerQueue};
CurrentSensor currentSensor(&currentSensorConfiguration, &currentSensorDevice);
CurrentSensorReadingsTaskParameters currentSensorReadingsTaskParameters = {
    &currentSensor
    // &xWireSemaphore // TODO:  because there are  multiple devices that work with the same wire, a semaphore is needed in order to sync them.
};

RealTimeClock rtc(Wire);
SyncTimeConfiguration syncTimeConfiguration = {
    "time1.google.com",
    3600, 3600};
SyncTime syncTime = SyncTime(&syncTimeConfiguration, &rtc);

SyncTimeTaskParameters syncTimeParameters = {
    &syncTime};

FS *fileSystem;

LoggerParameters loggerParameters = {
    fileSystem};

Logger logger = Logger(&loggerParameters);

LoggerTaskParameters loggerTaskParameters = {&logger, loggerQueue};

Network network;
NetworkAutoConnectTaskParameters networkAutoConnectParameters = {
    &network};
Display lcd;

void setup(void)
{
  currentSensorDevice.begin();
  Wire.begin();

  Serial.begin(115200);
  while (!Serial)
  {
    // will pause Zero, Leonardo, etc until serial console opens
    delay(1);
  }

  SPI.begin(SPI_CLOCK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN);

  if (isCardConnected(SPI, SD_CABLE_SELECT_PIN))
  {
    SD.begin(SD_CABLE_SELECT_PIN, SPI);
    fileSystem = &SD;
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    ESP_LOGV(TAG, "SD Card found, Available Space: %lluMB", cardSize);
  }
  if (SPIFFS.begin(true))
  {
    uint64_t partitionSize = SPIFFS.totalBytes() / (1024 * 1024);
    ESP_LOGV(TAG, "SPIFFS partition found, Available Space: %lluMB", partitionSize);
    if (fileSystem)
    {
      // move SPIFFS to card
    }
    else
    {
      fileSystem = &SPIFFS;
    }
  }

  loggerParameters.fileSystem = fileSystem;

  vSemaphoreCreateBinary(xWireSemaphore);

  // TODO use preferences in config - (de)serialize to/from JSON since it is easy to do so
  // preferences.begin("main", false);
  // preferences.end();

  delay(1000);
  // lcd.setup();

  currentSensor.initialize();

  xTaskCreate(&syncTimeTask, "syncTime", 4096, &syncTimeParameters, 10, NULL);

  xTaskCreate(&loggerTask, "logData", 4096, &loggerTaskParameters, 1, NULL);

  xTaskCreate(&networkAutoConnectTask, "networkAutoConnect", 4096, &networkAutoConnectParameters, 10, NULL);

  xTaskCreate(
      &currentSensorReadingsTask, "currentSensorReadingsTask", 4096, &currentSensorReadingsTaskParameters,
      1, NULL);
}

void loop()
{
  vTaskDelete(NULL);
}
