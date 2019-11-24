/* File: pcolor.h */
/* File to store color formatting */

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define BRIGHT "\x1b[1m"
#define DIM "\x1b[2m"
#define UNDERSCORE "\x1b[4m"
#define BLINK "\x1b[5m"
#define REVERSE "\x1b[7m"
#define HIDDEN "\x1b[8m"

// Prints a red character
void print_red(char c);

// Prints a green character
void print_green(char c);

// Prints a yellow character
void print_yellow(char c);

// Prints a blue character
void print_blue(char c);

// Prints a magenta character
void print_magenta(char c);

// Prints a cyan character
void print_cyan(char c);

// Returns string length
int stringLength(char *s);

// Prints with color based on styling
void colorPrint(const char *s, const char *style);