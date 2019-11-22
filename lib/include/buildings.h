/* File : buildings.h */
/* ADT yang berkaitan dengan objek castle */

#ifndef buildings_H
#define buildings_H

#include "boolean.h"

typedef int own;
typedef int types;

typedef struct tBuildings *addressBuildings;
typedef struct tBuildings {
    own owner;
    types type;
    int troops;
    int level;
    int troopsRegen;
    int maxTroops;
    boolean defense;
} buildings;

#define owner(C) (C).owner
#define type(C) (C).type
#define troops(C) (C).troops
#define level(C) (C).level
#define troopsRegen(C) (C).troopsRegen
#define maxTroops(C) (C).maxTroops
#define defense(C) (C).defense

// Allocate buildings in heap
buildings* allocateBuilding();

// Show building status
void show(buildings C);

// Constructor for building type castle
void makeCastle(buildings * C, own P);

// Constructor for building type tower
void makeTower(buildings * C, own P);

// Constructor for building type fort
void makeFort(buildings * C, own P);

// Constructor for building type village
void makeVillage(buildings * C, own P);

// Change building level (and stats)
void changeLevel(buildings * C, int level);

#endif

