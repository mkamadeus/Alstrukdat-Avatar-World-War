#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
// Returns true if queue is empty
boolean isEmpty(queue Q)
{
=======
boolean isEmptyQueue(queue Q){
>>>>>>> yoga_3
    return (Head(Q) == unDef && Tail(Q) == unDef);
}

// Returns true if queue is full
boolean isFull(queue Q)
{
    return (NBElmt(Q) == MaxElement(Q));
}

<<<<<<< HEAD
// Queue element count
int NBElmt(queue Q)
{
    if(isEmpty(Q)) return 0;
=======
int NBElmt(queue Q){
    if(isEmptyQueue(Q)){
        return 0;
    }
>>>>>>> yoga_3
    else{
        if(Tail(Q) >= Head(Q)) return (Tail(Q) - Head(Q) + 1);
        else return (MaxElement(Q) - Head(Q) + Tail(Q) + 1);
    }
}

// Create empty queue
void createQueue(queue * Q, int Max)
{
    (*Q).T = (int *) malloc (sizeof(int) * (Max+1));
    // If allocation successful..
    if((*Q).T != NULL)
    {
        MaxElement(*Q) = Max;
        Head(*Q) = unDef;
        Tail(*Q) = unDef;
    }
}

// Deallocate queue
void dealokasi(queue * Q)
{
    free((*Q).T);
    MaxElement(*Q) = 0;
}

<<<<<<< HEAD
// Inserts new element to queue (last)
void Add(queue * Q, int X)
{
    if(isEmpty(*Q))
    {
=======
void Add(queue * Q, int X){
    if(isEmptyQueue(*Q)){
>>>>>>> yoga_3
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoHead(*Q) = X;
        InfoTail(*Q) = X;
    }
    else
    {
        if(!isFull(*Q))
        {
            Tail(*Q) += 1;
            if(Tail(*Q) > MaxElement(*Q))
            {
                Tail(*Q) = 1;
                InfoTail(*Q) = X;
            }
            else InfoTail(*Q) = X;
        }
        else printf("Queue sudah penuh\n");
    }
}

// Deletes the first element of the queue
void Del (queue * Q, int * X)
{
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q))
    {
        Head(*Q) = unDef;
        Tail(*Q) = unDef;
    }
    else
    {
        Head(*Q) += 1;
        if(Head(*Q) > MaxElement(*Q)) Head(*Q) = 1;
    }
}