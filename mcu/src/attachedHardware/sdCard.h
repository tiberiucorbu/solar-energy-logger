#ifndef _SD_CARD_DEVICE_
#define _SD_CARD_DEVICE_

    #include <Arduino.h>
    #include <SD.h>

    #include "../pinMapping.h"

    boolean isCardConnected(SPIClass &spi, uint8_t pin) {
        if(!SD.begin(pin, SPI)){
            ESP_LOGV(TAG, "Card Mount Failed");
            return false;
        }
        
        uint8_t cardType = SD.cardType();

        if(cardType == CARD_NONE){
            ESP_LOGV(TAG, "No SD card attached");
            return false;
        }

        Serial.print("SD Card Type: ");
        if(cardType == CARD_MMC){
            ESP_LOGV(TAG, "MMC");
        } else if(cardType == CARD_SD){
            ESP_LOGV(TAG, "SDSC");
        } else if(cardType == CARD_SDHC){
            ESP_LOGV(TAG, "SDHC");
        } else {
            return false;
            ESP_LOGV(TAG, "UNKNOWN");
        }
        SD.end();
        return true;
        // fs = &SD;

    }

#endif