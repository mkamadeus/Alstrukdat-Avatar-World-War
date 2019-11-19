#include "../include/main.h"

#include "menu.c"
#include "game.c"

#include <string.h>

int main()
{
	menu();

	char mapName[50];
	mapSelection(mapName);

	printf("You're now playing on %s.\n", mapName);

	TabInt bangunan;
	linkedList P1,P2;
	buildings A,B,E,F;
	stack S,level,before,troops1,troops2,crit;
	int penyerang, diserang, leveledUp, moved, moved2;
	boolean critical = false;
	boolean ignore = false;
	int turn = 1;
    createStack(&S);
    createStack(&level);
    createStack(&before);
    createStack(&troops1);
    createStack(&troops2);
    createStack(&crit);
	makeCastle(&A,1);
	makeTower(&B,1);
	makeCastle(&E,2);
	makeTower(&F,2);
	makeEmptyArray(&bangunan, 5);
	bacaIsi(&bangunan, &A);
	bacaIsi(&bangunan, &B);
	bacaIsi(&bangunan, &E);
	bacaIsi(&bangunan, &F);
	show(*TI(bangunan)[1]);
	createEmpty(&P1);
	createEmpty(&P2);
	for(int i = 1; i < 5; i++){
		if(owner(*Elmt(bangunan,i)) == 1){
			insertValueLast(&P1,i);
		}
		else{
			insertValueLast(&P2,i);
		}
	}
	printf("P1 \n");
	printInfo(P1);
	printf("\n");
	printf("P2 \n");
	printInfo(P2);
	char str[50];	
	printf("\n");
	while(length(P1) != 0 && length(P2) != 0){
		do{
			printf("Masukkan Command: ");
			scanf("%s", str);
			if(strcmp(str,"ATTACK") == 0){
				printBuildings(turn, P1, P2, bangunan);
				printf("Bangunan yang digunakan untuk menyerang: ");
				scanf("%d", &penyerang);
				penyerang = inputToIndex(turn, penyerang, P1, P2);
				address P2_ = first(P2);
				while(P2_ != NULL){
					show(*TI(bangunan)[Info(P2_)]);
					printf("==================================\n");
					P2_ = Next(P2_);
				}
				printf("Bangunan yang diserang: ");
				scanf("%d", &diserang);
				P2_ = first(P2);
				for(int i = 0; i < diserang-1; i++){
					P2_ = Next(P2_);
				}
				diserang = Info(P2_);
				attack(Elmt(bangunan,penyerang), Elmt(bangunan,diserang), &critical, ignore, 1, &level, &before, &troops1, &troops2, &S, &crit);
				printf("Bangunanmu sekarang: \n");
				show(*TI(bangunan)[penyerang]);
				printf("\n");
				printf("Bangunan musuh sekarang: \n");
				show(*TI(bangunan)[diserang]);
			}
			else if(strcmp(str, "LEVEL_UP") == 0){
				printf("Daftar Bangunan: \n");
				printBuildings(turn, P1, P2, bangunan);
				printf("Bangunan yang akan dilevel-Up: ");
				scanf("%d", &leveledUp);
				leveledUp = inputToIndex(turn, leveledUp, P1, P2);
				levelUp(TI(bangunan)[leveledUp], &S);
			}
			else if(strcmp(str, "MOVE") == 0){
				printf("Daftar Bangunan: \n");
				printBuildings(turn, P1, P2, bangunan);
				printf("Pilih Bangunan: ");
				scanf("%d", &moved);
				moved = inputToIndex(turn, moved, P1, P2);
				printf("Daftar Bangunan Terdekat: ");
				printBuildings(turn, P1, P2, bangunan);
				printf("Pilih Bangunan: ");
				scanf("%d", &moved2);
				moved2 = inputToIndex(turn, moved2, P1, P2);
				move(TI(bangunan)[moved],TI(bangunan)[moved2],&S, &troops1, &troops2);
			}
			else if(strcmp(str, "END_TURN") == 0){
				changeTurn(&turn);
				printf("Sekarang giliran player %d\n", turn);
			}
		}while(strcmp(str,"END_TURN") != 0);
	}
}