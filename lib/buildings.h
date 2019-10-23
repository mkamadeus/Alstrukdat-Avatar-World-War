/* File : buildings.h */
/* ADT yang berkaitan dengan objek castle */

#ifndef buildings_H
#define buildings_H

#include "boolean.h"

typedef int own;
typedef int types;

/* Type */
/* 1 = Castle */
/* 2 = Tower */
/* 3 = Fort */
/* 4 = Village */ 

typedef struct {
    own owner;
    types type;
    int troops;
    int level;
    int troops_regen;
    int max_troops;
    boolean defense;
} buildings;

/* SELEKTOR */
#define owner(C) (C).owner
#define type(C) (C).type
#define troops(C) (C).troops
#define level(C) (C).level
#define troops_regen(C) (C).troops_regen
#define max_troops(C) (C).max_troops
#define defense(C) (C).defense

/* --------------------------------- */

void show(buildings C);
/* Mengeluarkan status bangunan */

void makeCastle(buildings * C, own P);
/* sebuah objek castle terbentuk */

void makeTower(buildings * C, own P);
/* sebuah objek tower terbentuk */

void makeFort(buildings * C, own P);
/* sebuah objek fort terbentuk */

void makeVillage(buildings * C, own P);
/* sebuah objek village terbentuk */

void levelOneCastle(buildings * C);
/* data level 1 castle */

void levelTwoCastle(buildings * C);
/* data level 2 castle */

void levelThreeCastle(buildings * C);
/* data level 3 castle */

void levelFourCastle(buildings * C);
/* data level 4 castle */   

void levelOneTower(buildings * C);
/* data level 1 tower */

void levelTwoTower(buildings * C);
/* data level 2 tower */

void levelThreeTower(buildings * C);
/* data level 3 tower */

void levelFourTower(buildings * C);
/* data level 4 tower */

void levelOneFort(buildings * C);
/* data level 1 fort */

void levelTwoFort(buildings * C);
/* data level 2 fort */

void levelThreeFort(buildings * C);
/* data level 3 fort */

void levelFourFort(buildings * C);
/* data level 4 fort */

void levelOneVillage(buildings * C);
/* data level 1 village */

void levelTwoVillage(buildings * C);
/* data level 2 village */

void levelThreeVillage(buildings * C);
/* data level 3 village */

void levelFourVillage(buildings * C);
/* data level 4 village */

#endif

