#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "boolean.h"

typedef int infotype;
typedef struct tNode *address;
typedef struct tNode {
  infotype info;
  address next;
} node;
typedef struct {
  address first;
  address last;
} linkedList;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)
#define last(L) ((L).last)

// Test whether linked list is empty or not, first(L) = NULL
boolean isEmpty(linkedList L);

// Empty linked list constructor
void createEmpty(linkedList *L);

// Allocate a new node with its content of X at return address
address allocateNode(infotype X);

// Deallocate node at address P
void deallocateNode(address *P);

// Returns the first node that contains X
address search(linkedList L, infotype X);

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

#endif