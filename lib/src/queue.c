#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

boolean isEmptyQueue(queue Q){
    return (Head(Q) == unDef && Tail(Q) == unDef);
}

boolean isFull(queue Q){
    return (NBElmt(Q) == MaxElement(Q));
}

int NBElmt(queue Q){
    if(isEmptyQueue(Q)){
        return 0;
    }
    else{
        if(Tail(Q) >= Head(Q)){
            return (Tail(Q) - Head(Q) + 1);
        }
        else{
            return (MaxElement(Q) - Head(Q) + Tail(Q) + 1);
        }
    }
}

void createQueue(queue * Q, int Max){
    (*Q).T = (int *) malloc (sizeof(int) * (Max+1));
    if((*Q).T != NULL){
        MaxElement(*Q) = Max;
        Head(*Q) = unDef;
        Tail(*Q) = unDef;
    }
    else{
        MaxElement(*Q) = 0;
    }
}

void dealokasi(queue * Q){
    free((*Q).T);
    MaxElement(*Q) = 0;
}

void Add(queue * Q, int X){
    if(isEmptyQueue(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoHead(*Q) = X;
        InfoTail(*Q) = X;
    }
    else{
        if(!isFull(*Q)){
            Tail(*Q) += 1;
            if(Tail(*Q) > MaxElement(*Q)){
                Tail(*Q) = 1;
                InfoTail(*Q) = X;
            }
            else{
                InfoTail(*Q) = X;
            }
        }
        else{
            printf("Queue sudah penuh\n");
        }
    }
}

void Del (queue * Q, int * X){
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        Head(*Q) = unDef;
        Tail(*Q) = unDef;
    }
    else{
        Head(*Q) += 1;
        if(Head(*Q) > MaxElement(*Q)){
            Head(*Q) = 1;
        }
    }
}