#include "../include/point.h"

/* *** Primitive Prototype *** */
/* *** Constructor *** */
buildingCoord makeBuildingCoord (buildings *building, int row, int col)
{
    buildingCoord C;
    row(C) = row;
    col(C) = col;
    C.building = building;
}

/* *** Write  *** */
void writeBuildingCoord (buildingCoord C)
//reading: <type> (<col>,<row>)
//example: Tower (1,13)
{
    if (C.building->type==1){printf("Castle ");}
    else if ((C.building->type)==2){printf("Tower ");}
    else if (C.building->type==3){printf("Fort ");}
    else if (C.building->type==4){printf("Village ");}
    printf("(%d,%d) ",col(C),row(C));
}