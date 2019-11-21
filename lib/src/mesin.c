# include "../include/mesin.h"
# include <stdio.h>

static char configFilename[] = "config.conf";

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
void readConfigFile(buildingsArray *arr, graph *G)
{
    // Start reading config file
    START(configFilename);

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