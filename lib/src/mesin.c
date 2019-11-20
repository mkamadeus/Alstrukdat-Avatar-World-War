# include "../include/mesin.h"
# include <stdio.h>

// Advances until CC is not blank
void ignoreBlank()
{
    // While not blank
    while (CC != EOF && (CC == ' ' || CC == '\n')) ADV();
}

// Converts read character to integer
int readNumber() {
    int n = 0;
    
    ignoreBlank();
    while (!EOP && CC != EOF && CC != ' ' && CC != '\n') {
        n = n*10 + (CC-'0');
        ADV();
    }

    return n;
}

// readConfigFile will read config file and make the structure
void readConfigFile(buildingsArray *arr, graph *G)
{
    // Start reading config file
    START();

    // Read map size
    ignoreBlank();
    int row = readNumber();
    ignoreBlank();
    int col = readNumber();

    
    // Read building count
    ignoreBlank();
    int t = readNumber();

    printf("Map size:%dx%d\nBuilding count:%d\n", row, col, t);
    printf("Reading building types...\n");

    // Initialize array size
    makeEmptyArray(arr,t);

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
        else if(buildingType=='F') makeFort(&building, 0);
        else if(buildingType=='V') makeVillage(&building, 0);
        
        // Read building coordinate
        ignoreBlank();
        int buildingRow = readNumber();
        ignoreBlank();
        int buildingCol = readNumber();
        
        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(&building, buildingRow, buildingCol);
        
    }

    printf("Building graph...\n");
    // Initialize graph
    createGraph(G,t);

    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=17;j++)
        {
            ignoreBlank();
            int connection = readNumber();
            if(connection) insertChild(G,i,j);
        }
    }

    printGraph(*G);
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
//     n = readNumber();
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
//             M[i][j] = readNumber();
//         }
//     }
//     EndKata = true;
// }

void printASCIIFile()
{
    START();
    while(!EOP)
    {
        int n = readNumber();
        printf("%d ", n);
    }
}