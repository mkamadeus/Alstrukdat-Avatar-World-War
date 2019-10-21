#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ReadMatrix.h"

/* ********** PRIMITIVE PROTOTYPE DEFINITION ********** */
/* *** Matrix Constructor *** */
void createEmpty (int NR, int NC, Matrix * M)
/* Creating "empty" matrix ready to use*/
/* I.S. NR dan NC are valid */
/* F.S. Matriks M created as defined above */
{
    NRowEff(*M)=NR+1;
    NColEff(*M)=NC+1;
    //+1 for "*" border (upper and left border using zero (0) index)
    //structures in the map defined in [1..RowMax-1] and [1..ColMax-1]
    //every fiend is EmptyField (' ')
    //to fill the blank with corresponding structure, use InsertStructure
    for(int i=1;i<=NR;i++)
    {
        for(int j=1;j<=NC;j++)
        {
            Elmt(*M,i,j)=EmptyField;
        };
    };
}

/* *** Selector "Matrix" *** */
boolean isIdxValid (int i, int j)
/* Returns true if i, j is a valid index */
{
    return((i>=RowMin && i<=RowMax) && (j>=ColMin && j<=ColMax));
}

/* *** Selector: for a defined matrix M: *** */
index getFirstIdxRow (Matrix M)
/* Returns lowest index row M */
{
    return(RowMin);
}
index getFirstIdxCol (Matrix M)
/* Returns lowest index column M */
{
    return(ColMin);
}
index getLastIdxRow (Matrix M)
/* Returns highest index row M */
{
    return(NRowEff(M));
}
index getLastIdxCol (Matrix M)
/* Returns highest index column M */
{
    return(NColEff(M));
}
boolean isIdxEff (Matrix M, index i, index j)
/* Returns true if i, j is effective index for M */
{
    return(i==getLastIdxRow(M) && j==getLastIdxCol(M));
}
/* ********** Read/Write ********** */
void insertStructure (Matrix * M, int Row, int Col)
/* I.S. isIdxValid(NR,NC) */
/* F.S. defined effective element of M , Size NR x NC */
/* Process: MakeMatrix(M,NB,NK) and write effective value */
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
{
    //WIP
}
void writeMatrix (Matrix M)
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
{
    int i,j;
    for(i=0;i<=getLastIdxRow(M);i++)
    {
        for(j=0;j<getLastIdxCol(M);j++)
        {
            if (i!=0 && j!=0 && i!=getLastIdxRow(M)){printf("%c",Elmt(M,i,j));}
            else{printf("*");}
        };
        printf("*\n");
    };
}