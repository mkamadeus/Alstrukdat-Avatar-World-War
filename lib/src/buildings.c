#include <stdio.h>
#include <stdlib.h>
#include "../include/buildings.h"

// Allocate buildings in heap
addressBuildings allocateBuilding()
{
    addressBuildings ptr = (addressBuildings)malloc(sizeof(buildings));
    return ptr;
}

// Show building status
void show(buildings C){
    // Print owner status
    printf("Owner = %d\n", owner(C));

    // Print building type
    printf("Type = ");
    if(type(C) == 1) printf("Castle\n");
    else if(type(C) == 2) printf("Tower\n");
    else if(type(C) == 3) printf("Fort\n");
    else if(type(C) == 4) printf("Village\n");

    // Print building type
    printf("Level = %d\n", level(C));
    printf("Troops = %d\n", troops(C));
    printf("Troops Regen = %d\n", troopsRegen(C));
    printf("Max Troops = %d\n", maxTroops(C));

    // Print defense status
    if(defense(C)) printf("Defense\n");
    else printf("No defense\n");
}

// Constructor for building type castle
void makeCastle(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 1;
    changeLevel(C, 1);
    troops(*C) = 40;
}

// Constructor for building type tower
void makeTower(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 2;
    changeLevel(C, 1);
    troops(*C) = 30;
}

// Constructor for building type fort
void makeFort(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 3;
    changeLevel(C, 1);
    troops(*C) = 80;
}

// Constructor for building type village
void makeVillage(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 4;
    changeLevel(C, 1);
    troops(*C) = 20;
}

// Change building level (and stats)
void changeLevel(buildings * C, int level){
    if(type(*C) == 1)
    {
        int A[4] = {10,15,20,25};
        int M[4] = {40,60,80,100};
        boolean P[4] = {0,0,0,0};
        level(*C) = level;
        troopsRegen(*C) = A[level-1];
        maxTroops(*C) = M[level-1];
        defense(*C) = P[level-1];
    }
    else if(type(*C) == 2)
    {
        int A[4] = {5,10,20,30};
        int M[4] = {20,30,40,50};
        boolean P[4] = {1,1,1,1};
        level(*C) = level;
        troopsRegen(*C) = A[level-1];
        maxTroops(*C) = M[level-1];
        defense(*C) = P[level-1];
    }
    else if(type(*C) == 3)
    {
        int A[4] = {10,20,30,40};
        int M[4] = {20,40,60,80};
        boolean P[4] = {0,0,1,1};
        level(*C) = level;
        troopsRegen(*C) = A[level-1];
        maxTroops(*C) = M[level-1];
        defense(*C) = P[level-1];
    }
    else if(type(*C) == 4)
    {
        int A[4] = {5,10,15,20};
        int M[4] = {20,30,40,50};
        boolean P[4] = {0,0,0,0};
        level(*C) = level;
        troopsRegen(*C) = A[level-1];
        maxTroops(*C) = M[level-1];
        defense(*C) = P[level-1];
    }
}