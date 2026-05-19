#include "task_1.h"

void task1_run(led_t *green_led, button_t *button){
  if(dd_button_state(button)) {
    turn_on_led(green_led);
    led_update(green_led);
  } else {
    turn_off_led(green_led);
    led_update(green_led);
  }
}