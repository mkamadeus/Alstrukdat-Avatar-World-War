/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

void START();
/* Mesin Karakter mulai dioperasikan */

void ADV();
/* Maju satu karakter pada pita */

#endif