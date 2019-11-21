# include "../include/mesin.h"
# include <stdio.h>

static char configFilename[] = "config.conf";
static char savefileFilename[] = "savefile.dat";

static FILE * savefile;

// Advances until CC is not blank
void ignoreBlank()
{
    // While not blank
    while (CC != EOF && (CC == ' ' || CC == '\n')) ADV();
}

// readNumber parses input to be an integer
int readNumber()
{
    int n = 0;
    
    ignoreBlank();
    while (!EOP && CC != EOF && CC != ' ' && CC != '\n') {
        n = n*10 + (CC-'0');
        ADV();
    }

    return n;
}

// readSTDIN will input from STDIN and convert it to ADT Word
void readSTDIN(word *input)
{
    STARTSTDIN();

    // Initialize word
    (*input).length = 0;

    while(!EOP && CC!='\n')
    {
        (*input).wordArray[(*input).length] = CC;
        ++(*input).length;
        ADVSTDIN();
    }
}

// readConfigFile will read config file and make the structure
void readConfigFile(matrix *M, buildingsArray *arr, graph *G)
{
    // Start reading config file
    START(configFilename);

    // Read map size
    ignoreBlank();
    int row = readNumber();
    ignoreBlank();
    int col = readNumber();

    // Initialize matrix
    createEmptyMatrix(row,col,M);

    // Read building count
    ignoreBlank();
    int t = readNumber();

    printf("Map size: %dx%d\nBuilding count: %d\n", row, col, t);
    printf("Reading building types...\n");

    // Initialize array size
    makeEmptyArray(arr,t);

    for(int i=1;i<=t;i++)
    {
        // Read building type
        ignoreBlank();
        char buildingType = CC;
        ADV();

        // Construct buildings
        addressBuildings ptr = allocateBuilding();

        if(buildingType=='C')  makeCastle(ptr,0);
        else if(buildingType=='T') makeTower(ptr, 0);
        else if(buildingType=='F') makeFort(ptr, 0);
        else if(buildingType=='V') makeVillage(ptr, 0);

        // Read building coordinate
        ignoreBlank();
        int buildingRow = readNumber();
        ignoreBlank();
        int buildingCol = readNumber();
        
        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(ptr, buildingRow, buildingCol);
        insertStructure(M, Elmt(*arr,i));
        
    }

    printf("Building graph...\n");
    // Initialize graph
    createGraph(G,t);

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++)
        {
            ignoreBlank();
            int connection = readNumber();
            if(connection) insertChild(G,i,j);
        }
    }
    char completeMessage[] = "Configuration file loaded!";
    int i=0;
    while(completeMessage[i]!='\0') print_green(completeMessage[i++]);
    printf("\n");
    // printGraph(*G);
}

// Save to file
void saveToFile(matrix *M, buildingsArray *arr, graph *G, int turn, boolean ignore, boolean critical, boolean extraTurn, queue *Q1, queue *Q2)
{
    savefile = fopen(savefileFilename, "w");
    // Output map size
    fprintf(savefile,"%d %d\n", nRowEff(*M)-1, nColEff(*M)-1);

    // Output building count
    int t=MaxEl(*arr);
    fprintf(savefile,"%d\n", t);

    // Output all bulding with its state
    // Format : type rb cb owner level troops defense
    for(int i=1;i<=t;i++)
    {
        char type;
        if(type(*build(*Elmt(*arr,i)))==1) type='C';
        else if(type(*build(*Elmt(*arr,i)))==2) type='T';
        else if(type(*build(*Elmt(*arr,i)))==3) type='F';
        else if(type(*build(*Elmt(*arr,i)))==4) type='V';

        fprintf(savefile, "%c %d %d %d %d %d %d\n", type, row(*Elmt(*arr,i)), col(*Elmt(*arr,i)), owner(*build(*Elmt(*arr,i))), level(*build(*Elmt(*arr,i))), troops(*build(*Elmt(*arr,i))), defense(*build(*Elmt(*arr,i))));
    }

    // Output graph representation in adjacency list form
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++) fprintf(savefile, "%d ", isConnected(*G, i, j) ? 1 : 0);
        fprintf(savefile,"\n");
    }

    // Output for whose turn it is
    fprintf(savefile, "%d\n", turn);
    // Output ignore defense state
    fprintf(savefile, "%d\n", ignore);
    // Output ignore critical state
    fprintf(savefile, "%d\n", ignore);
    // Output extra turn state
    fprintf(savefile, "%d\n", extraTurn);
    // Output skill queue for player 1
    int count=0;
    for(int i=Head(*Q1);count<10;i=(i%10)+1) {fprintf(savefile, "%d ", (*Q1).T[i]);++count;}
    fprintf(savefile, "\n");
    // Output skill queue for player 2
    count=0;
    for(int i=Head(*Q2);count<10;i=(i%10)+1) {fprintf(savefile, "%d ", (*Q2).T[i]);++count;}
    fprintf(savefile, "\n");

    // Close stream
    fclose(savefile);
}

// Load from file
void loadFromFile(matrix *M, buildingsArray *arr, graph *G, int *turn, boolean *ignore, boolean *critical, boolean *extraTurn, queue *Q1, queue *Q2)
{
    // Start reading filename
    START(savefileFilename);

    // Read map size
    ignoreBlank();
    int row = readNumber();
    ignoreBlank();
    int col = readNumber();

    // Initialize matrix
    createEmptyMatrix(row,col,M);

    // Read building count
    ignoreBlank();
    int t = readNumber();

    printf("Map size: %dx%d\nBuilding count: %d\n", row, col, t);
    printf("Reading building states...\n");

    // Initialize array size
    makeEmptyArray(arr,t);

    for(int i=1;i<=t;i++)
    {
        // Read building type
        ignoreBlank();
        char buildingType = CC;
        ADV();

        // Construct buildings
        addressBuildings ptr = allocateBuilding();

        if(buildingType=='C')  makeCastle(ptr,0);
        else if(buildingType=='T') makeTower(ptr, 0);
        else if(buildingType=='F') makeFort(ptr, 0);
        else if(buildingType=='V') makeVillage(ptr, 0);

        // Read building coordinate
        ignoreBlank();
        int buildingRow = readNumber();
        ignoreBlank();
        int buildingCol = readNumber();
        
        //Read building owner
        ignoreBlank();
        int buildingOwner = readNumber();
        owner(*ptr) = buildingOwner;
        //Read building level
        ignoreBlank();
        int buildingLevel = readNumber();
        level(*ptr) = buildingLevel;
        //Read building troops
        ignoreBlank();
        int buildingTroops = readNumber();
        troops(*ptr) = buildingTroops;
        //Read building defense state
        ignoreBlank();
        int buildingDefense = readNumber();
        defense(*ptr) = buildingDefense;

        // Construct and send to array
        Elmt(*arr, i) = makeBuildingCoord(ptr, buildingRow, buildingCol);
        insertStructure(M, Elmt(*arr,i));
        
    }

    printf("Building graph...\n");
    // Initialize graph
    createGraph(G,t);

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++)
        {
            ignoreBlank();
            int connection = readNumber();
            if(connection) insertChild(G,i,j);
        }
    }

    // Read turn state
    ignoreBlank();
    *turn = readNumber();
    // Read ignore state
    ignoreBlank();
    *ignore = readNumber();
    // Read critical state
    ignoreBlank();
    *critical = readNumber();
    // Read extra turn state
    ignoreBlank();
    *extraTurn = readNumber();

    // Input to queue
    createEmpty(Q1);
    for(int i=1;i<=10;i++) 
    {
        ignoreBlank();
        (*Q1).T[i] = readNumber();
    }

    // Input to queue
    createEmpty(Q2);
    for(int i=1;i<=10;i++) 
    {
        ignoreBlank();
        (*Q2).T[i] = readNumber();
    }
    char completeMessage[] = "Save file loaded, ready to play!";
    int i=0;
    while(completeMessage[i]!='\0') print_green(completeMessage[i++]);
    printf("\n");
    // printGraph(*G);
}

/* -=-=-=-=-=-=-=- FOR DEBUGGING PURPOSES -=-=-=-=-=-=-=- */

void printASCIIFile()
{
    START(configFilename);
    while(!EOP)
    {
        int n = readNumber();
        printf("%d ", n);
    }
}

// Print word
void printWord(word W)
{
    for(int i=0;i<W.length;i++) printf("%c",W.wordArray[i]);
    printf("\n");
}
