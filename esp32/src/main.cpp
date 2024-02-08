#include <SPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ErriezDHT22.h>

#include "config.h"
#include "WiFiManager.h"
#include "SensorManager.h"
#include "PowerManager.h"
#include "DataManager.h"

SensorManager sensorManager(4); // AM2302 DAT PIN

void initializeSerial() {
  Serial.begin(19200);
  while (!Serial) ; // wait for serial port to connect.
}

void setup() {
    initializeSerial();
    WiFiManager::connectToWiFi(ssid, password);
    sensorManager.begin();
}

void loop() {
    float lightLevel = sensorManager.readLightLevel();
    int temperature = -1;
    int humidity = -1;

    if(sensorManager.DHTAvailable()) {
        temperature = sensorManager.readTemperature();
        humidity = sensorManager.readHumidity();
    }
    
    if(lightLevel != -1 && temperature != -1 && humidity != -1) {
        DataManager::postDataToServer(lightLevel, temperature, humidity);
    }

    sensorManager.end();
    PowerManager::goToSleep(30, "minute");
}