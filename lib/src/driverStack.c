#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(){
    stack S;
    int x, out;
    createStack(&S);
    push(&S, 5);
    push(&S, 8);
    push(&S, 9);
    pop(&S, &out);
    pop(&S, &out);
    // x = peek(&S);
    printf("%d\n", out);
    return 0;
}