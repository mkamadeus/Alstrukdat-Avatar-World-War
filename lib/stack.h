/* File : stack.h */
/* ADT Stack yang berkaitan dengan Undo*/

#ifndef stack_H
#define stack_H

#include "boolean.h"

#define Nil -1

typedef struct{
    int capacity;
    int top;
    int *content;
}stack;

/* SELEKTOR */
#define capacity(S) (S).capacity
#define top(S) (S).top
#define content(S) (S)->content

/* --------------------------------- */

void createStack(stack * S);
/* Membuat stack dengan size 1 */

void dealocate(stack * S);
/* Menghapus stack */

void resize(stack * S);
/* Menambahkan size stack sebanyak 1 */

boolean isFull(stack S);
/* return true jika penuh */

boolean isEmpty(stack S);
/* return true jika kosong */

void push(stack * S, int data);
/* Menambahkan data ke dalam stack */

int peek(stack * S);
/* return content top */

void pop(stack * S, int * out);
/* Menyimpan content top ke out dan menghapus content top */

#endif