#include "../lib/include/mesin.h"
#include "../lib/include/graph.h"
#include "../lib/include/matrix.h"
#include "../lib/include/array.h"

int main()
{
    matrix M;
    buildingsArray A;
    graph G;
    int N;

    readConfigFile(&M,&A,&G,&N);

    writeMatrix(M);
}