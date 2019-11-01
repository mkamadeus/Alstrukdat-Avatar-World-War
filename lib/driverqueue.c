#include <stdio.h>
#include "queuelistlinier.h"

int main(){
	Queue Q;
	infotype dump;
	CreateEmpty(&Q, 10);
	Add(&Q, 1);
	Add(&Q, 2);
	Add(&Q, 3);
	Add(&Q, 4);
	Add(&Q, 5);
	Add(&Q, 6);
	Add(&Q, 7);
	Add(&Q, 8);
	Add(&Q, 9);
	Add(&Q, 0);
	Add(&Q, 10);
	Add(&Q, 10);
	printf("%d\n", NBElmt(Q));
	address p = First(Q);
	for(int i = 1;i<=NBElmt(Q);i++){
		printf("%d %d\n", Indeks(p), Info(p));
		p = Next(p);
	}
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	Del(&Q, &dump);
	p = First(Q);
	for(int i = 1;i<=NBElmt(Q);i++){
		printf("%d %d\n", Indeks(p), Info(p));
		p = Next(p);
	}
	
	char ini[] = "ini adalah string";
	char *u = ini;
	u[18] = 'q';
	printf("%d %s\n", sizeof(int*), ini);
	printf("%c",ini[18]); 
	return 0;
}