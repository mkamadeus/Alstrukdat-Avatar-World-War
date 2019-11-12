#include <stdio.h>
#include <stdlib.h>
#include "../include/boolean.h"
#include "../include/buildings.h"
#include "../include/command.h"
#include "../include/stack.h"
#include "../include/skills.h"

void instantUpgrade(buildings * C){
    /* TO DO */
    /* DEBUG */
    if(level(*C) != 4){
        changeLevel(C, level(*C)+1);
    }
}

void instantReinforcement(buildings * C){
    /* QUESTION */
    /* Apakah bisa bertambah lebih dari Max Troops? */
    /* BISA */
    troops(*C) += 5;
}

void barrage(buildings * C){
    /* TO DO */ 
    /* DEBUG */
    troops(*C) -= 10;
    if(troops(*C) < 0){
        troops(*C) = 0;
    }
}

void attackUp(boolean * ignore){
    *ignore = true;
}

void criticalHit(boolean * critical){
    *critical = true;
}