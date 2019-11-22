/* File : point.h */
/* File to store ADT point */

#ifndef point_H
#define point_H

#include "boolean.h"
#include "buildings.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    buildings *building;
	int row; 
	int col; 
} buildingCoord;

#define row(C) (C).row //Y pos
#define col(C) (C).col //X pos
#define build(C) (C).building

// Allocate building cord
buildingCoord* makeBuildingCoord (buildings *building, int row, int col);

// Outputs building in format : <type> (<col>,<row>)
// For e.g : Tower (1,13)
void writeBuildingCoord (buildingCoord C);
#endif