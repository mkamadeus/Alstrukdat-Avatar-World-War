#include "../include/game.h"
#include "../../lib/src/array.c"
#include "../../lib/src/command.c"
#include "../../lib/src/buildings.c"
#include "../../lib/src/stack.c"
#include "../../lib/src/linkedlist.c"

void changeTurn(int* turn)
{
	*turn = *turn==1 ? 2 : 1;
}

void printBuildings(int turn, linkedList P1, linkedList P2, TabInt bangunan){
	printf("Daftar Bangunan: \n");
	if(turn == 1){
		address P1_ = first(P1);
		while(P1_ != NULL){
			show(*TI(bangunan)[Info(P1_)]);
			printf("==================================\n");
			P1_ = Next(P1_);
		}
	}
	else{
		address P2_ = first(P2);
		while(P2_ != NULL){
			show(*TI(bangunan)[Info(P2_)]);
			printf("==================================\n");
			P2_ = Next(P2_);
		}
	}
}

int inputToIndex(int turn, int input, linkedList P1, linkedList P2){
	if(turn == 1){
		address P1_ = first(P1);
		for(int i = 0; i < input-1; i++){
			P1_ = Next(P1_);
		}
	}
	else{
		address P2_ = first(P2);
		for(int i = 0; i < input-1; i++){
			P2_ = Next(P2_);
		}
	}
}