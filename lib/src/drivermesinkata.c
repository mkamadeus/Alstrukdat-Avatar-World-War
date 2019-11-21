#include "../include/mesin.h"
#include "../include/mesinkar.h"

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
    printWord(w);    

}