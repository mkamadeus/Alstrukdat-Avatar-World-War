#include "../mesinKata/mesin.h"
#include "../graph/graph.h"
#include "matrix.h"
#include "../array/array.h"

int main()
{
    matrix M;
    buildingsArray A;
    graph G;
    int N;

    readConfigFile(&M,&A,&G,&N);

    writeMatrix(M);
}