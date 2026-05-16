#ifndef _TERMINAL_H             // Include guard to prevent multiple inclusions of this header file
#define _TERMINAL_H             

#include "config.h"             // Include the configuration header for project-wide settings

// function prototypes
void setup_terminal();                      // Function to initialize the terminal for serial communication
int write_ter(char str, FILE *stream);      // Function to write a character to the terminal stream
int read_ter(FILE *stream);                 // Function to read a character from the terminal stream


#endif // _TERMINAL_H