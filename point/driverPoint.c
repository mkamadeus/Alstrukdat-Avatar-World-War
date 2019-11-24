#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(){
    buildingCoord *A;
    buildings B; 
    makeCastle(&B, 1);
    A = makeBuildingCoord(&B,1,1);
    writeBuildingCoord(*A);
    return 0;
}