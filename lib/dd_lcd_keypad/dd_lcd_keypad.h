#ifndef DD_LCD_KEYPAD_H
#define DD_LCD_KEYPAD_H

#include <LiquidCrystal_I2C.h>          // Library for controlling LCD displays via I2C
#include <Keypad.h>                     // Library for handling keypad input
#include <Arduino.h>
#include "config.h"

//stdio stream for LCD and keypad handling
void perif_init();
int lcd_print(char str, FILE *stream);
int keypad_read(FILE *stream);

//function prototypes
void lcd_clear();

#endif // DD_LCD_KEYPAD_H