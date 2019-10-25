/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
/* Mesin Karakter mulai dioperasikan */
    pita = fopen("pitakar.txt","r");
    ADV();
}

void ADV() {
/* Maju satu karakter pada pita */

    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}