#include "Arduino.h"
#include "PowerManager.h"
#include "esp_sleep.h"
#include <cstring>


void PowerManager::goToSleep(unsigned long duration, const char* unit) {
    unsigned long long sleepDurationMicroseconds = duration; // Use unsigned long long for large values
    
    // Convert duration to microseconds based on the unit
    if (strcmp(unit, "second") == 0) {
        sleepDurationMicroseconds *= 1000000ULL;
    } else if (strcmp(unit, "minute") == 0) {
        sleepDurationMicroseconds *= 60 * 1000000ULL;
    } else if (strcmp(unit, "hour") == 0) {
        sleepDurationMicroseconds *= 60 * 60 * 1000000ULL;
    } else {
        Serial.println("Invalid time unit specified. Defaulting to seconds.");
        sleepDurationMicroseconds *= 1000000ULL;
    }
    
    // Print the sleep duration for verification
    Serial.print("Going to sleep for ");
    Serial.print(duration);
    Serial.print(" ");
    Serial.println(unit);

    delay(2000); // Give Serial some time to complete transmission
    esp_sleep_enable_timer_wakeup(sleepDurationMicroseconds);
    esp_deep_sleep_start();
}