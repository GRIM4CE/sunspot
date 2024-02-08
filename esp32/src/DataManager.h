#ifndef DataManager_h
#define DataManager_h
#include <cstdint>

class DataManager {
public:
    static void postDataToServer(uint16_t lux, int temperature, int humidity);
};

#endif