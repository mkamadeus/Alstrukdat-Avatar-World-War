#include "../include/matrix.h"

/* ********** PRIMITIVE PROTOTYPE DEFINITION ********** */
/* *** matrix Constructor *** */
void createEmptyMatrix(int NR, int NC, matrix * M)
/* Creating "empty" matrix ready to use*/
/* I.S. NR dan NC are valid */
/* F.S. Matriks M created as defined above */
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

/* *** Selector "matrix" *** */
boolean isIdxValid (int i, int j)
/* Returns true if i, j is a valid index */
{
    return((i>=rowMin && i<=rowMax) && (j>=colMin && j<=colMax));
}

/* *** Selector: for a defined matrix M: *** */
index getFirstIdxRow (matrix M)
/* Returns lowest index row M */
{
    return(rowMin);
}
index getFirstIdxCol (matrix M)
/* Returns lowest index column M */
{
    return(colMin);
}
index getLastIdxRow (matrix M)
/* Returns highest index row M */
{
    return(nRowEff(M));
}
index getLastIdxCol (matrix M)
/* Returns highest index column M */
{
    return(nColEff(M));
}
boolean isIdxEff (matrix M, index i, index j)
/* Returns true if i, j is effective index for M */
{
    return(i==getLastIdxRow(M) && j==getLastIdxCol(M));
}
/* ********** Read/Write ********** */
void insertStructure (matrix * M, buildingCoord *C)
/* I.S. isIdxValid(NR,NC) */
/* F.S. defined effective element of M , Size NR x NC */
/* Process: Makematrix(M,NB,NK) and write effective value */
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
{
    buildingPtr(*M,row(*C),col(*C)) = C;
    // printf("%d\n", buildingPtrType(*M,row(*C),col(*C)));
    // show(*build(*buildingPtr(*M,row(*C),col(*C))));
}
void writeMatrix (matrix M)
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