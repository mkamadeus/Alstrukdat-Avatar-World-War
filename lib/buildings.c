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
    level(*C) = 1;
    troops(*C) = 40;
    troops_regen(*C) = 10;
    max_troops(*C) = 40;
    defense(*C) = false;
}

void makeTower(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 2;
    level(*C) = 1;
    troops(*C) = 30;
    troops_regen(*C) = 5;
    max_troops(*C) = 20;
    defense(*C) = true;
}

void makeFort(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 3;
    level(*C) = 1;
    troops(*C) = 80;
    troops_regen(*C) = 10;
    max_troops(*C) = 20;
}

void makeVillage(buildings * C, own P){
    owner(*C) = P;
    type(*C) = 4;
    level(*C) = 1;
    troops(*C) = 20;
    troops_regen(*C) = 5;
    max_troops(*C) = 20;
}

void levelOneCastle(buildings * C){
    level(*C) = 1;
    type(*C) = 1;
    troops_regen(*C) = 10;
    max_troops(*C) = 40;
    defense(*C) = false;
}

void levelTwoCastle(buildings * C){
    level(*C) = 2;
    type(*C) = 1;
    troops_regen(*C) = 15;
    max_troops(*C) = 60;
    defense(*C) = false;
}

void levelThreeCastle(buildings * C){
    level(*C) = 3;
    type(*C) = 1;
    troops_regen(*C) = 20;
    max_troops(*C) = 80;
    defense(*C) = false;
}

void levelFourCastle(buildings * C){
    level(*C) = 4;
    type(*C) = 1;
    troops_regen(*C) = 25;
    max_troops(*C) = 100;
    defense(*C) = false;
}

void levelOneTower(buildings * C){
    level(*C) = 1;
    type(*C) = 2;
    troops_regen(*C) = 5;
    max_troops(*C) = 20;
    defense(*C) = true;
}

void levelTwoTower(buildings * C){
    level(*C) = 2;
    type(*C) = 2;
    troops_regen(*C) = 10;
    max_troops(*C) = 30;
    defense(*C) = true;
}

void levelThreeTower(buildings * C){
    level(*C) = 3;
    type(*C) = 2;
    troops_regen(*C) = 20;
    max_troops(*C) = 40;
    defense(*C) = true;
}

void levelFourTower(buildings * C){
    level(*C) = 4;
    type(*C) = 2;
    troops_regen(*C) = 30;
    max_troops(*C) = 50;
    defense(*C) = true;
}

void levelOneFort(buildings * C){
    level(*C) = 1;
    type(*C) = 3;
    troops_regen(*C) = 10;
    max_troops(*C) = 20;
    defense(*C) = false;
}

void levelTwoFort(buildings * C){
    level(*C) = 2;
    type(*C) = 3;
    troops_regen(*C) = 20;
    max_troops(*C) = 40;
    defense(*C) = false;
}

void levelThreeFort(buildings * C){
    level(*C) = 3;
    type(*C) = 3;
    troops_regen(*C) = 30;
    max_troops(*C) = 60;
    defense(*C) = true;
}

void levelFourFort(buildings * C){
    level(*C) = 4;
    type(*C) = 3;
    troops_regen(*C) = 40;
    max_troops(*C) = 80;
    defense(*C) = true;
}

void levelOneVillage(buildings * C){
    level(*C) = 1;
    type(*C) = 4;
    troops_regen(*C) = 5;
    max_troops(*C) = 20;
    defense(*C) = false;
}

void levelTwoVillage(buildings * C){
    level(*C) = 2;
    type(*C) = 4;
    troops_regen(*C) = 10;
    max_troops(*C) = 30;
    defense(*C) = false;
}

void levelThreeVillage(buildings * C){
    level(*C) = 3;
    type(*C) = 4;
    troops_regen(*C) = 15;
    max_troops(*C) = 40;
    defense(*C) = false;
}

void levelFourVillage(buildings * C){
    level(*C) = 4;
    type(*C) = 4;
    troops_regen(*C) = 20;
    max_troops(*C) = 50;
    defense(*C) = false;
}