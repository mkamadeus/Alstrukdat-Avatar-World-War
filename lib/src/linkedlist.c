#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedlist.h"

// Test whether linked list is empty or not, first(L) = NULL
boolean isEmpty(linkedList L)
{
	return first(L)==NULL && last(L)==NULL;
}

// Empty linked list constructor
void createEmpty(linkedList *L)
{
	first(*L) = NULL;
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

// Returns the first node that contains X
address search(linkedList L, infotype X)
{
	address P = first(L);
	boolean found = false;

	while(!found && P != NULL) 
	{
		if(info(P)==X) found = true;
		else P = next(P);
	}

	if(found) return P;
	else return NULL;
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
	
	next(P) = first(*L); 
	first(*L) = P;
}

// Insert node at last if the node P has been allocated
void insertNodeLast(linkedList *L, address P)
{
	if(isEmpty(*L)) first(*L) = P;
	else next(last(*L)) = P;
	
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
	*P = first(*L);
	first(*L) = next(*P);
	next(*P) = NULL;

	if(first(*L)==NULL) last(*L) = NULL; 
}

// Delete last node and return it to P (no deallocation)
void deleteNodeLast(linkedList *L, address *P)
{
	*P = last(*L);

	address prec = NULL;
	address ls = first(*L);

	while(ls != last(*L))
	{
		prec = ls;
		ls = next(ls);
	}

	if(prec == NULL)
	{
		first(*L) = NULL;
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
	address P = first(L);
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
        address P=first(L);
        while(next(P)!=NULL)
        {
            printf("%d,",info(P));
            P = next(P);
        }
        printf("%d", info(P));
    }
    printf("]");
}