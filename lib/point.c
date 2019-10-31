#include "point.h"

/* *** Primitive Prototype *** */
/* *** Constructor *** */
buildingCoord makeBuildingCoord (buildings building, int row, int col)
{
    buildingCoord C;
    row(C) = row;
    col(C) = col;
    build(C) = building;
}

/* *** Write  *** */
void writeBuildingCoord (buildingCoord C)
//reading: <type> (<col>,<row>)
//example: Tower (1,13)
{
    if (type(build(C))==1) printf("Castle ");
    else if (type(build(C))==2) printf("Tower ");
    else if (type(build(C))==3) printf("Fort ");
    else if (type(build(C))==4) printf("Village ");
    printf("(%d,%d) ",col(C),row(C));
}