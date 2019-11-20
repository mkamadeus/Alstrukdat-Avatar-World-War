
#ifndef __MESIN_H_
#define __MESIN_H_

# include "mesinkar.h"
# include "boolean.h"
# include "array.h"
# include "matrix.h"
# include "graph.h"

#define IdxMax 100

extern boolean EndKata;

/* Mengabaikan satu atau lebih Blank */
void ignoreBlank();

/* Fungsi readNumber membaca dan mengirim satu buah angka */
int readNumber();

// readConfigFile will read config file and make the structure
void readConfigFile(buildingsArray *arr, graph *G);

/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */
buildingCoord bangunan();

// Procedure for reading file
void bacaFile ();

// Print ASCII of character (for debugging purposes)
void printASCIIFile();

#endif