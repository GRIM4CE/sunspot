#include "WiFiManager.h"
#include <WiFi.h>
#include <Arduino.h>

void WiFiManager::connectToWiFi(const char* ssid, const char* password) {
  Serial.print("Attempting to connect to WiFi network, SSID: ");
  Serial.println(ssid);

  WiFi.setTxPower(WIFI_POWER_MINUS_1dBm);
  WiFi.begin(ssid, password);

  wl_status_t status = WiFi.status();

  // Attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    // Wait 10 seconds for connection:
    delay(10000);

    status = WiFi.status();

    if (status != WL_CONNECTED) {
      switch (status) {
        case WL_IDLE_STATUS:
          Serial.println("WiFi is in idle state.");
          break;
        case WL_NO_SSID_AVAIL:
          Serial.println("No SSID are available, WiFi cannot connect.");
          break;
        case WL_SCAN_COMPLETED:
          Serial.println("Scan networks is completed.");
          break;
        case WL_CONNECT_FAILED:
          Serial.println("Failed to connect to WiFi network.");
          break;
        case WL_CONNECTION_LOST:
          Serial.println("Connection to WiFi network is lost.");
          break;
        case WL_DISCONNECTED:
          Serial.println("WiFi is disconnected.");
          break;
        default:
          Serial.println("WiFi connection failed with unknown error.");
          break;
      }
    }
  }

  Serial.println("Connected to WiFi network.");
}
