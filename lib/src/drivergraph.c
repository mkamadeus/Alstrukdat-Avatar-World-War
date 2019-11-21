#include "../include/graph.h"
#include <stdio.h>

int main()
{  
    int n=5;
    graph G;
    createGraph(&G,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j) insertChild(&G, i, j);
        }
    }

    printGraph(G);
}