
#ifndef __MESIN_H_
#define __MESIN_H_

# include "mesinkar.h"
# include "boolean.h"
# include "array.h"
# include "matrix.h"

#define IdxMax 100
#define BLANK ' '

extern boolean EndKata;

void IgnoreBlank();
/* Mengabaikan satu atau lebih Blank */

int BacaAngka();
/* Fungsi BacaAngka membaca dan mengirim satu buah angka */

matrix Peta (matrix *map);
/* Fungsi Peta membaca dan mengirim ukuran peta permainan */

buildingCoord Bangunan();
/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */

int BacaFile ();

#endif