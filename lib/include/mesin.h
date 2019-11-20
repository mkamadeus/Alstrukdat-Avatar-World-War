
#ifndef __MESIN_H_
#define __MESIN_H_

# include "mesinkar.h"
# include "boolean.h"
# include "array.h"
# include "matrix.h"

#define IdxMax 100

extern boolean EndKata;

/* Mengabaikan satu atau lebih Blank */
void ignoreBlank();

/* Fungsi BacaAngka membaca dan mengirim satu buah angka */
int bacaAngka();

/* Fungsi Peta membaca dan mengirim ukuran peta permainan */
void readConfig();

/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */
buildingCoord bangunan();

// Procedure for reading file
void bacaFile ();

// Print ASCII of character (for debugging purposes)
void printASCIIFile();

#endif