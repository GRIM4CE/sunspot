#ifndef SensorManager_h
#define SensorManager_h

#include <BH1750.h>
#include <ErriezDHT22.h>

class SensorManager {
public:
    SensorManager(int dhtPin);
    void begin();
    void end();
    float readLightLevel();
    bool DHTAvailable();
    int readTemperature();
    int readHumidity();

private:
    BH1750 lightSensor;
    DHT22 dhtSensor;
    bool isBH1750Configured;
};

#endif