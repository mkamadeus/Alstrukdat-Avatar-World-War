#include "linkedlist.h"

// Test whether linked list is empty or not, first(L) = NULL
boolean isEmpty(linkedList L)
{
	return first(L)==NULL && last(L)==NULL;
}

// Empty linked list constructor
void createEmpty(linkedList *L)
{
	*L.first = NULL;
	*L.last = NULL;
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
void deallocateNode(address *P)
{
	free(*P);
}

// Returns the first node that contains X
address search(linkedList L, infotype X)
{
	address P = First(L);
	boolean found = false;

	while(!found && P != NULL) 
	{
		if(info(P)==X) found = true;
		else P = Next(P);
	}

	if(found) return P;
	else return NULL;
}

// Insert element containing X at the front of list
void insertValueFirst(linkedList *L, infotype X);

// Insert element containing X at the back of list
void insertValueLast(linkedList *L, infotype X);

// Insert element containing X at the front of list
void deleteValueFirst(linkedList *L, infotype *X);

// Insert element containing X at the back of list
void deleteValueLast(linkedList *L, infotype *X);

// Insert node at first if the node P has been allocated
void insertNodeFirst(linkedList *L, address P);

// Insert node at last if the node P has been allocated
void insertNodeLast(linkedList *L, address P);

// Insert node after Prev if the node P has been allocated
void insertNodeAfter(linkedList *L, address P, address Prev);

// Delete first node and return it to P (no deallocation)
void deleteNodeFirst(linkedList *L, address *P);

// Delete last node and return it to P (no deallocation)
void deleteNodeLast(linkedList *L, address *P);

// Delete node after Prev and return it to P (no deallocation)
void deleteNodeAfter(linkedList *L, address *P, address Prev);

// Return linked list length
int length(linkedList L);
