#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "buildings.h"
#include "command.h"
#include "stack.h"
#include "skills.h"

void instantUpgrade(buildings * C, stack * S, stack * level){
    /* TO DO */
    /* DEBUG */
    push(S, 8);
    push(level, level(*C));
    if(level(*C) != 4){
        changeLevel(C, level(*C)+1);
    }
}

void inverseInstantUpgrade(buildings * C, stack * level){
    /* TO DO */
    /* DEBUG */
    int level_;
    pop(level, &level_);
    changeLevel(C, level_);
}

void instantReinforcement(buildings * C, stack * S){
    /* QUESTION */
    /* Apakah bisa bertambah lebih dari Max Troops? */
    /* BISA */
    push(S, 9);
    troops(*C) += 5;
}

void inverseInstantReinforcement(buildings * C){
    troops(*C) -= 5;
}

void barrage(buildings * C, stack * troop, stack * S){
    /* TO DO */ 
    /* DEBUG */
    push(S, 10);
    push(troop, troops(*C));
    troops(*C) -= 10;
    if(troops(*C) < 0){
        troops(*C) = 0;
    }
}

void inverseBarrage(buildings * C, stack * troop){
    int troop_;
    pop(troop, &troop_);
    troops(*C) = troop_;
}

void attackUp(boolean * ignore, stack * S){
    push(S, 11);
    *ignore = true;
}

void inverseAttackUp(boolean * ignore){
    *ignore = false;
}

void criticalHit(boolean * critical, stack * S){
    push(S, 12);
    *critical = true;
}

void inverseCriticalHit(boolean * critical){
    *critical = false;
}