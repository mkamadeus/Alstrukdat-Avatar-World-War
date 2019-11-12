
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void makeEmptyArray(TabInt * T, int maxel)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    TI(*T) = (ElType *) malloc ((maxel+1)*sizeof(ElType));
    Neff(*T)=0;
    MaxEl(*T)=maxel;
}

void dealokasiArray(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
	free (TI(*T));
	MaxEl(*T)=0;
	Neff(*T)=0;
}

void bacaIsi(TabInt *T, buildings C)
/*add pointer inside array to building*/
{
    Neff(*T)++;
    Elmt(*T,Neff(*T)) = &C;
}

/* CAUTION: ARRAY MUST NOT EMPTY */
void tulisIsiTab(TabInt T)
/*Prints every building available on field*/
{
    printf("Building on field:\n");
    for(int i = 1;i<=Neff(T);i++)
    {
        printf("%d.\n");
        show(*(Elmt(T, i)));
        printf("=====================\n");
    }
}

void printOnType(TabInt T, char X)
/* Print based on type*/
{
    if (X == 'C'|| X == 'T'|| X == 'V'|| X == 'F' )
    {
        printf("Building on field:\n");
        for(int i = 1;i<=Neff(T);i++)
        {
            if(Elmt(T,i)->type == X)
            {
                printf("%d.\n");
                show(*(Elmt(T, i)));
                printf("=====================\n");
            }
        }
    }
    else printf("Salah input goblok\n");
}

void printOnOwner(TabInt T, own X)
/* Print based on owner*/
{
    if (X == 1|| X == 2|| X == 0)//nunggu fix ownershipnya
    {
        printf("Building on field:\n");
        for(int i = 1;i<=Neff(T);i++)
        {
            if(Elmt(T,i)->owner == X)
            {
                printf("%d.\n");
                show(*(Elmt(T, i)));
                printf("=====================\n");
            }
        }
    }
    else printf("Salah input goblok\n");
}

