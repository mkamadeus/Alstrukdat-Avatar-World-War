#include "graph.h"

void createEmpty(graph* G)
{
	first(*G) = NULL;	
}

uAddress allocateNodeU(infotype N)
{
	uAddress P = (uAddress)malloc(sizeof(nodeU));
	if(P!= NULL)
	{
		info(P) = N;
		next(P) = NULL;
		child(P) = NULL;
	}
	return P;
}

vAddress allocateNodeV(infotype N)
{
	vAddress P = (vAddress)malloc(sizeof(nodeV));
	if(P != NULL)
	{
		info(P) = N;
		next(P) = NULL;
	}
	return P;
}

void createGraph(graph *G, int nodeCount)
{
	uAddress P = allocateNodeU(1);
	first(*G) = P;
	
	for(int i=2;i<=nodeCount;i++)
	{
		uAddress Ptemp = allocateNodeU(i);
		next(P) = Ptemp;
		P = Ptemp;
	}

}

void insertConnections(graph *G, int node, int *connections, int connectionsCount)
{
	uAddress P = first(*G);
	while(info(P) != node && P != NULL) P = next(P);

	if(P == NULL)
	{
		printf("Node invalid.\n")
		return;
	}
	else
	{
		vAddress Q = allocateNodeV(connections[0]);
		child(P) = Q;
		for(int i=1;i<connectionsCount;i++)
		{
			vAddress Qtemp = allocateNodeV(connections[i]);
			next(Q) = Qtemp;
			Q = Qtemp;
		}
	}
	
}
