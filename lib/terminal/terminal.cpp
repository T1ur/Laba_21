#include <Arduino.h>
#include "terminal.h"

static FILE stream = {0};                   // Static FILE structure for terminal stream handling

void setup_terminal(){
    Serial.begin(BAUDRATE);

    fdev_setup_stream(&stream, write_ter, read_ter, _FDEV_SETUP_RW);    // Configure the FILE structure for read/write operations using the custom write and read functions

    stdin = &stream;        // Set standard input, output, and error streams to the configured FILE structure
    stdout = &stream;
    stderr = &stream;

    printf("Terminal setup complete.\n\r");     // Print a message to indicate that the terminal setup is complete
}

int write_ter(char str, FILE *stream){          // Custom write function to send a character to the terminal stream
    return Serial.write(str);
}

int read_ter(FILE *stream){                     // Custom read function to read a character from the terminal stream
    while(!Serial.available()); 
    return Serial.read();
}