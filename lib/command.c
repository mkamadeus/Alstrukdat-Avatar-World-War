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

    int minus, remains;
    minus = max_troops(*C) / 2;
    remains = troops(*C) - minus;
    if(type(*C) == 1){
        if(level(*C) == 1){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelTwoCastle(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 2){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelThreeCastle(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 3){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelFourCastle(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else{       //Level 4
            printf("Bangunan sudah mencapai level maksimum\n");
        }
    }
    else if(type(*C) == 2){
        if(level(*C) == 1){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelTwoTower(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 2){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelThreeTower(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 3){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelFourTower(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else{       //Level 4
            printf("Bangunan sudah mencapai level maksimum\n");
        }
    }
    else if(type(*C) == 3){
        if(level(*C) == 1){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelTwoFort(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 2){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelThreeFort(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 3){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelFourFort(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else{       //Level 4
            printf("Bangunan sudah mencapai level maksimum\n");
        }
    }
    else{           //Types 4 
        if(level(*C) == 1){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelTwoVillage(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 2){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelThreeVillage(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else if(level(*C) == 3){
            if(remains >= 0){
                push(S, 1);
                troops(*C) = remains;
                levelFourVillage(C);
            }
            else{
                printf("Pasukan tidak mencukupi\n");
            }
        }
        else{       //Level 4
            printf("Bangunan sudah mencapai level maksimum\n");
        }
    }
}

void inverseLevelUp(buildings * C){
    int plus;
    if(type(*C) == 1){
        if(level(*C) == 4){
            plus = 40;
            levelThreeCastle(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 3){
            plus = 30;
            levelTwoCastle(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 2){
            plus = 20;
            levelOneCastle(C);
            troops(*C) += plus;
        }
    }
    else if(type(*C) == 2){
        if(level(*C) == 4){
            plus = 20;
            levelThreeTower(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 3){
            plus = 15;
            levelTwoTower(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 2){
            plus = 10;
            levelOneTower(C);
            troops(*C) += plus;
        }
    }
    else if(type(*C) == 3){
        if(level(*C) == 4){
            plus = 30;
            levelThreeFort(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 3){
            plus = 20;
            levelTwoFort(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 2){
            plus = 10;
            levelOneFort(C);
            troops(*C) += plus;
        }
    }
    else{       //Type 4
        if(level(*C) == 4){
            plus = 20;
            levelThreeVillage(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 3){
            plus = 15;
            levelTwoVillage(C);
            troops(*C) += plus;
        }
        else if (level(*C) == 2){
            plus = 10;
            levelOneVillage(C);
            troops(*C) += plus;
        }
    }
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

void attack(buildings * C1, buildings * C2, boolean ignore, own P, stack * level, stack * before, stack * troops1, stack * troops2, stack * S){
    /* C1 menyerang C2 */
    /* TO DO */
    /* Debug */

    int temp = troops(*C1);

    push(troops1, troops(*C1));
    push(troops2, troops(*C2));
    push(level, level(*C2));
    push(before, owner(*C2));
    push(S, 2);

    if(ignore){
        troops(*C1) -= troops(*C2);
        troops(*C2) -= temp;
    }
    else{
        troops(*C1) -= troops(*C2);
        if(defense(*C2)){
            troops(*C2) -= temp*3/4;
        }
        else{
            troops(*C2) -= temp;
        }
    }

    if(troops(*C2) <= 0){
        owner(*C2) = P;
        if(type(*C2) == 1){
            levelOneCastle(C2);
        }
        else if(type(*C2) == 2){
            levelOneTower(C2);
        } 
        else if(type(*C2) == 3){
            levelOneFort(C2);
        }
        else{       // type(*C2) == 4
            levelOneVillage(C2);
        }
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
