#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

int main(){
    queue Q;
    int A;
    createQueue(&Q, 10);
    add(&Q,1);
    add(&Q,2);
    add(&Q,3);
    add(&Q,4);
    add(&Q,5);
    add(&Q,6);
    add(&Q,7);
    add(&Q,8);
    add(&Q,9);
    add(&Q,10);
    Del(&Q,&A);
    add(&Q,11);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,12);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,13);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,14);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,15);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,16);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,17);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,18);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,19);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,20);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,21);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,22);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,23);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,24);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,25);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,26);
    printf("%d\n", A);
    Del(&Q,&A);
    add(&Q,27);
    printf("%d\n", A);
    return 0;
}