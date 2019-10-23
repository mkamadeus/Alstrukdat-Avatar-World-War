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

void instantUpgrade(buildings * C);
/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */

void instantReinforcement(buildings * C);
/* Troops seluruh bangunan akan bertambah sebanyak 5 */

void barrage(buildings * C);
/* Troops pada seluruh bangunan musuh akan berkurang sebanyak 10 */

#endif