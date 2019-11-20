/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "../include/mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
void START() {
    pita = fopen("pitakar.txt","r");
    EOP = false;
    ADV();
}

/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
void ADV() {
    // Advances if not EOF (return value of EOF when fscanf fails is -1)
    if (fscanf(pita,"%c",&CC)==EOF)
    {
        EOP = true;
        fclose(pita);
    }
}