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

    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=17;j++)
        {
            ignoreBlank();
            int connection = readNumber();
            if(connection) insertChild(G,i,j);
        }
    }

    // printGraph(*G);
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

int intConverter(word W){
    int result = 0;
    int temp;
    for(int i = 0; i < W.length; i++){
        temp = (int) W.wordArray[i] - '0';
        result = result * 10 + temp;
    }
    return result;
}

boolean wordCompare(word W, char * S){
    boolean result = true;
    int i;
    for(i = 0; i < W.length; i++){
        char temp = (char) W.wordArray[i];
        if(temp != S[i]){
            result = false;
        }
    }
    int a = strlen(S);
    if(W.length != a){
        result = false;
    }
    return result;
}