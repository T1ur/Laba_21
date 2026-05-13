#include <Arduino.h>
#include <stdio.h>
#include "dd_led.h"
#include "dd_lcd_keypad.h"
#include "config.h"

static led_t RED;
static led_t GREEN;


void setup() {
  perif_init();
  setup_led(&RED, RED_LED_PIN, digitalWrite, pinMode);
  setup_led(&GREEN, GREEN_LED_PIN, digitalWrite, pinMode);
}


void loop() {
  printf("Password:\n\r");
  delay(1000);
}