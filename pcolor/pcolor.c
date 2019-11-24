/* File: pcolor.c */
/* pcolor.h implemetation */

#include <stdio.h>
#include <string.h>
#include "pcolor.h"

// Prints a red character
void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

// Prints a green character
void print_green(char c) {
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}

// Prints a yellow character
void print_yellow(char c) {
    printf("%s%c", YELLOW, c);
    printf("%s", NORMAL);
}

// Prints a blue character
void print_blue(char c) {
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}

// Prints a magenta character
void print_magenta(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
}

// Prints a cyan character
void print_cyan(char c) {
    printf("%s%c", CYAN, c);
    printf("%s", NORMAL);
}

// Returns string length
int stringLength(char *s)
{
    int result=0;
    int i=0;
    while(s[i]!='\0') {++result;++i;}
    
    return result;
}

// Prints with color based on styling
void colorPrint(const char *s, const char *style)
{
    if(strcmp(style,NORMAL)==0) printf("%s%s%s", NORMAL,s,NORMAL);
    else if(strcmp(style,RED)==0) printf("%s%s%s", RED,s,NORMAL);
    else if(strcmp(style,GREEN)==0) printf("%s%s%s", GREEN,s,NORMAL);
    else if(strcmp(style,YELLOW)==0) printf("%s%s%s", YELLOW,s,NORMAL);
    else if(strcmp(style,BLUE)==0) printf("%s%s%s", BLUE,s,NORMAL);
    else if(strcmp(style,MAGENTA)==0) printf("%s%s%s", MAGENTA,s,NORMAL);
    else if(strcmp(style,CYAN)==0) printf("%s%s%s", CYAN,s,NORMAL);
    else if(strcmp(style,BRIGHT)==0) printf("%s%s%s", BRIGHT,s,NORMAL);
    else if(strcmp(style,DIM)==0) printf("%s%s%s", DIM,s,NORMAL);
    else if(strcmp(style,UNDERSCORE)==0) printf("%s%s%s", UNDERSCORE,s,NORMAL);
    else if(strcmp(style,BLINK)==0) printf("%s%s%s", BLINK,s,NORMAL);
    else if(strcmp(style,REVERSE)==0) printf("%s%s%s", REVERSE,s,NORMAL);
    else if(strcmp(style,HIDDEN)==0) printf("%s%s%s", HIDDEN,s,NORMAL);
}