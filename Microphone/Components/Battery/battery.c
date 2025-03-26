#include "battery.h"
#include "main.h" // For using BATTERY_Pin and BATTERY_GPIO_Port configurations
#include "adc.h"

#define MIN_VOLTAGE 3000
#define MAX_VOLTAGE 4200

static uint32_t ReadBatteryVoltage(void);

// Initialize the battery module
void Battery_Init(void) {
    HAL_ADC_Start(&hadc1);
}

// Get the battery charge level as an enumerator
BatteryChargeLevel Battery_GetChargeLevel(void) {
    uint32_t voltage = ReadBatteryVoltage();
    uint8_t chargePercentage;

    // Calculate charge percentage (internal logic only for determining the level)
    if (voltage < MIN_VOLTAGE) {
        chargePercentage = 0;
    } else if (voltage > MAX_VOLTAGE) {
        chargePercentage = 100;
    } else {
        chargePercentage = (voltage - MIN_VOLTAGE) * 100 / (MAX_VOLTAGE - MIN_VOLTAGE);
    }

    // Determine and return charge level enum
    if (chargePercentage >= 50) {
        return FULL_POWER; // 50-100%
    } else if (chargePercentage >= 20) {
        return MODERATE_POWER; // 20-50%
    } else if (chargePercentage >= 10) {
        return LOW_POWER; // 10-20%
    } else {
        return CRITICAL_POWER; // Below 10%
    }
}

// Read the battery voltage
static uint32_t ReadBatteryVoltage(void) {
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint32_t adcValue = HAL_ADC_GetValue(&hadc1);

    // Convert ADC value to millivolts
    uint32_t voltage = (adcValue * 3300) / 4095; // 3300 mV, 12-bit ADC
    return voltage;
}