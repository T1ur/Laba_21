#include "dd_button.h"

void dd_button_init(button_t *button, uint8_t pin, int (*read_func)(uint8_t), void (*set_func)(uint8_t, uint8_t)) {
    // Initialize the button structure with the provided pin and function pointers
    button->pin = pin;
    button->state = BUTTON_LOW; // Default state is LOW (not pressed)
    button->read = read_func;   // Assign the read function pointer
    button->set = set_func;     // Assign the set function pointer

    // Set the pin mode for the button using the provided set function
    button->set(button->pin, INPUT_PULLUP_BUTTON);
}

int dd_button_state(button_t *button) {
    return button->read(button->pin); // Read and return the current state of the button using the read function pointer
}