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

void changeLevel(buildings * C, int level){
    if(type(*C) == 1){
        if(level == 1){
            level(*C) = 1;
            troops_regen(*C) = 10;
            max_troops(*C) = 40;
            defense(*C) = false;
        }
        else if(level == 2){
            level(*C) = 2;
            troops_regen(*C) = 15;
            max_troops(*C) = 60;
            defense(*C) = false;
        }
        else if(level == 3){
            level(*C) = 3;
            troops_regen(*C) = 20;
            max_troops(*C) = 80;
            defense(*C) = false; 
        }
        else{       //level == 4
            level(*C) = 4;
            troops_regen(*C) = 25;
            max_troops(*C) = 100;
            defense(*C) = false;
        }
    }
    else if(type(*C) == 2){
        if(level == 1){
            level(*C) = 1;
            troops_regen(*C) = 5;
            max_troops(*C) = 20;
            defense(*C) = true;
        }
        else if(level == 2){
            level(*C) = 2;
            troops_regen(*C) = 10;
            max_troops(*C) = 30;
            defense(*C) = true;
        }
        else if(level == 3){
            level(*C) = 3;
            troops_regen(*C) = 20;
            max_troops(*C) = 40;
            defense(*C) = true;
        }
        else{       //level == 4
            level(*C) = 4;
            troops_regen(*C) = 30;
            max_troops(*C) = 50;
            defense(*C) = true;
        }
    }
    else if(type(*C) == 3){
        if(level(*C) == 1){
            level(*C) = 1;
            troops_regen(*C) = 10;
            max_troops(*C) = 20;
            defense(*C) = false;
        }
        else if(level(*C) == 2){
            level(*C) = 2;
            troops_regen(*C) = 20;
            max_troops(*C) = 40;
            defense(*C) = false;
        }
        else if(level(*C) == 3){
            level(*C) = 3;
            troops_regen(*C) = 30;
            max_troops(*C) = 60;
            defense(*C) = true;
        }
        else{       //level == 4
            level(*C) = 4;
            troops_regen(*C) = 40;
            max_troops(*C) = 80;
            defense(*C) = true;
        }
    }
    else{       //type(*C) == 4
        if(level(*C) == 1){
            level(*C) = 1;
            troops_regen(*C) = 5;
            max_troops(*C) = 20;
            defense(*C) = false;
        }
        else if(level(*C) == 2){
            level(*C) = 2;
            troops_regen(*C) = 10;
            max_troops(*C) = 30;
            defense(*C) = false;
        }
        else if(level(*C) == 3){
            level(*C) = 3;
            troops_regen(*C) = 15;
            max_troops(*C) = 40;
            defense(*C) = false;
        }
        else{       //level == 4
            level(*C) = 4;
            troops_regen(*C) = 20;
            max_troops(*C) = 50;
            defense(*C) = false;
        }
    }
}
