#include "../include/mesin.h"

int main()
{
    buildingsArray b;
    graph g;
    readConfigFile(&b, &g);

    for(int i=1;i<=17;i++)
    {
        writeBuildingCoord(*Elmt(b,i));
    }
    printf("\n");
}