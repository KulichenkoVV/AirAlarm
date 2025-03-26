#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>

// Enumerator for battery charge levels
typedef enum {
    FULL_POWER,       // 50-100% charge
    MODERATE_POWER,   // 20-50% charge
    LOW_POWER,        // 10-20% charge
    CRITICAL_POWER    // Below 10% charge
} BatteryChargeLevel;

// Function declarations
void Battery_Init(void);
BatteryChargeLevel Battery_GetChargeLevel(void); // Returns the charge level enum

#endif // BATTERY_H
