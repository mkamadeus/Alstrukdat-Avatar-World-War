/* File: matrix.h */
/* File yang berkaitan dengan matriks*/

#ifndef matrix_H
#define matrix_H

#include "boolean.h"
#include "point.h"
#include "pcolor.h"
#include <stdio.h>

/* minimum and maximum map size in row and column */
#define rowMin 1
#define rowMax 31
#define colMin 1
#define colMax 21
#define emptyField ' '

typedef int index; /* index row, column */
typedef struct {
    buildingCoord *buildingPtr[rowMax+1][colMax+1];
    int nRowEff; /* defined row size for max*/
    int nColEff; /* defined col size for max */
} matrix;
/* 11 <= nRowEff <= 31 and 11<= nColEff <= 21 */
/* Indeks used: [0..rowMax][0..colMax] */

/* ********** PRIMITIVE PROTOTYPE DEFINITION ********** */
/* *** matrix Constructor *** */
void createEmpty (int NR, int NC, matrix * M);
/* Creating "empty" matrix ready to use*/
/* I.S. NR dan NC are valid */
/* F.S. Matriks M created as defined above */

/* *** Selector *** */
#define nRowEff(M) (M).nRowEff
#define nColEff(M) (M).nColEff
#define buildingPtr(M,i,j) (M).buildingPtr[(i)][(j)]

/* *** Selector "matrix" *** */
boolean isIdxValid (int i, int j);
/* Returns true if i, j is a valid index */

/* *** Selector: for a defined matrix M: *** */
index getFirstIdxRow (matrix M);
/* Returns lowest index row M */
index getFirstIdxCol (matrix M);
/* Returns lowest index column M */
index getLastIdxRow (matrix M);
/* Returns highest index row M */
index getLastIdxCol (matrix M);
/* Returns highest index column M */
boolean isIdxEff (matrix M, index i, index j);
/* Returns true if i, j is effective index for M */

/* ********** Read/Write ********** */
void insertStructure (matrix * M, buildingCoord C);
/* I.S. IsIdxValid(NR,NC) */
/* F.S. defined effective element of M , Size NR x NC */
/* Process: Makematrix(M,NR,NC) and write effective value */
/* then read element value per row and column */
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
void writeMatrix (matrix M);
/* I.S. M defined */
/* F.S. Value of M(i,j) printed per row per column*/
/* Process: print per row and per column*/
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
#endif