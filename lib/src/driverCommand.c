#include "command.c"
#include "buildings.c"
#include "stack.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    buildings C, F;
    stack S, level, before, troops1, troops2, crit;
    own P;
    boolean critical = true;
    boolean ignore = false;
    createStack(&S);
    createStack(&level);
    createStack(&before);
    createStack(&troops1);
    createStack(&troops2);
    createStack(&crit);
    makeCastle(&C,2);
    makeFort(&F,1);
    troops(C) = 30;
    defense(C) = true;
    troops(F) = 14;
    show(C);
    printf("\n");
    show(F);
    printf("\n\n");
    attack(&F,&C, 10, &critical, ignore, 1, &level, &before, &troops1, &troops2, &S, &crit);
    printf("===================================\n");
    show(C);
    printf("\n");
    show(F);
    printf("\n");
}