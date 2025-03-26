#ifndef INDICATION_H
#define INDICATION_H

#include <stdint.h>

// Colors of LEDs
typedef enum {
    LED_GREEN,
    LED_RED,
    LED_BLUE
} led_color;

// States of LEDs
typedef enum {
    LED_STATE_OFF,
    LED_STATE_ON,
    LED_STATE_BLINK
} led_state;

// Structure to manage LED state
typedef struct {
    led_color color;
    led_state state;
    uint16_t delay; // Delay for BLINK state
} led_control;

// Initialize LEDs
void indication_init(void);

// Set the state of an LED
void indication_set_state(led_control *led);

#endif // INDICATION_H