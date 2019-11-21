#include "../include/queue.h"

void createEmpty (queue * Q){
	(*Q).T = (infotype*) malloc((Max+1) * sizeof(infotype));
	for(int i=1;i<=10;i++) (*Q).T[i]=0;
	Head(*Q) = unDef;
	Count(*Q) = 0;
	maxEl(*Q) = Max;
}

/* *** Destruktor *** */
void deAlokasi(queue * Q){
	free(Q -> T);
	maxEl(*Q) = unDef;
	Count(*Q) = 0;
	Head(*Q) = unDef;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/* ********* Prototype ********* */
boolean isEmpty (queue Q){
	return Head(Q) == unDef;
}

boolean isFull (queue Q){
	return Count(Q) == maxEl(Q);
}

int nbElmt (queue Q){
	return Count(Q);
}


/* *** Primitif Add/Delete *** */
void Add (queue * Q, infotype X){
	if(isEmpty(*Q)){
		Head(*Q) = 1;
		Count(*Q) = 1;
		infoHead(*Q) = X;
	}
	else
	{
		Count(*Q)++;
		infoTail(*Q) = X;
	}
	
}

void Del (queue * Q, infotype * X){
	*X = infoHead(*Q);
	if(Count(*Q) == 1){
		Head(*Q) = unDef;
	}
	else
	{
		Head(*Q)=(Head(*Q)%maxEl(*Q))+1;
	}
	Count(*Q)--;
}
