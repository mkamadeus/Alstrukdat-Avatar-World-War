
#ifndef __MESIN_H_
#define __MESIN_H_

# include "mesinkar.h"
# include "boolean.h"
# include "array.h"
# include "matrix.h"
# include "graph.h"

#define maxLength 100

typedef struct {
    char wordArray[maxLength+1];
    int length;
} word;

extern boolean EndKata;

// ignoreBlank skips input character if its blank/\n
void ignoreBlank();

// readNumber parses input to be an integer
int readNumber();

// readSTDIN will input from STDIN and convert it to ADT Word
void readSTDIN(word *input);

// readConfigFile will read config file and make the structure
void readConfigFile(matrix *M, buildingsArray *arr, graph *G);

// Print ASCII of character (for debugging purposes)
void printASCIIFile();

// Print word
void printWord(word W);

#endif