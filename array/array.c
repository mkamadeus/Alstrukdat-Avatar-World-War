/* File : array.c */
/* array.h implementation */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Constructor for buildingsArray
void makeEmptyArray(buildingsArray * T, int maxel)
{
    TI(*T) = (ElType *) malloc ((maxel+1)*sizeof(ElType));
    Neff(*T)=0;
    MaxEl(*T)=maxel;
}

// Destructor for buildingsArray
void dealokasiArray(buildingsArray *T)
{
	free (TI(*T));
	MaxEl(*T)=0;
	Neff(*T)=0;
}

// Procedure for reading building
void bacaIsi(buildingsArray *T, buildingCoord *C)
{
    ++Neff(*T);
    Elmt(*T,Neff(*T)) = C;
}

// Output all buildings on the field
void tulisIsiTab(buildingsArray T)
{
    printf("Building on field:\n");
    for(int i = 1;i<=Neff(T);i++)
    {
        printf("%d.\n");
        show(*Build(T,i));
        printf("=====================\n");
    }
}

// Output buildings based on type
void printOnType(buildingsArray T, char type)
{
    if (type == 'C'|| type == 'T'|| type == 'V'|| type == 'F' )
    {
        printf("Building on field:\n");
        for(int i = 1;i<=Neff(T);i++)
        {
            if(type(*Build(T,i)) == type)
            {
                printf("%d.\n");
                show(*Build(T,i));
                printf("=====================\n");
            }
        }
    }
}

// Output buildings based on owner
void printOnOwner(buildingsArray T, own owner)
{
    if (owner == 1|| owner == 2|| owner == 0)
    {
        printf("Building on field:\n");
        for(int i = 1;i<=Neff(T);i++)
        {
            if(owner(*Build(T,i)) == owner)
            {
                printf("%d.\n");
                show(*Build(T,i));
                printf("=====================\n");
            }
        }
    }
}