/* ********** TYPE Matrix definition with index dan coordinate ********** */

#ifndef ReadMatrix_H
#define ReadMatrix_H

#include "boolean.h"

/* minimum and maximum map size in row and column */
#define RowMin 1
#define RowMax 31
#define ColMin 1
#define ColMax 21
#define EmptyField ' '

typedef int index; /* index row, column */
typedef int ElType;
typedef struct {
    ElType Mem[RowMax+1][ColMax+1];
    int NRowEff; /* defined row size for max*/
    int NColEff; /* defined col size for max */
} Matrix;
/* 11 <= NRowEff <= 31 and 11<= NColEff <= 21 */
/* Indeks used: [0..RowMax][0..ColMax] */

/* ********** PRIMITIVE PROTOTYPE DEFINITION ********** */
/* *** Matrix Constructor *** */
void createEmpty (int NR, int NC, Matrix * M);
/* Creating "empty" matrix ready to use*/
/* I.S. NR dan NC are valid */
/* F.S. Matriks M created as defined above */

/* *** Selector *** */
#define NRowEff(M) (M).NRowEff
#define NColEff(M) (M).NColEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selector "Matrix" *** */
boolean isIdxValid (int i, int j);
/* Returns true if i, j is a valid index */

/* *** Selector: for a defined matrix M: *** */
index getFirstIdxRow (Matrix M);
/* Returns lowest index row M */
index getFirstIdxCol (Matrix M);
/* Returns lowest index column M */
index getLastIdxRow (Matrix M);
/* Returns highest index row M */
index getLastIdxCol (Matrix M);
/* Returns highest index column M */
boolean isIdxEff (Matrix M, index i, index j);
/* Returns true if i, j is effective index for M */

/* ********** Read/Write ********** */
void insertStructure (Matrix * M, int Row, int Col);
/* I.S. IsIdxValid(NR,NC) */
/* F.S. defined effective element of M , Size NR x NC */
/* Process: MakeMatrix(M,NR,NC) and write effective value */
/* then read element value per row and column */
/* Example: Jika NR = 15 dan NC = 10, then matrix entry :
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
void writeMatrix (Matrix M);
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