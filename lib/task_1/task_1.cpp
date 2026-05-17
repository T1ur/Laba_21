#include "task_1.h"

void task1_run(led_t *green_led, button_t *button, void (*delay)(unsigned long ms)){
  static bool state = false;
  static bool lastButtonState = ZERO;
  bool buttonState = dd_button_state(button);
  if (lastButtonState == ONE && buttonState == ZERO) {
  state = !state;           
  set_led_state(green_led, (led_state_t)state);
  led_update(green_led);      
  delay(PAUSE_DURATION);
 }
  lastButtonState = buttonState;
}