/* File : point.c */
/* point.h implementation */

#include "point.h"

// Allocate buildingCoord
buildingCoord* makeBuildingCoord (buildings *building, int row, int col)
{
    buildingCoord *C = (buildingCoord*) malloc(sizeof(buildingCoord));
    row(*C) = row;
    col(*C) = col;
    build(*C) = building;

    return C;
}

// Outputs building in format : <type> (<col>,<row>)
// For e.g : Tower (1,13)
void writeBuildingCoord (buildingCoord C)
{
    if (C.building->type==1){printf("Castle ");}
    else if ((C.building->type)==2){printf("Tower ");}
    else if (C.building->type==3){printf("Fort ");}
    else if (C.building->type==4){printf("Village ");}
    printf("(%d,%d) ",row(C),col(C));
}