#include <stdio.h>
#include <stdlib.h>
#include "buildings.c"
#include "command.c"
#include "stack.c"

int main(){
    buildings C, T, F, V;
    stack S;
    int X;
    createStack(&S);
    makeCastle(&C, 1);
    levelUp(&C, &S);
    levelUp(&C, &S);
    pop(&S, &X);
    if(X == 1){
        inverseLevelUp(&C);
    }
    show(C);
    printf("\n");
    // makeTower(&T, 1);
    // levelTwoTower(&T);
    // show(T);
    // printf("\n");
    // makeFort(&F, 1);
    // show(F);
    // printf("\n");
    // makeVillage(&V, 1);
    // show(V);
    // printf("\n");
    return 0;
}