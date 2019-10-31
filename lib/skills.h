/* File: skills.h */
/* ADT yang berisi list skills */

#ifndef skills_H
#define skills_H

#include "boolean.h"
#include "buildings.h"
#include "command.h"
#include "stack.h"
#include "skills.h"

/* --------------------------------- */

void instantUpgrade(buildings * C, stack * S, stack * level);
/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */

void inverseInstantUpgrade(buildings * C, stack * level);
/* Inverse dari instantUpgrade */

void instantReinforcement(buildings * C, stack * S);
/* Troops seluruh bangunan akan bertambah sebanyak 5 */

void inverseInstantReinforcement(buildings * C);
/* Inverse dari instantReinforcement */

void barrage(buildings * C, stack * troop, stack * s);
/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */

void inverseBarrage(buildings * C, stack * troop);
/* Inverse dari Barrage */

void attackUp(boolean * ignore, stack * S);
/* Defense musuh diignore */

void inverseAttackUp(boolean * ignore, stack * S);
/* Inverse dari attackUp */

void criticalHit(boolean * critical, stack * S);
/* Pasukan saat menyerang hanya berkurang setengah */

void inverseCriticalHit(boolean * critical);
/* inverse dari criticalHit */

#endif