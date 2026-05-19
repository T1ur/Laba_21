#ifndef DD_BUTTON_H
#define DD_BUTTON_H

#include "config.h"
#include <stdio.h>      // Standard input/output library for C

typedef enum {          // Enumeration for button states
    BUTTON_LOW = 0,
    BUTTON_HIGH
} button_state_t;

typedef struct          // Structure to represent a button with its properties and function pointers
{
    uint8_t pin;                            // Pin number to which the button is connected
    button_state_t state;                   // Current state of the button (PRESSED/RELEASED)
    int (*read)(uint8_t);                  // Function pointer for reading the button state
    void (*set)(uint8_t, uint8_t);          // Function pointer for setting the pin mode for the button
} button_t;

// Function declarations
void dd_button_init(button_t *button, uint8_t pin, int (*read_func)(uint8_t), void (*set_func)(uint8_t, uint8_t));
int dd_button_state(button_t *button);
#endif // DD_BUTTON_H