#ifndef queue_H
#define queue_H

#include <stdlib.h>
#include "boolean.h"

#define unDef 0

typedef struct{
    int * T;
    int HEAD;
    int TAIL;
    int MaxEl;
} queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElement(Q) (Q).MaxEl

boolean isEmpty(queue Q);

boolean isFull(queue Q);

int NBElmt(queue Q);

void createQueue(queue * Q, int Max);

void dealokasi(queue * Q);

void Add(queue * Q, int X);

void Del(queue * Q, int * X);

#endif