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

/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
void instantUpgrade(buildings * C, stack * S, stack * level);

/* Inverse dari instantUpgrade */
void inverseInstantUpgrade(buildings * C, stack * level);

/* Troops seluruh bangunan akan bertambah sebanyak 5 */
void instantReinforcement(buildings * C, stack * S);

/* Inverse dari instantReinforcement */
void inverseInstantReinforcement(buildings * C);

/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */
void barrage(buildings * C, stack * troop, stack * s);

/* Inverse dari Barrage */
void inverseBarrage(buildings * C, stack * troop);

/* Defense musuh diignore */
void attackUp(boolean * ignore, stack * S);

/* Inverse dari attackUp */
void inverseAttackUp(boolean * ignore, stack * S);

/* Pasukan saat menyerang hanya berkurang setengah */
void criticalHit(boolean * critical, stack * S);

/* inverse dari criticalHit */
void inverseCriticalHit(boolean * critical);

#endif