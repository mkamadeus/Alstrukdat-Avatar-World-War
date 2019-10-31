/* File : stack.h */
/* ADT Stack yang berkaitan dengan Undo*/

#ifndef stack_H
#define stack_H

#include "boolean.h"


typedef int infotype;
typedef struct tStacklist *address;
typedef struct tStacklist{
    infotype info;
    address next;
} stackList;
typedef struct{
    address top;
} stack;

/* SELEKTOR */
#define Top(L) ((L).top)
#define Info(P) (P)->info
#define Next(P) (P)->next

/* --------------------------------- */

void createStack(stack * S);
/* Membuat stack dengan */

void dealocate(stack * S);
/* Menghapus stack */

boolean isEmpty(stack S);
/* return true jika kosong */

void push(stack * S, int data);
/* Menambahkan data ke dalam stack */

int peek(stack * S);
/* return content top */

void pop(stack * S, int * out);
/* Menyimpan content top ke out dan menghapus content top */

void delA(stack * S, address * P);
/* Menghapus address top dan menyimpannya ke P */

#endif