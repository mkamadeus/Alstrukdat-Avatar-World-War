#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include "../../array/array.h"
#include "../../buildings/buildings.h"
#include "../../stack/stack.h"
#include "../../list/linkedlist.h"
#include "../../point/point.h"
#include "../../mesinKata/mesin.h"
#include "../../matrix/matrix.h"
#include "../../graph/graph.h"
#include "../../pcolor/pcolor.h"
#include "../../queue/queue.h"
#include "../../command/command.h"
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
