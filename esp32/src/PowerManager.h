#ifndef PowerManager_h
#define PowerManager_h

class PowerManager {
public:
    static void goToSleep(unsigned long duration, const char* unit);
};

#endif
