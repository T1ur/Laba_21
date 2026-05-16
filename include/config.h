#ifndef CONFIG_H
#define CONFIG_H

#define DEBUG           // Uncomment to enable debug output

#define BAUDRATE        9600        // Serial communication baud rate
#define LED_PIN         8           // Pin connected to the LED
#define BUFF_SIZE       20          // Buffer size for command input

#define RED_LED_PIN     9           // Pin connected to the red LED
#define GREEN_LED_PIN   8           // Pin connected to the green LED

#define LCD_I2C_ADDR    0x27        // I2C address for the LCD
#define LCD_COLS        16          // Number of columns in the LCD
#define LCD_ROWS        2           // Number of rows in the LCD

#define ROW_PIN_1     23          // Pin connected to row 1 of the keypad
#define ROW_PIN_2     25          // Pin connected to row 2 of the keypad
#define ROW_PIN_3     27          // Pin connected to row 3 of the keypad
#define ROW_PIN_4     29          // Pin connected to row 4 of the keypad
#define COL_PIN_1     31          // Pin connected to column 1 of the keypad
#define COL_PIN_2     33          // Pin connected to column 2 of the keypad
#define COL_PIN_3     35          // Pin connected to column 3 of the keypad
#define COL_PIN_4     37          // Pin connected to column 4 of the keypad
#define code_length   4           // Length of the password code
#define correct_code  "1234"      // Correct password code
#define led_stay      1000        // Duration (in milliseconds) to keep the LED on after a successful password entry
#endif // CONFIG_H

