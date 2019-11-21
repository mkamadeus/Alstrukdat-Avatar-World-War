#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include "../../lib/include/array.h"
#include "../../lib/include/command.h"
#include "../../lib/include/buildings.h"
#include "../../lib/include/stack.h"
#include "../../lib/include/linkedlist.h"
#include "../../lib/include/point.h"
#include "../../lib/include/mesin.h"
#include "../../lib/include/matrix.h"
#include "../../lib/include/graph.h"
#include "../../lib/include/pcolor.h"
#include "../../lib/include/queue.h"
#include "../include/skills.h"

void changeTurn(int *turn);

void printBuildingConnected(graph G, int input, buildingsArray bangunan);

void printBuildings(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

void printEnemyBuildings(int turn, linkedList P1, linkedList P2, buildingsArray bangunan);

int inputToIndex(int turn, int input, linkedList P1, linkedList P2);

int inputToIndexEnemy(graph G, int input1, int input2, buildingsArray bangunan);

void printNearbyMyBuildings(graph G, int turn, int input, buildingsArray bangunan, int * count);

#endif