/* File: skills.h */
/* ADT yang berisi list skills */

#ifndef __SKILLS_H__
#define __SKILLS_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../lib/include/boolean.h"
#include "../../lib/include/buildings.h"
#include "../../lib/include/command.h"
#include "../../lib/include/stack.h"
#include "../../lib/include/linkedlist.h"
#include "../../lib/include/array.h"

/* --------------------------------- */

/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
void instantUpgrade(buildingsArray *buildingsID, linkedList listPlayer);

/* Seluruh bangunan yang dimiliki oleh pemain akan memilki pertahanan selama 2 turn lawan */
void shield(buildingsArray *buildingsID, linkedList listPlayer);

/* Utility function for shield, unshield yang seharusnya gak punya shield */
void unshield(buildingsArray *buildingsID, linkedList listPlayer);

/* Extra turn! */
void extraTurn(boolean * isExtraTurn);

/* Defense musuh diignore */
void attackUp(boolean * ignore);

/* Pasukan saat menyerang hanya berkurang setengah */
void criticalHit(boolean * critical);

/* Troops seluruh bangunan akan bertambah sebanyak 5 */
void instantReinforcement(buildingsArray *buildingsID, linkedList listPlayer);

/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */
void barrage(buildingsArray *buildingsID, linkedList listEnemy);

#endif