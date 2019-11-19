#include "../include/skills.h"

/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
void instantUpgrade(buildingsArray *buildingsID, linkedList listPlayer)
{
    address P = first(listPlayer);
    while(P != NULL)
    {
        // If level under 4..
        if(level(*Elmt(*buildingsID, info(P)))<4)
            level(*Elmt(*buildingsID, info(P)))++;
        P = next(P);
    }
}

/* Seluruh bangunan yang dimiliki oleh pemain akan memilki pertahanan selama 2 turn lawan */
void shield(buildingsArray *buildingsID, linkedList listPlayer)
{
    address P = first(listPlayer);
    while(P != NULL)
    {
        defense(*Elmt(*buildingsID, info(P))) = true;
        P = next(P);
    }
}

/* Utility function for shield, unshield yang seharusnya gak punya shield */
void unshield(buildingsArray *buildingsID, linkedList listPlayer)
{
    address P = first(listPlayer);
    while(P != NULL)
    {
        // Belom bisa
        // defense(*Elmt(*buildingsID, info(P)));
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
void instantReinforcement(buildingsArray *buildingsID, linkedList listPlayer)
{
    address P = first(listPlayer);
    while(P != NULL)
    {
        troops(*Elmt(*buildingsID, info(P)))+=5;
        P = next(P);
    }
}

/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */
void barrage(buildingsArray *buildingsID, linkedList listEnemy)
{
    address P = first(listPlayer);
    while(P != NULL)
    {
        if(troops(*Elmt(*buildingsID, info(P)))<=10) troops(*Elmt(*buildingsID, info(P)))=0;
        else troops(*Elmt(*buildingsID, info(P)))-=10;
        P = next(P);
    }
}

