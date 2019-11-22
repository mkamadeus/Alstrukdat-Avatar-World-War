/* File : array.h */
/* Header file for ADT Array */

#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"
#include "buildings.h"
#include "point.h"

#define IdxMin 1

typedef int IdxType;
typedef buildingCoord *ElType;
typedef struct
{
  ElType *TI;
  int Neff;
  int MaxEl;
} buildingsArray;

#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl
#define Build(T,i) (Elmt(T, i))->building

// Constructor for buildingsArray
void makeEmptyArray(buildingsArray *T, int maxel);

// Destructor for buildingsArray
void dealokasiArray(buildingsArray *T);

// Procedure for reading building
void bacaIsi(buildingsArray *T, buildingCoord *C);

// Output all buildings on the field
void tulisIsiTab(buildingsArray T);

// Output buildings based on type
void printOnType(buildingsArray T, char type);

// Output buildings based on owner
void printOnOwner(buildingsArray T, own owner);

#endif