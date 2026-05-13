#include "dd_led.h"

void setup_led(led_t *led, int pin, void (*write_func)(uint8_t, uint8_t), void (*set_func)(uint8_t, uint8_t)){
    led->pin = pin;
    led->state = LED_LOW;
    led->write = write_func;
    led->set = set_func;
    led->set(led->pin, OUTPUT_LED);
}

void turn_on_led(led_t *led)
{
    led->state = LED_HIGH;
}

void turn_off_led(led_t *led){
    led->state = LED_LOW;
}

led_state_t get_led_state(led_t *led)
{
    return led->state;
}

void toggle_led_state(led_t *led)
{
    led->state = (led->state == LED_LOW) ? LED_HIGH : LED_LOW;
}

led_state_t set_led_state(led_t *led, led_state_t new_state)
{
    led->state = new_state;
    return led->state;
}

void led_update(led_t *led)
{
    led->write(led->pin, led->state);
}

