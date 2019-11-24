#include "buildings.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    buildings A, B, C, D;
    makeCastle(&A,1);
    show(A);
    makeTower(&B,2);
    show(B);
    makeFort(&C,2);
    show(C);
    makeVillage(&D,1);
    show(D);
    changeLevel(&A, 3);
    show(A);
    return 0;
}