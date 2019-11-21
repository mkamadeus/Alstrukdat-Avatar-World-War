// #include "../include/mesin.h"
// #include "../include/mesinkar.h"

#include "mesin.c"
#include "mesinkar.c"
#include "buildings.c"
#include "matrix.c"
#include "command.c"
#include "graph.c"
#include "queue.c"
#include "stack.c"
#include "array.c"
#include "point.c"
#include "pcolor.c"

int main()
{
    buildingsArray b;
    graph g;
    matrix m;
    readConfigFile(&m, &b, &g);

    for(int i=1;i<=17;i++)
    {
        writeBuildingCoord(*Elmt(b,i));
        printf("\n");
    }
    printf("\n");

    writeMatrix(m);

    word w;
    readSTDIN(&w);
    printf("word = ");
    printWord(w);
    printf("\n");
    int a =intConverter(w);
    printf("integer = ");
    printf("%d", a);
}