#include <stdio.h>
#include <stdlib.h>
#include "command.h"
#include "../buildings/buildings.h"

int main(){
    buildings C, F;
    stack S, level, before, troops1, troops2, crit;
    boolean isCaptured;
    boolean critical = false;
    boolean ignore = true;
    boolean isSuccess;
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
    attack(&F,&C, &isCaptured, 10, &critical, ignore, 1, &level, &before, &troops1, &troops2, &S, &crit);
    show(C);
    show(F);
    move(&C, &F, &S, &troops1, &troops2);
    show(C);
    show(F);
    levelUp(&C, &S, &isSuccess);
    show(C);
    return 0;
}