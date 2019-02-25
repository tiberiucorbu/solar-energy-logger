#include "Network.h"

void Network::connect() {
    
}

void Network::disconnect(){
    WiFi.disconnect();
}

int Network::searchKnownNetworks() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  int n = WiFi.scanNetworks();
  if (n == 0) {
      ESP_LOGI(TAG, "no networks found");
  } else {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {
          if (isNetworkKnown(WiFi.SSID(i))){

          }
      }
  }
  WiFi.mode(WIFI_OFF);
}


boolean Network::isNetworkKnown(String i) {
  // config->preferences.getString()  i.equals()
  return false;
}
