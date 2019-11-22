/* File : stack.c */
/* stack.h implementation */

#include "../include/stack.h"

// Creates an empty stack
void createStack(stack * S)
{
    Top(*S) = NULL;
}

// Deallocate a stack element
void deallocate(address_ P)
{
    free(P);
}

// Deallocate the whole stack
void deleteAll(stack * S)
{
    int temp;
    while(!isEmpty(*S)) pop(S, &temp);
}

// Allocate a stack element
address_ allocate(int X)
{
    address_ P = (address_)malloc(sizeof(stackList));
	if(P != NULL)
    {
		Info(P) = X;
		Next(P) = NULL;
	}

	return P;
}

// Return true if stack is empty
boolean isEmpty(stack S)
{
    return (Top(S) == NULL);
}

// Push a new element into the stack
void push(stack * S, int data)
{
    address_ P = allocate(data);
    if(P != NULL)
    {
        if(isEmpty(*S)) Top(*S) = P;
        else
        {
            Next(P) = Top(*S);
            Top(*S) = P;
        }
    }
}

// Peeks the top element
int peek(stack * S)
{
    return (Info(Top(*S)));
}

// Pops the topmost element of the stack
void pop(stack * S, int * out)
{
    if(isEmpty(*S)) printf("Stack kosong\n");
    else
    {
        address_ X;
        delA(S, &X);
        *out = Info(X);
        deallocate(&X);
    }
}

// Deletes topmost stack and return address to P
void delA(stack * S, address_ *P)
{
    *P = Top(*S);
    Top(*S) = Next(*P);
    Next(*P) = NULL;
}