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
#include "../../lib/include/queue.h"

/* --------------------------------- */

/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
void instantUpgrade(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2);

/* Seluruh bangunan yang dimiliki oleh pemain akan memilki pertahanan selama 2 turn lawan */
void shield(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2, boolean * isShieldActive);

/* Utility function for shield, unshield yang seharusnya gak punya shield */
void unshield(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2);

/* Extra turn! */
void extraTurn(boolean * isExtraTurn);

/* Defense musuh diignore */
void attackUp(boolean * ignore);

/* Pasukan saat menyerang hanya berkurang setengah */
void criticalHit(boolean * critical);

/* Troops seluruh bangunan akan bertambah sebanyak 5 */
void instantReinforcement(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2);

/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */
void barrage(buildingsArray *buildingsID, int turn, linkedList P1, linkedList P2);

int lengthTurnNow(int turn, linkedList P1, linkedList P2);

void shieldTriggered(queue * skill1, queue * skill2, int turn);

int fortCounter(linkedList P1, linkedList P2, buildingsArray bangunan, int turn);

void extraTurnTriggered(queue * skill1, queue * skill2, int turn);

int towerCounter(linkedList P1, linkedList P2, buildingsArray bangunan, int turn);

void attackUpTriggered(queue * skill1, queue * skill2, int turn);

void criticalHitTriggered(queue * skill1, queue * skill2, int turn);

void instantReinforcementTriggered(queue * skill1, queue * skill2, buildingsArray bangunan, linkedList P1, linkedList P2, int turn);

void barrageTriggered(queue * skill1, queue * skill2, linkedList P1, linkedList P2, int turn);

#endif