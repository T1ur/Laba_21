#include <Arduino.h>
#include <stdio.h>
#include <string.h>   // Include string.h for strcmp function
#include "dd_led.h"
#include "terminal.h"
#include "config.h"
#include <ctype.h>    // Include ctype.h for toupper function


static led_t led_1;

void setup() {
  // setting up LED and terminal:
  setup_led(&led_1, LED_PIN, digitalWrite, pinMode);
  setup_terminal();
}
// Command definitions and function pointers for handling LED commands
static const char *commands[]
{
  "ON",
  "OFF",
  "TOGGLE"
};
// Array of function pointers corresponding to the LED commands
void (*functions[])(led_t*)
{
  turn_on_led,
  turn_off_led,
  toggle_led_state
};
// Function to check the received command and execute the corresponding LED function
void check_command(const char *command)
{
  static uint8_t num_commands = sizeof(commands) / sizeof(commands[0]);

  for (size_t i = 0; i < num_commands; i++)
  {
    if (strcmp(command, commands[i]) == 0)
    {
      functions[i](&led_1);
      printf("Command executed: LED %s\n\r", command);
      return;
    }
  }
  printf("Invalid command: %s. Use: LED <ON/OFF/TOGGLE>\n\r", command);
}


void loop() {
  printf("Enter a command: LED ON / LED OFF\n\r");

  char command[BUFF_SIZE] = {0};
  char stat[BUFF_SIZE] = {0};

  scanf("%5s %7s", command, stat);

  convert_to_uppercase(command);
  convert_to_uppercase(stat);
  
#ifdef DEBUG
  printf("Debug: Received input - stat: '%s', command: '%s'\n\r", command, stat);
#endif
  if (strcmp(command, "LED") == 0)
  {
    check_command(stat);
  }
  else
  {
    printf("Invalid command format. Use: LED <ON/OFF/TOGGLE>\n\r");
  }

  led_update(&led_1);
}