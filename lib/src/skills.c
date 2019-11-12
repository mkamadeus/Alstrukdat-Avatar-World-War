#include <stdio.h>
#include <stdlib.h>
#include "../include/boolean.h"
#include "../include/buildings.h"
#include "../include/command.h"
#include "../include/stack.h"
#include "../include/skills.h"

/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
void instantUpgrade(buildings * C, stack * S, stack * level){
    /* TO DO */
    /* DEBUG */
    push(S, 8);
    push(level, level(*C));
    if(level(*C) != 4){
        changeLevel(C, level(*C)+1);
    }
}

/* Inverse dari instantUpgrade */
void inverseInstantUpgrade(buildings * C, stack * level){
    /* TO DO */
    /* DEBUG */
    int level_;
    pop(level, &level_);
    changeLevel(C, level_);
}

/* Troops seluruh bangunan akan bertambah sebanyak 5 */
void instantReinforcement(buildings * C, stack * S){
    push(S, 9);
    troops(*C) += 5;
}

/* Inverse dari instantReinforcement */
void inverseInstantReinforcement(buildings * C){
    troops(*C) -= 5;
}

/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */
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

/* Inverse dari Barrage */
void inverseBarrage(buildings * C, stack * troop){
    int troop_;
    pop(troop, &troop_);
    troops(*C) = troop_;
}

/* Defense musuh diignore */
void attackUp(boolean * ignore, stack * S){
    push(S, 11);
    *ignore = true;
}

/* Inverse dari attackUp */
void inverseAttackUp(boolean * ignore){
    *ignore = false;
}

/* Pasukan saat menyerang hanya berkurang setengah */
void criticalHit(boolean * critical, stack * S){
    push(S, 12);
    *critical = true;
}

/* inverse dari criticalHit */
void inverseCriticalHit(boolean * critical){
    *critical = false;
}