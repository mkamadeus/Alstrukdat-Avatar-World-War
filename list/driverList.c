#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
    linkedList L;
    int A;
    createEmpty(&L);
    insertValueFirst(&L, 1);
    printInfo(L);
    insertValueFirst(&L,2);
    printInfo(L);
    insertValueLast(&L,3);
    printInfo(L);
    deleteValueFirst(&L, &A);
    printf("A = %d\n", A);
    deleteValueLast(&L, &A);
    printf("A = %d\n", A);
    deleteValue(&L, 1);
    printInfo(L);
    return 0;
}