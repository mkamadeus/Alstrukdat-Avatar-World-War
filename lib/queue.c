#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void createEmpty (queue * Q, int Max)
{
	Q->first = Nil;
	Q->count = 0;
	Q->maxElement = Max;
}

boolean IsEmpty (queue Q)
{
	return (first(Q) == Nil);
}

boolean IsFull (queue Q)
{
	return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (queue Q)
{
	int x = 0;
	if (IsEmpty(Q)){
		return x;
	}
	address p = First(Q);
	while (p!= Last(Q)){
		x++;
		p = Next(p);
	}
	x++;
	return x;
}


void DeAlokasi(queue * Q)
{
	MaxEl(*Q) = 0;
	address n = First(*Q);
	address o = Next(First(*Q));
	while(n){
		free(n);
		n = o;
		o = Next(o);
		if(o == Nil){
			break;
		}
	}
}

void Add (queue * Q, infotype X)
{
	if (IsEmpty(*Q)){
		address l = Alokasi(X);
		Indeks(l) = 1;
		First(*Q) = l;
		Last(*Q) = l;
		return;
	}
	if(NBElmt(*Q)<MaxEl(*Q)){
		int h = Indeks(Last(*Q));
		address t = Alokasi(X);
		Indeks(t) = h + 1;
		Next(Last(*Q)) = t;
		Last(*Q) = t;
	}
}

void Del (queue * Q, infotype * X)
{
	if(Next(First(*Q)) == Nil){
		First(*Q) = Nil;
		Last(*Q) = Nil;
	}
	else{
		address temp = First(*Q);
		First(*Q) = Next(First(*Q));
	    Next(temp) = Nil;
		temp = First(*Q);
		while(temp!= Last(*Q)){
			Indeks(temp)--;
			temp = Next(temp);
		}
		Indeks(temp)--;
	}
}
