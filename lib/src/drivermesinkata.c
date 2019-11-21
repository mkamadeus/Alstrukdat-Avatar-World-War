#include "../include/mesin.h"
#include "../include/mesinkar.h"

int main()
{
    buildingsArray b;
    graph g;
    matrix m;
    queue q1,q2;
    // createEmpty(&q1);
    // Add(&q1,1);
    // createEmpty(&q2);
    // Add(&q2,2);
    // readConfigFile(&m, &b, &g);

    int t;
    boolean i,c,e;

    loadFromFile(&m, &b,&g,&t,&i,&c,&e,&q1,&q2);   
    saveToFile(&m, &b,&g,t,i,c,e,&q1,&q2);    
}