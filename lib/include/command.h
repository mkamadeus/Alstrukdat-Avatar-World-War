/* File: command.h */
/* File for storing commands */

#ifndef command_H
#define command_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "buildings.h"
#include "stack.h"
#include "mesin.h"

<<<<<<< HEAD
// Level up a building
=======
/* LIST INVERS */
/* 1 = inverseLevelUp */
/* 2 = inverseAttack */
/* 3 = inverseMove */

/* --------------------------------- */

void showBuildings();
/* Daftar bangunan yang bisa dieksekusi */

>>>>>>> yoga_3
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