/* File: matrix.c */
/* matrix.h implementation */

#include "../include/matrix.h"

// Creates an empty matrix with size NRxNC
void createEmptyMatrix(int NR, int NC, matrix * M)
{
    //Map size
    nRowEff(*M)=NR+1;
    nColEff(*M)=NC+1;
    for(int i=1;i<=nRowEff(*M);i++)
        for(int j=1;j<=nColEff(*M);j++)
        {
            buildingPtr(*M,i,j) = NULL; // give null pointer
        }
    //+1 for "*" border (upper and left border using zero (0) index)
    //structures in the map defined in [1..rowMax-1] and [1..colMax-1]
    //every fiend is EmptyField (' ')
    //to fill the blank with corresponding structure, use InsertStructure
}

// Return true if index [i,j] valid
boolean isIdxValid (int i, int j)
{
    return((i>=rowMin && i<=rowMax) && (j>=colMin && j<=colMax));
}

// Returns lowest index row M
index getFirstIdxRow (matrix M)
{
    return(rowMin);
}

// Returns lowest index column M
index getFirstIdxCol (matrix M)
{
    return(colMin);
}

// Returns highest index row M
index getLastIdxRow (matrix M)
{
    return(nRowEff(M));
}

// Returns highest index column M
index getLastIdxCol (matrix M)
{
    return(nColEff(M));
}

// Returns true if index [i,j] is effective index for M
boolean isIdxEff (matrix M, index i, index j)
{
    return(i==getLastIdxRow(M) && j==getLastIdxCol(M));
}

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
void insertStructure (matrix * M, buildingCoord *C)
{
    buildingPtr(*M,row(*C),col(*C)) = C;
}

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
void writeMatrix (matrix M)
{
    int i,j;
    char t;
    for(i=0;i<=getLastIdxRow(M);i++)
    {
        for(j=0;j<getLastIdxCol(M);j++)
        {
            if (i!=0 && j!=0 && i!=getLastIdxRow(M))
            {
                if (buildingPtr(M,i,j)!=NULL)
                {
                    //building type determiner
                    t = 'n';//undefined building (building not exist at the coordinate)
                    if (type(*build(*buildingPtr(M,i,j)))==1) t='C';
                    else if (buildingPtrType(M,i,j)==2) t='T';
                    else if (buildingPtrType(M,i,j)==3) t='F';
                    else if (buildingPtrType(M,i,j)==4) t='V';
                    //ownership determiner
                    if (buildingPtrOwner(M,i,j)==1) print_red(t);//player 1's, red
                    else if (buildingPtrOwner(M,i,j)==2) print_blue(t);//player 2's, blue
                    else printf("%c",t);//neurtral's, standard white
                }
                else printf(" ");
            }
            else printf("*");
        };
        printf("*\n");
    };
}