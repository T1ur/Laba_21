#ifndef DD_LED_H
#define DD_LED_H        // Include guard to prevent multiple inclusions of this header file

#include <stdio.h>      // Standard input/output library for C

#define OUTPUT_LED 1    // Define for setting pin mode to output for the LED

typedef enum {          // Enumeration for LED states
    LED_LOW = 0,
    LED_HIGH
} led_state_t;

typedef struct          // Structure to represent an LED with its properties and function pointers
{
    uint8_t pin;                            // Pin number to which the LED is connected
    led_state_t state;                      // Current state of the LED (ON/OFF)
    void (*write)(uint8_t, uint8_t);        // Function pointer for writing to the LED pin
    void (*set)(uint8_t, uint8_t);          // Function pointer for setting the pin mode for the LED
} led_t;

// function prototypes
void setup_led(led_t *led, int pin, void (*write_func)(uint8_t, uint8_t), void (*set_func)(uint8_t, uint8_t));
void turn_on_led(led_t *led);
void turn_off_led(led_t *led);
void toggle_led_state(led_t *led);

led_state_t get_led_state(led_t *led);
led_state_t set_led_state(led_t *led, led_state_t new_state);
void led_update(led_t *led);

void convert_to_uppercase(char *str);
        
#endif // DD_LED_H