#include "../include/mesin.h"
#include "../include/mesinkar.h"

int main()
{
    buildingsArray b;
    graph g;
    matrix m;
    queue q1,q2;
    createEmpty(&q1);
    Add(&q1,1);
    createEmpty(&q2);
    Add(&q2,2);
    readConfigFile(&m, &b, &g);

    saveToFile(&m, &b,&g,1,0,0,0,&q1,&q2);    

}