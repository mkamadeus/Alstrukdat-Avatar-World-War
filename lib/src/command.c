/* File: command.c */
/* command.h implementation */

#include "../include/command.h"

// Level up a building
void levelUp(buildings * C, stack * S, boolean * isSuccess){
    int minus, remains;
    minus = maxTroops(*C) >> 1;
    remains = troops(*C) - minus;
    if(level(*C) != 4)
    {
        if(remains >= 0)
        {
            push(S, 1);
            troops(*C) = remains;
            changeLevel(C, level(*C)+1);
            printf("Bangunan naik ke level %d\n", level(*C));
            *isSuccess = true;
        }
        else
        {
            printf("Pasukan tidak mencukupi\n");
            *isSuccess = false;
        }
    }
    else
    {
        printf("Bangunan sudah mencapai level maksimum\n");
        *isSuccess = false;
    }
}

// Returns troop count >= max troops
boolean isMax(buildings C)
{
    return (troops(C) >= maxTroops(C));
}

// Regen the troops
void increaseTroops(buildings * C)
{
    troops(*C) += troopsRegen(*C);
    if(isMax(*C)) troops(*C) = maxTroops(*C);
}

// Attack command : Attacks from C1 to C2
void attack(buildings * C1, buildings * C2, boolean * isCaptured, int troopsUsed, boolean * critical, boolean ignore, own P, stack * level, stack * before, stack * troops1, stack * troops2, stack * S, stack * crit)
{
    if(troopsUsed > troops(*C1)) printf("Pasukan tidak mencukupi\n");
    else
    {
        push(troops1, troops(*C1));
        push(troops2, troops(*C2));
        push(level, level(*C2));
        push(before, owner(*C2));

        if(*critical) push(crit, 1);
        else push(crit, 0);

        push(S, 2);

        int troopsAttacked;
        int troopsAttack = troopsUsed;

        printf("troops C2 awal = %d\n", troops(*C2));

        if(ignore && !(*critical))
        {
            troopsAttacked = troops(*C2);
            troops(*C2) -= troopsUsed;
        }
        else if((ignore && (*critical)) || ((*critical) && !ignore))
        {
            troopsAttacked = troops(*C2)/2;
            troops(*C2) -= 2*troopsUsed;
            *critical = false;
        }
        else
        {
            if(defense(*C2))
            {
                troopsAttacked = 4*troops(*C2)/3;
                troops(*C2) -= troopsUsed*3/4;
            }
            else
            {
                troopsAttacked = troops(*C2);
                troops(*C2) -= troopsUsed;
            }
        }

        printf("troops C2 = %d\n", troops(*C2));
        if(troops(*C2) <= 0)
        {
            printf("troopsAttack = %d\n", troopsAttack);
            printf("troopsAttacked = %d\n", troopsAttacked);
            owner(*C2) = P;
            changeLevel(C2, 1);
            troops(*C2) = troopsAttack - troopsAttacked;
            *isCaptured = true;
        }
        else *isCaptured = false;
        troops(*C1) -= troopsUsed;
    }
}

// void undo(buildings * C1, buildings * C2, boolean * critical ,stack * level, stack * before, stack * troops1 , stack * troops2 ,stack * S, stack * crit){
//     int command;
//     pop(S, &command);
//     if(command == 1){
//         inverseLevelUp(C1);
//     }
//     else if(command == 2){
//         inverseAttack(C1, C2, critical, level, before, troops1, troops2, crit);
//     }
//     else if(command == 3){
//         inverseMove(C1, C2, troops1, troops2);
//     }
// }

// Move command
void move(buildings * C1, buildings * C2, stack * S, stack * troops1, stack * troops2)
{
    push(S, 3);
    push(troops1, troops(*C1));
    push(troops2, troops(*C2));
    word troopsCount;
    int troopsCount_;

    do
    {
        printf("Masukkan jumlah pasukan: ");
        readSTDIN(&troopsCount);
        troopsCount_ = intConverter(troopsCount);
        if(troopsCount_ > troops(*C1)) printf("Jumlah pasukan tidak mencukupi\n");
    } while(troopsCount_ > troops(*C1));
    
    troops(*C1) -= troopsCount_;
    troops(*C2) += troopsCount_;
    printf("Pasukan berhasil dipindahkan\n");
}

/* -=-=-=-=-=-=-=-=- UNDO UTILITY FUNCTION -=-=-=-=-=-=-=-=- */

// Inverse of levelUp function
void inverseLevelUp(buildings * C){
    int plus;
    changeLevel(C, level(*C)-1);
    plus = maxTroops(*C)/2;
    troops(*C) += plus;
}

// Inverse of move function
void inverseMove(buildings * C1, buildings * C2, stack * troops1, stack * troops2){
    int troops_1, troops_2;
    pop(troops1, &troops_1);
    pop(troops2, &troops_2);
    troops(*C1) = troops_1;
    troops(*C2) = troops_2;
}

// Inverse of attack
void inverseAttack(buildings * C1, buildings * C2, boolean * critical ,stack * level, stack * before, stack * troops1, stack * troops2, stack * crit)
{
    int v_troops1, v_troops2, v_level;
    int v_critical;
    own v_before;

    pop(before, &v_before);
    pop(troops1, &v_troops1);
    pop(troops2, &v_troops2);
    pop(level, &v_level);
    pop(crit, &v_critical);

    if(v_critical == 1) *critical = true;
    else *critical = false;

    level(*C2) = v_level;
    troops(*C2) = v_troops2;
    troops(*C1) = v_troops1;
    owner(*C2) = v_before;
}
