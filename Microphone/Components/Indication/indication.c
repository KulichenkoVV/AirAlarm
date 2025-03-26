#include "indication.h"
#include "stm32wbxx_hal.h"

// GPIO pins for LEDs
#define LED_GREEN_PIN GPIO_PIN_0
#define LED_RED_PIN GPIO_PIN_1
#define LED_BLUE_PIN GPIO_PIN_2
#define LED_GPIO_PORT GPIOB

// Initialize GPIO ports for LEDs
void indication_init(void) {
    // Configure GPIO settings
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef gpio_init_struct = {0};
    gpio_init_struct.Pin = LED_GREEN_PIN | LED_RED_PIN | LED_BLUE_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull = GPIO_NOPULL;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GPIO_PORT, &gpio_init_struct);
}

// Set the state of an LED
void indication_set_state(led_control *led) {
    uint16_t pin;

    // Map color to corresponding GPIO pin
    switch (led->color) {
        case LED_GREEN: pin = LED_GREEN_PIN; break;
        case LED_RED: pin = LED_RED_PIN; break;
        case LED_BLUE: pin = LED_BLUE_PIN; break;
        default: return;
    }

    // Apply the state to the LED
    switch (led->state) {
        case LED_STATE_ON:
            HAL_GPIO_WritePin(LED_GPIO_PORT, pin, GPIO_PIN_SET);
            break;

        case LED_STATE_OFF:
            HAL_GPIO_WritePin(LED_GPIO_PORT, pin, GPIO_PIN_RESET);
            break;

        case LED_STATE_BLINK:
            HAL_GPIO_TogglePin(LED_GPIO_PORT, pin);
            HAL_Delay(led->delay);
            HAL_GPIO_TogglePin(LED_GPIO_PORT, pin);
            HAL_Delay(led->delay);
            break;
    }
}