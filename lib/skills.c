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
    if(type(*C) == 1){
        if(level(*C) == 1){
            levelTwoCastle(C);
        }
        else if(level(*C) == 2){
            levelThreeCastle(C);
        }
        else if(level(*C) == 3){
            levelFourCastle(C);
        }
    }
    else if(type(*C) == 2){
        if(level(*C) == 1){
            levelTwoTower(C);
        }
        else if(level(*C) == 2){
            levelThreeTower(C);
        }
        else if(level(*C) == 3){
            levelFourTower(C);
        }
    }
    else if(type(*C) == 3){
        if(level(*C) == 1){
            levelTwoFort(C);
        }
        else if(level(*C) == 2){
            levelThreeFort(C);
        }
        else if(level(*C) == 3){
            levelFourFort(C);
        }
    }
    else{       //type(*C) == 4
        if(level(*C) == 1){
            levelTwoVillage(C);
        }
        else if(level(*C) == 2){
            levelThreeVillage(C);
        }
        else if(level(*C) == 3){
            levelFourVillage(C);
        }
    }
}

void inverseInstantUpgrade(buildings * C, stack * level){
    /* TO DO */
    /* DEBUG */
    int level_;
    pop(level, &level_);
    level(*C) = level_;
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
