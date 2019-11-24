#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include "../../lib/include/array.h"
#include "../../lib/include/buildings.h"
#include "../../lib/include/stack.h"
#include "../../lib/include/linkedlist.h"
#include "../../lib/include/point.h"
#include "../../lib/include/mesin.h"
#include "../../lib/include/matrix.h"
#include "../../lib/include/graph.h"
#include "../../lib/include/pcolor.h"
#include "../../lib/include/queue.h"
#include "../include/command.h"
#include "../include/skills.h"

void changeTurn(int *turn);

void printEnemyBuildingConnected(graph G, int turn, int input, buildingsArray bangunan, int * output);

void printBuildings(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

void printEnemyBuildings(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

int inputToIndex(int turn, int input, linkedList P1, linkedList P2);

int inputToIndexMine(graph G, int turn, int input1, int input2, buildingsArray bangunan);

int inputToIndexEnemy(graph G, int turn, int input1, int input2, buildingsArray bangunan);

void printNearbyMyBuildings(graph G, int turn, int input, buildingsArray bangunan, int * count);

void firstInterface(queue skill1, queue skill2, int turn);

void interfaceInsideAttack(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

void levelUpInterface(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

void searchBInterface(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

void deleteAllStack(stack * S, stack * level, stack * before, stack * troops1, stack * troops2, stack * crit);

void createAllStack(stack * S, stack * level, stack * before, stack * troops1, stack * troops2, stack * crit);

void mainMenu();

void commandInterface();

void buildingStatusInterface(buildingsArray bangunan, linkedList flagAttack, linkedList flagMove, int turn);

#endif
