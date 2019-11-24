// #include "../include/mesin.h"
// #include "../include/mesinkar.h"

#include "mesin.h"
#include "mesinkar.h"
#include "../buildings/buildings.h"
#include "../matrix/matrix.h"
#include "../command/command.h"
#include "../graph/graph.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../array/array.h"
#include "../point/point.h"
#include "../pcolor/pcolor.h"

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

    int t,bc,cp1,cp2,lfa,lfm;
    int * arrfa;
    int * arrfb;
    boolean i,c,e,c1,c2,is1,is2,s1,s2;
    

    loadFromFile(&m, &b,&g,&t,&i,&c,&e,&q1,&q2,&bc,&c1,&c2,&is1,&s1,&is2,&s2,&cp1,&cp2,&lfa,&lfm,&arrfa,&arrfb);   
    saveToFile(&m, &b,&g,t,i,c,e,&q1,&q2,c1,c2,is1,s1,is2,s2,cp1,cp2,lfa,lfm,arrfa,arrfb);    
    readConfigFile(&m, &b, &g,&bc);
    printf("masuk sini");
    for(int i=1;i<=Neff(b);i++)
    {
        printf("masuk sini");
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