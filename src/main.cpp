#include <Arduino.h>
#include <stdio.h>
#include "dd_led.h"
#include "dd_lcd_keypad.h"
#include "config.h"
#include <string.h>
#include "dd_button.h"

static led_t green_led;
static button_t button;

void setup() {
  setup_led(&green_led, GREEN_LED_PIN, digitalWrite, pinMode);
  dd_button_init(&button, BUTTON_1, digitalRead, pinMode);
}


void loop() {
  static bool state = false;
  static bool lastButtonState = LOW;
  bool buttonState = dd_button_state(&button);
  if (lastButtonState == HIGH && buttonState == LOW) {
  state = !state;           
  set_led_state(&green_led, (led_state_t)state);
  led_update(&green_led);      
  delay(200);
 }
  lastButtonState = buttonState;
}