#include "command.c"
#include "buildings.c"
#include "stack.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    buildings C, F;
    stack S, level, before, troops1, troops2;
    own P;
    createStack(&S);
    createStack(&level);
    createStack(&before);
    createStack(&troops1);
    createStack(&troops2);
    makeCastle(&C,2);
    makeFort(&F,1);
    show(C);
    show(F);
    printf("\n");
    attack(&F,&C, 1, &level, &before, &troops1, &troops2, &S);
    show(C);
    show(F);
    printf("\n");
    inverseAttack(&F, &C, &level, &before, &troops1, &troops2);
    show(C);
    show(F);
}