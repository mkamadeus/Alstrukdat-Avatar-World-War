# include "../include/mesin.h"
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

Buildings Bangunan()
/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */
{
    Buildings tempB;
    int x, y, temp;

    IgnoreBlank();
    tempB.B = CC;
    ADV();
    IgnoreBlank();
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
    tempB.IdX = x;
    tempB.IdY = y;

    return tempB;
}

int BacaFile () {
    Point P;
    int n, i, j;
    Buildings B;
    BArray BArr;
    int M[IdxMax][IdxMax];

    START();
    IgnoreBlank();
    P = Peta();
    IgnoreBlank();
    n = BacaAngka();
    BArr.BI[n+1];
    IgnoreBlank();
    for (i = 1; i <= n; i++) {
        B = Bangunan();
        BArr.BI[i] = B;
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