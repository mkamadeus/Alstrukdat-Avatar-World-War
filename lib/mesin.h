
#ifndef __MESIN_H_
#define __MESIN_H_

# include "mesinkar.h"
# include "boolean.h"

#define IdxMax 100
#define BLANK ' '

typedef struct {
    int X;
    int Y;
} Point;

typedef struct {
    char B;
    int IdX;
    int IdY;
} Buildings;

typedef struct {
    Buildings BI[IdxMax+1];
    int Neff;
} BArray;

extern boolean EndKata;

void IgnoreBlank();
/* Mengabaikan satu atau lebih Blank */

int BacaAngka();
/* Fungsi BacaAngka membaca dan mengirim satu buah angka */

Point Peta ();
/* Fungsi Peta membaca dan mengirim ukuran peta permainan */

Buildings Bangunan();
/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */

int BacaFile ();

#endif