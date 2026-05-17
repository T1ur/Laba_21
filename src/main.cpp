#include <Arduino.h>
#include <stdio.h>
#include "dd_led.h"
#include "dd_lcd_keypad.h"
#include "config.h"
#include <string.h>
#include "dd_button.h"
#include "task_1.h"

static led_t green_led;
static button_t button;

void setup() {
  setup_led(&green_led, GREEN_LED_PIN, digitalWrite, pinMode);
  dd_button_init(&button, BUTTON_1, digitalRead, pinMode);
}


void loop() {
  task1_run(&green_led, &button, delay);
}