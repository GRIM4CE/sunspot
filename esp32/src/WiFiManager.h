#ifndef WiFiManager_h
#define WiFiManager_h

#include <WiFi.h>

class WiFiManager {
public:
    static void connectToWiFi(const char* ssid, const char* password);
};

#endif
