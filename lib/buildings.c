#include <stdio.h>
#include <stdlib.h>
#include "buildings.h"

void show(buildings C){
    printf("Owner = %d\n", owner(C));
    if(type(C) == 1){
        printf("Type = Castle\n");
    }
    else if(type(C) == 2){
        printf("Type = Tower\n");
    }
    else if(type(C) == 3){
        printf("Type = Fort\n");
    }
    else{       //Type(C) == 4
        printf("Type = Village\n");
    }
    printf("Level = %d\n", level(C));
    printf("Troops = %d\n", troops(C));
    printf("Troops Regen = %d\n", troops_regen(C));
    printf("Max Troops = %d\n", max_troops(C));
    if(defense(C)){
        printf("Defense\n");
    }
    else{
        printf("No Defense\n");
    }
}

void makeCastle(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 1;
    changeLevel(C, 1);
    troops(*C) = 40;
}

void makeTower(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 2;
    changeLevel(C, 1);
    troops(*C) = 30;
}

void makeFort(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 3;
    changeLevel(C, 1);
    troops(*C) = 80;
}

void makeVillage(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 4;
    changeLevel(C, 1);
    troops(*C) = 20;
}

void changeLevel(buildings * C, int level){
    if(type(*C) == 1){
        int A[4] = {10,15,20,25};
        int M[4] = {40,60,80,100};
        boolean P[4] = {0,0,0,0};
        level(*C) = level;
        troops_regen(*C) = A[level+1];
        max_troops(*C) = M[level+1];
        defense(*C) = P[level+1];
    }
    else if(type(*C) == 2){
        int A[4] = {5,10,20,30};
        int M[4] = {20,30,40,50};
        boolean P[4] = {1,1,1,1};
        level(*C) = level;
        troops_regen(*C) = A[level+1];
        max_troops(*C) = M[level+1];
        defense(*C) = P[level+1];
    }
    else if(type(*C) == 3){
        int A[4] = {10,20,30,40};
        int M[4] = {20,40,60,80};
        boolean P[4] = {0,0,1,1};
        troops_regen(*C) = A[level+1];
        max_troops(*C) = M[level+1];
        defense(*C) = P[level+1];
    }
    else{       //type(*C) == 4
        int A[4] = {5,10,15,20};
        int M[4] = {20,30,40,50};
        boolean P[4] = {0,0,0,0};
        troops_regen(*C) = A[level+1];
        max_troops(*C) = M[level+1];
        defense(*C) = P[level+1];
    }
}