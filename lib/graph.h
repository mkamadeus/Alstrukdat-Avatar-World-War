#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "boolean.h"

typedef int infotype;
typedef struct tNodeU* uAddress;
typedef struct tNodeV* vAddress;
typedef struct tNodeU {
	infotype info;
	vAddress child;
	uAddress next; 
} nodeU;
typedef struct tNodeV {
	infotype info;
	vAddress nextChild;
} nodeV;
typedef struct {
	uAddress first;
} graph;
typedef struct {
	vAddress firstChild;
} graphChild;

#define info(P) (P)->info
#define next(P) (P)->next
#define child(P) (P)->child
#define first(L) ((L).first)
#define firstChild(L) ((L).firstChild)

void createEmpty(graph* G);

uAddress allocateNodeU(infotype N);

vAddress allocateNodeV(infotype N);

void createGraph(graph *G, int nodeCount);

void insertConnections(graph *G, int node, int *connections, int connectionsCount);

#endif