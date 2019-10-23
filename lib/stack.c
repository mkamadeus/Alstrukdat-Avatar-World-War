#include <stdio.h>
#include <stdlib.h>
#include "buildings.h"
#include "command.h"
#include "stack.h"

void createStack(stack * S){
    int *content;
    content = (int *) malloc (sizeof(int) * 5);

    if(content == NULL){
        printf("Failed to create stack");
    }

    content(S) = content;
    capacity(*S) = 5;
    top(*S) = 0;
}

void dealocate(stack * S){
    free(content(S));
    capacity(*S) = 0;
    top(*S) = 0;
}

void resize(stack * S){
    content(S) = (int *) realloc (content(S), sizeof(int) * (capacity(*S) * 2));
    capacity(*S)++;
}

boolean isFull(stack S){
    return (capacity(S) == top(S));
}

boolean isEmpty(stack S){
    return (top(S) == 0);
}

void push(stack * S, int data){
    if(isFull(*S)){
        resize(S);
    }
    top(*S)++;
    content(S)[top(*S)] = data;
}

int peek(stack * S){
    return (content(S)[top(*S)]);
}

void pop(stack * S, int * out){
    if(isEmpty(*S)){
        printf("Stack kosong");
    }
    else{
        *out = content(S)[top(*S)];
        top(*S)--;
    }
}