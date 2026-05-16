#include <Arduino.h>
#include <stdio.h>
#include "dd_led.h"
#include "dd_lcd_keypad.h"
#include "config.h"
#include <string.h>

static led_t RED;
static led_t GREEN;
static char code[code_length + 1];          // Buffer to store the entered password code, +1 for null terminator

void setup() {
  perif_init();
  setup_led(&RED, RED_LED_PIN, digitalWrite, pinMode);
  setup_led(&GREEN, GREEN_LED_PIN, digitalWrite, pinMode);
}


void loop() {
  printf("Password: ");
  scanf("%s", code);                         // Read the entered password code from the keypad stream
  if(strcmp(code, correct_code) == 0){       // Compare the entered code with the correct code
    lcd_clear();
    printf("Access Granted\n");
    turn_on_led(&GREEN);                      // Turn on the green LED
    led_update(&GREEN);                       // Update the state of the green LED
    delay(led_stay);                          // Keep the LED on for a specified duration
    turn_off_led(&GREEN);                     // Turn off the green LED
    led_update(&GREEN);                       // Update the state of the green LED
  } else {
    lcd_clear();
    printf("Access Denied\n");
    turn_on_led(&RED);                        // Turn on the red LED
    led_update(&RED);                         // Update the state of the red LED
    delay(led_stay);                          // Keep the LED on for a specified duration
    turn_off_led(&RED);                       // Turn off the red LED
    led_update(&RED);                         // Update the state of the red LED
  }
}