#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedlist.h"

// Test whether linked list is empty or not, firstList(L) = NULL
boolean isEmpty(linkedList L)
{
	return firstList(L)==NULL && last(L)==NULL;
}

// Empty linked list constructor
void createEmpty(linkedList *L)
{
	firstList(*L) = NULL;
	last(*L) = NULL;
}

// Allocate a new node with its content of X at return address
address allocateNode(infotype X)
{
	address P = (address)malloc(sizeof(node));
	if(P != NULL)
	{
		info(P) = X;
		next(P) = NULL;
	}

	return P;
}

// Deallocate node at address P
void deallocateNode(address P)
{
	free(P);
}

// Returns the firstList node that contains X
address search(linkedList L, infotype X)
{
	address P = firstList(L);
	boolean found = false;

	while(!found && P != NULL) 
	{
		if(info(P)==X) found = true;
		else P = next(P);
	}

	if(found) return P;
	else return NULL;
}

// Returns boolean when find X
boolean searchB(linkedList L, infotype X){
	address P = firstList(L);
	boolean found = false;
	while(!found && P != NULL){
		if(info(P) == X){
			found = true;
		}
		else{
			P = next(P);
		}
	}
	return found;
}

// Insert element containing X at the front of list
void insertValueFirst(linkedList *L, infotype X)
{
	address P = allocateNode(X);

	if(P != NULL) insertNodeFirst(L, P);
}

// Insert element containing X at the back of list
void insertValueLast(linkedList *L, infotype X)
{
	address P = allocateNode(X);
	if(P != NULL) insertNodeLast(L, P);
}

// Insert element containing X at the front of list
void deleteValueFirst(linkedList *L, infotype *X)
{
	address P;
	deleteNodeFirst(L, &P);
	*X = info(P);
	deallocateNode(P);
}

void deleteValue(linkedList *L, infotype X){
	address Y = firstList(*L);
	address prec;
	int count = 0;
    if(!isEmpty(*L)){
        while(info(Y) != X && next(Y) != NULL){
            prec = Y;
            Y = next(Y);
            count++;
        }
        if(info(Y) == X){
            if(count != 0){
                next(prec) = next(Y);
                deallocateNode(Y);
            }
            else{
                if(length(*L) != 1){
                    firstList(*L) = next(firstList(*L));
                }
                else{
                    createEmpty(L);
                }
            }
        }
    }
}

// Insert element containing X at the back of list
void deleteValueLast(linkedList *L, infotype *X)
{
	address P;
	deleteNodeLast(L, &P);
	*X = info(P);
	deallocateNode(P);
}

// Insert node at first if the node P has been allocated
void insertNodeFirst(linkedList *L, address P)
{
	if(isEmpty(*L)) last(*L) = P;
	
	next(P) = firstList(*L); 
	firstList(*L) = P;
}

// Insert node at last if the node P has been allocated
void insertNodeLast(linkedList *L, address P)
{
	if(isEmpty(*L)) {
		firstList(*L) = P;
	}
	else {
		next(last(*L)) = P;
	}
	last(*L) = P;
}

// Insert node after Prev if the node P has been allocated
void insertNodeAfter(linkedList *L, address P, address Prev)
{
	next(P) = next(Prev);
	next(Prev) = P;
}

// Delete first node and return it to P (no deallocation)
void deleteNodeFirst(linkedList *L, address *P)
{
	*P = firstList(*L);
	firstList(*L) = next(*P);
	next(*P) = NULL;

	if(firstList(*L)==NULL) last(*L) = NULL; 
}

// Delete last node and return it to P (no deallocation)
void deleteNodeLast(linkedList *L, address *P)
{
	*P = last(*L);

	address prec = NULL;
	address ls = firstList(*L);

	while(ls != last(*L))
	{
		prec = ls;
		ls = next(ls);
	}

	if(prec == NULL)
	{
		firstList(*L) = NULL;
		last(*L) = NULL;	
	}
	else
	{
		next(prec) = NULL;
		last(*L) = prec;
	}

}

// Delete node after Prev and return it to P (no deallocation)
void deleteNodeAfter(linkedList *L, address *P, address Prev)
{
	*P = next(Prev);
	next(Prev) = next(*P);
	next(*P) = NULL;
}

// Return linked list length
int length(linkedList L)
{
	address P = firstList(L);
	int result = 0;

	while(P != NULL)
	{
		P = next(P);
		result++;
	}

	return result;
}

void printInfo (linkedList L)
{
    printf("[");
    if(!isEmpty(L))
    {
        address P=firstList(L);
        while(next(P)!=NULL)
        {
            printf("%d,",info(P));
            P = next(P);
        }
        printf("%d", info(P));
    }
    printf("]");
}

void deleteEverything(linkedList * L){
	int X;
	while(firstList(*L) != NULL){
		deleteValueLast(L,&X);
	}
}