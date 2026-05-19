#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include "dd_led.h"
#include "dd_lcd_keypad.h"
#include "config.h"
#include "dd_button.h"
#include "timer-api.h"
#include "task_1.h"
#include "task_2.h"

static led_t green_led;
static button_t button;

void os_seq1_setup() {
    timer_init_ISR_1Hz(TIMER_DEFAULT);
}

/**
 * Timer interrupt service routine, called with chosen period
 * @param timer - timer id
 */
/**
 * Процедура, вызываемая прерыванием по событию таймера с заданным периодом
 * @param timer - идентификатор таймера
 */
void timer_handle_interrupts(int timer) {
    task1_run(&green_led, &button);
}

void setup() {
  perif_init();
  os_seq1_setup();
  setup_led(&green_led, GREEN_LED_PIN, digitalWrite, pinMode);
  dd_button_init(&button, BUTTON_1, digitalRead, pinMode);
}
//TODO: Create a function for button/action
void loop() {
  
}