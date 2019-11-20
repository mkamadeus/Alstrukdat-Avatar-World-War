# include "../include/mesin.h"
# include <stdio.h>

// Advances until CC is not blank
void ignoreBlank()
{
    // While not blank
    while (CC != EOF && (CC == ' ' || CC == '\n')) ADV();
}

// Converts read character to integer
int bacaAngka() {
    int n = 0;
    
    ignoreBlank();
    while (!EOP && CC != EOF && CC != ' ' && CC != '\n') {
        n = n*10 + (CC-'0');
        ADV();
    }

    return n;
}

/* Fungsi Peta membaca dan mengirim ukuran peta permainan */
void readConfig()
{
    // Start reading config file
    START();

    // Read map size
    ignoreBlank();
    int row = bacaAngka();
    ignoreBlank();
    int col = bacaAngka();

    // Read building count
    ignoreBlank();
    int t = bacaAngka();

    for(int i=1;i<=t;i++)
    {
        // Read building type
        ignoreBlank();
        ADV();
        char buildingType = CC;

        // Construct buildings
        buildings building;
        if(buildingType=='C') makeCastle(&building, 0);
        else if(buildingType=='T') makeTower(&building, 0);
        else if(buildingType=='F') makeForst(&building, 0);
        else if(buildingType=='V') makeVillage(&building, 0);
        
        // Read building coordinate
        ignoreBlank();
        int buildingRow = bacaAngka();
        ignoreBlank();
        int buildingCol = bacaAngka();
        
        // Construct buildingCoord
        buildingCoord bc = makeBuildingCoord(&building, buildingRow, buildingCol);

        // Send to array
        
    }

    printf("Map size:%dx%d\n", row, col);
    
    // createEmpty(row,col,map);
}

// /* Fungsi mengirim daftar bangunan yang ingin dimasukkan ke dalam peta permainan */
// buildingCoord bangunan()
// {
//     buildings B;
//     int row, col;

//     ignoreBlank();
//     if (CC == 'C') makeCastle(&B,0);
//     else if (CC == 'F') makeFort(&B,0);
//     else if (CC == 'T') makeTower(&B,0);
//     else if (CC == 'V') makeVillage(&B,0);//kondisikan ownernya
//     ADV();
//     ignoreBlank();
//     row = 0;
//     while ((CC != EOF) && (CC != ' ')) {
//         row = row * 10 + (int)CC;
//         ADV();
//     }
//     ignoreBlank();
//     col = 0;
//     while ((CC != EOF) && (CC != ' ')) {
//         col = col * 10 + (int)CC;
//         ADV();
//     }
//     return makeBuildingCoord (&B,row,col);
// }

// /* Prosedur untuk membaca file */
// void bacaFile () {
//     matrix map;
//     int n, i, j;
//     buildingCoord B;
//     buildingsArray BArr;
//     int M[IdxMax][IdxMax];//graph (?)

//     START();
//     ignoreBlank();
//     Peta(&map);
//     ignoreBlank();
//     n = bacaAngka();
//     makeEmptyArray(&BArr,n);
//     ignoreBlank();
//     for (i = 1; i <= n; i++) {
//         B = bangunan();
//         bacaIsi(&BArr,B);
//         insertStructure(&map,B);
//     }
//     ignoreBlank();
//     for (i = 1;i <= n; i++) {
//         for (j = 1; j<= n; j++) {
//             M[i][j] = bacaAngka();
//         }
//     }
//     EndKata = true;
// }

void printASCIIFile()
{
    START();
    while(!EOP)
    {
        int n = bacaAngka();
        printf("%d ", n);
    }
}