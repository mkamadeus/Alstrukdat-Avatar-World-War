# include "../include/mesin.h"
# include "../include/array.h"
# include <stdio.h>

void IgnoreBlank()
/* Mengabaikan satu atau lebih Blank */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    while ((CC == BLANK) && (CC != EOF)) {
        ADV();
    }
}

int BacaAngka() {
    int n, temp;
    IgnoreBlank();
    while ((CC != EOF) && (CC != BLANK)) {
        n = n * 10;
        temp = CC - "";
        n = n + temp;
        ADV();
    }
    IgnoreBlank();
    return n;
}

Point Peta ()
/* Fungsi Peta membaca dan mengirim ukuran peta permainan */
{
    int i, x, y, temp;
    Point P;

    x = 0;
    while ((CC != EOF) && (CC != BLANK)) {
        x = x * 10;
        temp = CC - "";
        x = x + temp;
        ADV();
    }
    IgnoreBlank();
    y = 0;
    while ((CC != EOF) && (CC != BLANK)) {
        y = y * 10;
        temp = CC - "";
        y = y + temp;
        ADV();
    }
    P.X = x;
    P.Y = y;
    return P;
}

buildingCoord Bangunan()
/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */
{
    buildings B;
    int row, col, temp;

    IgnoreBlank();
    if (CC == 'C') 
    B = CC;
    ADV();
    IgnoreBlank();
    row = 0;
    while ((CC != EOF) && (CC != BLANK)) {
        temp = (int)CC;
        row = row * 10 + (int)CC;
        ADV();
    }
    IgnoreBlank();
    col = 0;
    while ((CC != EOF) && (CC != BLANK)) {
        col = col * 10 + (int)CC;
        ADV();
    }
    return makeBuildingCoord (&B,row,col);
}

int BacaFile () {
    Point P;
    int n, i, j;
    buildingCoord B;
    TabInt BArr;
    int M[IdxMax][IdxMax];

    START();
    IgnoreBlank();
    P = Peta();
    IgnoreBlank();
    n = BacaAngka();
    makeEmptyArray(&BArr,n);
    IgnoreBlank();
    for (i = 1; i <= n; i++) {
        B = Bangunan();
        bacaIsi(&BArr,B);
    }
    IgnoreBlank();
    for (i = 1;i <= n; i++) {
        for (j = 1; j<= n; j++) {
            M[i][j] = BacaAngka();
        }
    }
    EndKata = true;
    return 0;
}