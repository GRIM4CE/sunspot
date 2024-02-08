#include "DataManager.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

void DataManager::postDataToServer(uint16_t lux, int temperature, int humidity) {
  if (WiFi.status() == WL_CONNECTED) {
        
    StaticJsonDocument<200> doc; // Adjust size based on your needs
    doc["lux"] = lux;
    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    String jsonData;
    serializeJson(doc, jsonData);

    HTTPClient http;
    http.begin("https://bvrp9p732c.execute-api.us-east-1.amazonaws.com/POST_LIGHT_DATA");
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(jsonData);
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi is not connected");
  }
}