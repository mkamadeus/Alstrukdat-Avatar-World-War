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
        n = n *10 + (int)CC;
        ADV();
    }
    IgnoreBlank();
    return n;
}

matrix Peta (matrix *map)
/* Fungsi Peta membaca dan mengirim ukuran peta permainan */
{
    int i, row, col, temp;

    row = 0;
    while ((CC != EOF) && (CC != BLANK)) {
        row = row * 10 + (int)CC;
        ADV();
    }
    IgnoreBlank();
    col = 0;
    while ((CC != EOF) && (CC != BLANK)) {
        col = col * 10 + (int)CC;
        ADV();
    }
    createEmpty(row,col,map);
    return *map;
}

buildingCoord Bangunan()
/* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */
{
    buildings B;
    int row, col;

    IgnoreBlank();
    if (CC == 'C') makeCastle(&B,0);
    else if (CC == 'F') makeFort(&B,0);
    else if (CC == 'T') makeTower(&B,0);
    else if (CC == 'V') makeVillage(&B,0);//kondisikan ownernya
    ADV();
    IgnoreBlank();
    row = 0;
    while ((CC != EOF) && (CC != BLANK)) {
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
    matrix map;
    int n, i, j;
    buildingCoord B;
    TabInt BArr;
    int M[IdxMax][IdxMax];//graph (?)

    START();
    IgnoreBlank();
    map = Peta(&map);
    IgnoreBlank();
    n = BacaAngka();
    makeEmptyArray(&BArr,n);
    IgnoreBlank();
    for (i = 1; i <= n; i++) {
        B = Bangunan();
        bacaIsi(&BArr,B);
        insertStructure(&map,B);
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