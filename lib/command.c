#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "buildings.h"
#include "command.h"
#include "stack.h"


void showBuildings(int * N){
    /* TO DO */
    /* Menunggu ADT List*/
    /* Menambahkan daftar bangunan tergantung owner */

    printf("Daftar Bangunan:\n");
    printf("Bangunan yang akan di level up: ");
    scanf("%d", *N);
}

void levelUp(buildings * C, stack * S){
    /* TO DO */
    /* Menambahkan showBuildings */
    /* DEBUG */

    int minus, remains;
    minus = max_troops(*C) / 2;
    remains = troops(*C) - minus;
    if(level(*C) != 4){
        if(remains >= 0){
            push(S, 1);
            troops(*C) = remains;
            changeLevel(C, level(*C)+1);
        }
        else{
            printf("Pasukan tidak mencukupi\n");
        }
    }
    else{
        printf("Bangunan sudah mencapai level maksimum\n");
    }
}

void inverseLevelUp(buildings * C){
    int plus;
    changeLevel(C, level(*C)-1);
    plus = max_troops(*C)/2;
    troops(*C) += plus;
}

boolean isMax(buildings C){
    return (troops(C) >= max_troops(C));
}

void increaseTroops(buildings * C){
    troops(*C) += troops_regen(*C);
    if(isMax(*C)){
        troops(*C) = max_troops(*C);
    }
}

void attack(buildings * C1, buildings * C2, boolean critical, boolean ignore, own P, stack * level, stack * before, stack * troops1, stack * troops2, stack * S){
    /* C1 menyerang C2 */
    /* TO DO */
    /* Debug */

    int temp = troops(*C2);

    push(troops1, troops(*C1));
    push(troops2, troops(*C2));
    push(level, level(*C2));
    push(before, owner(*C2));
    push(S, 2);

    if(ignore){
        troops(*C2) -= troops(*C1);
    }
    else{
        if(defense(*C2)){
            troops(*C2) -= troops(*C1)*3/4;
        }
        else{
            troops(*C2) -= troops(*C1);
        }
    }
    if(critical){
        troops(*C1) -= temp/2;
    }
    else{
        troops(*C1) -= temp;
    }

    if(troops(*C2) <= 0){
        owner(*C2) = P;
        changeLevel(C2, 1);
        troops(*C2) = troops(*C1);
        troops(*C1) = 0;
    }

    if(troops(*C1) < 0){
        troops(*C1) = 0;
    }    
}

void inverseAttack(buildings * C1, buildings * C2, stack * level, stack * before, stack * troops1, stack * troops2){
    /* TO DO */
    /* DEBUG */

    int v_troops1, v_troops2, v_level;
    own v_before;
    pop(before, &v_before);
    pop(troops1, &v_troops1);
    pop(troops2, &v_troops2);
    pop(level, &v_level);
    level(*C2) = v_level;
    troops(*C2) = v_troops2;
    troops(*C1) = v_troops1;
    owner(*C2) = v_before;
}

void undo(buildings * C1, buildings * C2, stack * level, stack * before, stack * troops1 , stack * troops2 ,stack * S){
    int command;
    pop(S, &command);
    if(command == 1){
        inverseLevelUp(C1);
    }
    else if(command == 2){
        inverseAttack(C1, C2, level, before, troops1, troops2);
    }
}

void move(buildings * C1, buildings * C2, stack * S, stack * troops1, stack * troops2){
    /* Memindahkan pasukan dari C1 ke C2 */
    /* TO DO */
    /* DEBUG */
    push(S, 3);
    int troopsCount;
    do{
        scanf("%d", troopsCount);
        if(troopsCount > troops(*C1)){
            printf("Jumlah pasukan tidak mencukupi\n");
        }
    } while(troopsCount > troops(*C1));
    troops(*C1) -= troopsCount;
    troops(*C2) += troopsCount;
}

void inverseMove(buildings * C1, buildings * C2, stack * troops1, stack * troops2){
    /* TO DO */
    /* DEBUG */
    int troops_1, troops_2;
    pop(troops1, &troops_1);
    pop(troops2, &troops_2);
    troops(*C1) = troops_1;
    troops(*C2) = troops_2;
}