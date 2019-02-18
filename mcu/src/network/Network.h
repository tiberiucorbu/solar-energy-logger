#ifndef _NETWORK_H_
#define _NETWORK_H_
  #include "WiFi.h"
  class Network {
    public:
      void connect();
      void disconnect();
      int searchKnownNetworks();
    private:
      boolean isNetworkKnown(String i);
  };

#endif
