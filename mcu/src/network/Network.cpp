#include "Network.h"

void Network::connect() {

}

void Network::disconnect(){

}

int Network::searchKnownNetworks() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  int n = WiFi.scanNetworks();
  if (n == 0) {
      Serial.println("no networks found");
  } else {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {
          // Print SSID and RSSI for each network found
          Serial.print(i + 1);
          Serial.print(": ");
          Serial.print(WiFi.SSID(i));
          Serial.print(" (");
          Serial.print(WiFi.RSSI(i));
          Serial.print(")");
          Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
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
