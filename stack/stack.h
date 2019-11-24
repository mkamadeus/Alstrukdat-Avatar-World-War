/* File : stack.h */
/* File to store ADT Stack (related to UNDO) */

#ifndef stack_H
#define stack_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef int infotype;
typedef struct tStacklist *address_;
typedef struct tStacklist{
    infotype info;
    address_ next;
} stackList;
typedef struct{
    address_ top;
} stack;

#define Top(L) ((L).top)
#define Info(P) (P)->info
#define Next(P) (P)->next

// Creates an empty stack
void createStack(stack * S);

// Allocate a stack element
address_ allocate(int X);

// Deallocate a stack element
void dealocate(address_ P);

// Deallocate the whole stack
void deleteAll(stack * S);

// Return true if stack is empty
boolean isEmptyStack(stack S);

// Push a new element into the stack
void push(stack * S, int data);

// Peeks the top element
int peek(stack * S);

// Pops the topmost element of the stack
void pop(stack * S, int * out);

// Deletes topmost stack and return address to P
void delA(stack * S, address_ * P);

#endif