/* File : queue.h */
/* File to store ADT queue */

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

boolean isEmptyQueue(queue Q);

// Returns true if queue is full
boolean isFull(queue Q);

// Queue element count
int NBElmt(queue Q);

// Create empty queue
void createQueue(queue * Q, int Max);

// Deallocate queue
void dealokasi(queue * Q);

// Inserts new element to queue (last)
void Add(queue * Q, int X);

// Deletes the first element of the queue
void Del(queue * Q, int * X);

#endif