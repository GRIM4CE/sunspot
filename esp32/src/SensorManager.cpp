#include "SensorManager.h"
#include <Wire.h>

#define LED_POWER_PIN 2

SensorManager::SensorManager(int dhtPin) : lightSensor(), dhtSensor(dhtPin), isBH1750Configured(false) {}

void SensorManager::begin() {
    pinMode(LED_POWER_PIN, OUTPUT);
    digitalWrite(LED_POWER_PIN, HIGH);
    dhtSensor.begin();

    Wire.begin();
    isBH1750Configured = lightSensor.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
}

void SensorManager::end() {
    digitalWrite(LED_POWER_PIN, LOW);
}

float SensorManager::readLightLevel() {
    if(isBH1750Configured) {
        return lightSensor.readLightLevel();
    } else {
         return -1;
    }
}

bool SensorManager::DHTAvailable() {
    return dhtSensor.available();
}

int SensorManager::readTemperature() {
    return dhtSensor.readTemperature();
}

int SensorManager::readHumidity() {
    return dhtSensor.readHumidity();
}