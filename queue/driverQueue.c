#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    queue Q;
    int A;
    createQueue(&Q, 10);
    Add(&Q,1);
    Add(&Q,2);
    Add(&Q,3);
    Add(&Q,4);
    Add(&Q,5);
    Add(&Q,6);
    Add(&Q,7);
    Add(&Q,8);
    Add(&Q,9);
    Add(&Q,10);
    Del(&Q,&A);
    Add(&Q,11);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,12);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,13);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,14);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,15);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,16);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,17);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,18);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,19);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,20);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,21);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,22);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,23);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,24);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,25);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,26);
    printf("%d\n", A);
    Del(&Q,&A);
    Add(&Q,27);
    printf("%d\n", A);
    return 0;
}