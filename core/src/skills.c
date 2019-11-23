#include "../include/skills.h"

/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
void instantUpgrade(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2)
{
    if(turn == 1){
        address P = first(P1);
        while(P != NULL)
        {
            // If level under 4..
            if(level(*Build(*buildingsID, info(P)))<4){
                int t = level(*Build(*buildingsID, info(P)));
                changeLevel(Build(*buildingsID, info(P)),t+1);
            }
            P = next(P);
        }
    }
    else{
        address P = first(P2);
        while(P != NULL){
            if(level(*Build(*buildingsID, info(P)))<4){
                int t = level(*Build(*buildingsID, info(P)));
                changeLevel(Build(*buildingsID, info(P)),t+1);
            }
            P = next(P);
        }
    }
}

/* Seluruh bangunan yang dimiliki oleh pemain akan memilki pertahanan selama 2 turn lawan */
void shield(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2, boolean * isShieldActiveP1, boolean * shieldActivatedP1, boolean * isShieldActiveP2, boolean * shieldActivatedP2)
{
    if(turn == 1){
        address P = first(P1);
        while(P != NULL)
        {
            defense(*Build(*buildingsID, info(P))) = true;
            P = next(P);
        }
        *isShieldActiveP1 = true;
        *shieldActivatedP1 = true;
    }
    else{
        address P = first(P2);
        while(P != NULL)
        {
            defense(*Build(*buildingsID, info(P))) = true;
            P = next(P);
        }
        *isShieldActiveP2 = true;
        *shieldActivatedP2 = true;
    }
}

/* Utility function for shield, unshield yang seharusnya gak punya shield */
void unshield(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2)
{
    address P;
    if(turn == 1){
        P = first(P1);
    }
    else{
        P = first(P2);
    }
    while(P != NULL)
    {
        if(type(*Build(*buildingsID, Info(P))) == 1){
            defense(*Build(*buildingsID, Info(P))) = false;
        }
        else if(type(*Build(*buildingsID, Info(P))) == 4){
            defense(*Build(*buildingsID, Info(P))) = false;
        }
        else if(type(*Build(*buildingsID, Info(P))) == 3){
            if((level(*Build(*buildingsID, Info(P))) == 2) || (level(*Build(*buildingsID, Info(P))) == 1)){
                defense(*Build(*buildingsID, Info(P))) = false;
           }
        }
        P = next(P);
    }
}

/* Extra turn! */
void extraTurn(boolean * isExtraTurn)
{
    *isExtraTurn = true;
}

/* Defense musuh diignore */
void attackUp(boolean * ignore)
{
    *ignore = true;
}

/* Pasukan saat menyerang hanya berkurang setengah */
void criticalHit(boolean * critical)
{
    *critical = true;
}

/* Troops seluruh bangunan akan bertambah sebanyak 5 */
void instantReinforcement(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2)
{
    address P; 
    if(turn == 1){
        P = first(P1);
    }
    else{
        P = first(P2);
    }
    while(P != NULL)
    {
        troops(*Build(*buildingsID, info(P)))+=5;
        P = next(P);
    }
}

/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */
void barrage(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2)
{
    address P;
    if(turn == 1){
        P = first(P1);
    }
    else{
        P = first(P2);
    }
    while(P != NULL)
    {
        if(troops(*Build(*buildingsID, info(P)))<=10) troops(*Build(*buildingsID, info(P)))=0;
        else troops(*Build(*buildingsID, info(P)))-=10;
        P = next(P);
    }
}

int lengthTurnNow(int turn, linkedList P1, linkedList P2){
    if(turn == 1){
        return length(P2);
    }
    else{
        return length(P1);
    }
}

void shieldTriggered(queue * skill1, queue * skill2, int turn){
    if(turn == 1){
        Add(skill2,2);
        printf("Player 2 Mendapatkan Shield\n");
    }
    else{
        Add(skill1,2);
        printf("Player 1 Mendapatkan Shield\n");
    }
}

int fortCounter(linkedList P1, linkedList P2, buildingsArray bangunan, int turn){
    int count = 0;
    if(turn == 1){
        address P = first(P2);
        while(P != NULL){
            int fort = type(*Build(bangunan,info(P)));
            if(fort == 3){
                count++;
            }
            P = Next(P);
        }
    }
    else{
        address P = first(P1);
        while(P != NULL){
            int fort = type(*Build(bangunan,info(P)));
            if(fort == 3){
                count++;
            }
            P = Next(P);
        }
    }
    return count;
}

void extraTurnTriggered(queue * skill1, queue * skill2, int turn){
    if(turn == 1){
        Add(skill2, 3);
        printf("Player 2 Mendapatkan Extra Turn\n");
    }
    else{
        Add(skill1, 3);
        printf("Player 1 Mendapatkan Extra Turn\n");
    }
}

int towerCounter(linkedList P1, linkedList P2, buildingsArray bangunan, int turn){
    int count = 0;
    if(turn == 1){
        address P = first(P1);
        while(P != NULL){
            int tower = type(*Build(bangunan,info(P)));
            if(tower == 2){
                count++;
            }
            P = Next(P);
        }
    }
    else{
        address P = first(P2);
        while(P != NULL){
            int tower = type(*Build(bangunan,info(P)));
            if(tower == 2){
                count++;
            }
            P = Next(P);
        }
    }

    return count;
}

void attackUpTriggered(queue * skill1, queue * skill2, int turn){
    if(turn == 1){
        Add(skill1,4);
        printf("Player 1 Mendapatkan Attack Up\n");
    }
    else{
        Add(skill2,4);
        printf("Player 2 Mendapatkan Attack Up\n");
    }
}

void criticalHitTriggered(queue * skill1, queue * skill2, int turn){
    if(turn == 1){
        Add(skill2,5);
        printf("Player 2 Mendapatkan Critical Hit\n");
    }
    else{
        Add(skill1,5);
        printf("Player 1 Mendapatkan Critical Hit\n");
    }
}

void instantReinforcementTriggered(queue * skill1, queue * skill2, buildingsArray bangunan, linkedList P1, linkedList P2, int turn){
    int count = 0;
    if(turn == 1){
        address P = first(P1);
        while(P != NULL){
            int l = level(*Build(bangunan,info(P)));
            if(l == 4){
                count++;
            }
            P = Next(P);
        }
        if(count == length(P1)){
            Add(skill1, 6);
            printf("Player 1 Mendapatkan Skill Instant Reinforcement\n");
        }
    }
    else{
        address P = first(P2);
        while(P != NULL){
            int l = level(*Build(bangunan,info(P)));
            if(l == 2){
                count++;
            }
            P = Next(P);
        }
        if(count == length(P2)){
            Add(skill2, 6);
            printf("Player 2 Mendapatkan Skill Instant Reinforcement\n");
        }
    }
}

int lengthTurnMine(int turn, linkedList P1, linkedList P2){
    if(turn == 1){
        return (length(P1));
    }
    else{
        return (length(P2));
    }
}

void barrageTriggered(queue * skill1, queue * skill2, linkedList P1, linkedList P2, int turn){
    if(turn == 1){
        if(length(P1) == 10){
            Add(skill2,7);
            printf("Player 2 Mendapatkan Skill Barrage\n");
        }
    }
    else{
        if(length(P2) == 10){
            Add(skill1,7);
            printf("Player 1 Mendapatkan Skill Barrage\n");
        }
    }
}