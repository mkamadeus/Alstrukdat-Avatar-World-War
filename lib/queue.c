#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

infotype Head(Queue Q){
	return Indeks(First(Q));
}

infotype Tail(Queue Q){
	return Indeks(Last(Q));
}

infotype InfoHead(Queue Q){
	return Info(First(Q));
}

infotype InfoTail(Queue Q){
	return Info(Last(Q));
}


boolean IsEmpty (Queue Q){
	return (First(Q) == Nil && Last(Q) == Nil);
}

address Alokasi (infotype X){
	address P;
	P = (address)malloc(sizeof(Elmtq));
	if (P == Nil){
		return Nil;
	}
	Indeks(P) = 0;
	Info(P) = X;
	Next(P) = Nil;
	return P;
}


boolean IsFull (Queue Q){
	return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (Queue Q){
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

void CreateEmpty (Queue * Q, int Max){
	Q->First = Nil;
	Q->Last = Nil;
	Q->MaxEl = Max;
}

void DeAlokasi(Queue * Q){
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

void Add (Queue * Q, infotype X){
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

void Del (Queue * Q, infotype * X){
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
