/* File: command.h */
/* File for storing commands */

#ifndef command_H
#define command_H

#include <stdio.h>
#include <stdlib.h>
#include "../../lib/include/boolean.h"
#include "../../lib/include/buildings.h"
#include "../../lib/include/stack.h"
#include "../../lib/include/mesin.h"

// Show building connections
void showConnections(graph G, buildingsArray* arr, int buildingID);

// Level up a building
void levelUp(buildings * C, stack * S, boolean * isSuccess);

// Returns troop count >= max troops
boolean isMax(buildings C);

// Regen the troops
void increaseTroops(buildings * C);

// Attack command : Attacks from C1 to C2
void attack(buildings * C1, buildings * C2, boolean * isCaptured, int troopsUsed, boolean * critical, boolean ignore, own P, stack * level, stack * before, stack * troops1, stack * troops2, stack * S, stack * crit);

// Undo command
void undo(buildings * C1, buildings * C2, stack * level, stack * before, stack * troops1 , stack * troops2 ,stack * S);

// Move command
void move(buildings * C1, buildings * C2, stack * S, stack * troops1, stack * troops2);

/* -=-=-=-=-=-=-=-=- UNDO UTILITY FUNCTION -=-=-=-=-=-=-=-=- */

// Inverse of levelUp function
void inverseLevelUp(buildings * C);

// Inverse of move function
void inverseMove(buildings * C1, buildings * C2, stack * troops1, stack * troops2);

// Inverse of attack
void inverseAttack(buildings * C1, buildings * C2, boolean * critical ,stack * level, stack * before, stack * troops1, stack * troops2, stack * crit);

#endif