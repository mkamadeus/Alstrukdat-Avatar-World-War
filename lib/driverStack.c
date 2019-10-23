#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(){
    stack S;
    int X;
    createStack(&S);
    for(int i = 0; i < 10; i++){
        printf("%d\n", capacity(S));
        push(&S,i);
    }
    pop(&S, &X);
    printf("peek = %d\n", peek(&S));
    printf("pop = %d\n", X);
    dealocate(&S);
    createStack(&S);
    push(&S, 102);
    printf("%d\n", peek(&S));
}