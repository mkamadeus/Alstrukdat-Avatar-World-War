#include <stdio.h>
#include <stdlib.h>
#include "buildings.h"
#include "command.h"
#include "stack.h"

void createStack(stack * S){
    Top(*S) = NULL;
}

void deallocate(address * P){
    free(P);
}

void deleteAll(stack * S){
    int temp;
    while(!isEmpty(*S)){
        pop(S, &temp);
    }
}

address allocate(int X){
    address P = (address)malloc(sizeof(stackList));
	if(P != NULL){
		Info(P) = X;
		Next(P) = NULL;
	}

	return P;
}

boolean isEmpty(stack S){
    return (Top(S) == NULL);
}

void push(stack * S, int data){
    address P = allocate(data);
    if(P != NULL){
        if(isEmpty(*S)){
            Top(*S) = P;
        }
        else{
            Next(P) = Top(*S);
            Top(*S) = P;
        }
    }
}

int peek(stack * S){
    return (Info(Top(*S)));
}

void pop(stack * S, int * out){
    if(isEmpty(*S)){
        printf("Stack kosong\n");
    }
    else{
        address X;
        delA(S, &X);
        *out = Info(X);
        deallocate(&X);
    }
}

void delA(stack * S, address *P){
    *P = Top(*S);
    Top(*S) = Next(*P);
    Next(*P) = NULL;
}