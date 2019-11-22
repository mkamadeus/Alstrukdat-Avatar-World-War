/* File: matrix.h */
/* File to store ADT Matrix */

#ifndef matrix_H
#define matrix_H

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "pcolor.h"

#define rowMin 1
#define rowMax 31
#define colMin 1
#define colMax 21
#define emptyField ' '

typedef int index;

//11 <=a nRowEff <= 31 and 11<= nColEff <= 21
// Index used: [0..rowMax][0..colMax]
typedef struct {
    buildingCoord *buildingPtr[rowMax+1][colMax+1];
    int nRowEff;
    int nColEff;
} matrix;


#define nRowEff(M) (M).nRowEff
#define nColEff(M) (M).nColEff
#define buildingPtr(M,i,j) (M).buildingPtr[(i)][(j)]
#define buildingPtrType(M,i,j) (M).buildingPtr[(i)][(j)]->building->type
#define buildingPtrOwner(M,i,j) (M).buildingPtr[(i)][(j)]->building->owner

// Creates an empty matrix with size NRxNC
void createEmptyMatrix(int NR, int NC, matrix * M);

// Return true if index [i,j] valid
boolean isIdxValid (int i, int j);

// Returns lowest index row M
index getFirstIdxRow (matrix M);

// Returns lowest index column M
index getFirstIdxCol (matrix M);

// Returns highest index row M
index getLastIdxRow (matrix M);

// Returns highest index column M
index getLastIdxCol (matrix M);

// Returns true if index [i,j] is effective index for M
boolean isIdxEff (matrix M, index i, index j);

// Insert structure in M based on C
/* Example: if NR = 15 dan NC = 10, then matrix entry (provided every structure already inserted) :
C       V   ​T​ ​C​
  C            
T      V     ​C​ 
    F          
           F   
  T            
         T     
 ​C​   ​V​        T
            C  
​C​ T           C
NB: depends on coordinate points
*/
void insertStructure (matrix * M, buildingCoord *C);

// Prints out matrix based on matrix 
/* Example: prints 10x15 map (bordered by * from 0 to size+1)
*****************
*C       V   ​T​ ​C​*
*  C            *
*T      V     ​C​ *
*    F          *
*           F   *
*  T            *
*         T     *
* ​C​   ​V​        T*
*            C  *
*​C​ T           C*
*****************  
*/
void writeMatrix (matrix M);

#endif