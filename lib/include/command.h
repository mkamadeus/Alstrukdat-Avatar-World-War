/* File: command.h */
/* ADT yang berkaitan dengan command */

#ifndef command_H
#define command_H

#include "boolean.h"
#include "buildings.h"
#include "stack.h"

/* LIST INVERS */
/* 1 = inverseLevelUp */
/* 2 = inverseAttack */
/* 3 = inverseMove */
/* 8 = inverseInstantUpgrade */
/* 9 = inverseInstantReinforcement */
/* 10 = inverseBarrage */
/* 11 = inverseAttackUp */
/* 12 = inverseCriticalHit */

/* --------------------------------- */

void showBuildings();
/* Daftar bangunan yang bisa dieksekusi */

void levelUp(buildings * C, stack * S);
/* Meningkatkan level bangunan sebanyak 1 */

void inverseLevelUp(buildings * C);
/* Menurunkan level bangunan sebanyak 1 */

boolean isMax(buildings C);
/* Return true jika troops >= max_troops */

void increaseTroops(buildings * C);
/* Menambah jumlah troops sebanyak troops_regen */

void attack(buildings * C1, buildings * C2, boolean critical, boolean ignore, own P, stack * level, stack * before, stack * troops1, stack * troops2, stack * S);
/* Melakukan attack */

void inverseAttack(buildings * C1, buildings * C2, stack * level, stack * before, stack * troops1, stack * troops2);
/* Mengembalikan kondisi sebelum diserang */

void undo(buildings * C1, buildings * C2, stack * level, stack * before, stack * troops1 , stack * troops2 ,stack * S);
/* Melakukan undo */

void move(buildings * C1, buildings * C2, stack * S, stack * troops1, stack * troops2);
/* Memindahkan troops sebanyak troopsCount dari buildings C1 ke buildings C2 */

void inverseMove(buildings * C1, buildings * C2, stack * troops1, stack * troops2);
/* inverse dari Move */

#endif