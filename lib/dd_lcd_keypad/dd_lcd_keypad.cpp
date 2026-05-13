#include "dd_lcd_keypad.h"

static FILE stream = {0};                   // Static FILE structure for LCD stream handling

LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_COLS, LCD_ROWS);           // set the LCD address to 0x27 for a 16 chars and 2 line display

//keypad setup
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {ROW_PIN_1, ROW_PIN_2, ROW_PIN_3, ROW_PIN_4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {COL_PIN_1, COL_PIN_2, COL_PIN_3, COL_PIN_4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void perif_init(){
    Serial.begin(9600);
    // Initialize the LCD with the I2C address and dimensions
    lcd.init();                      // initialize the LCD
    lcd.backlight();                 // turn on the backlight

    fdev_setup_stream(&stream, lcd_print, keypad_read, _FDEV_SETUP_RW);    // Configure the FILE structure for write operations using the custom lcd_print function
    stdout = &stream;        // Set standard output stream to the configured FILE structure
    stdin = &stream;         // Set standard input stream to the configured FILE structure
}

int lcd_print(char str, FILE *stream){          // Custom write function to send a character to the LCD stream
    lcd.write(str);
    return 0;                                   // Return 0 to indicate successful write
}

int keypad_read(FILE *stream){                     // Custom read function to read a character from the keypad stream
    char key = keypad.getKey();
    while (key == NO_KEY) {
        key = keypad.getKey();
    }
    return key;
}