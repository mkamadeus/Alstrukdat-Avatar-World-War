#ifndef point_H
#define point_H

#include "boolean.h"
#include "buildings.h"

typedef struct {
    buildings building;
	int row; /* row   */
	int col; /* col */
} buildingCoord;
/*reading in config*/
/*<buildingType> <row> <col>*/

//point refers to coordinates
/* *** coordinate selector *** */
#define row(C) (C).row //Y pos
#define col(C) (C).col //X pos
#define build(C) (C).building

/* *** Primitive Prototype *** */
/* *** Constructor *** */
buildingCoord makeBuildingCoord (buildings building, int row, int col);

/* *** Read/Write  *** */
void writeBuildingCoord (buildingCoord C);
//reading: <type> (<col>,<row>)
//example: Tower (1,13)
#endif