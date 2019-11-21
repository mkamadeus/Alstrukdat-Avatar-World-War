#include "../include/game.h"

void changeTurn(int* turn)
{
	*turn = *turn==1 ? 2 : 1;
}

void printBuildingConnected(graph G, int input, buildingsArray bangunan){
	uAddress P = first(G);
	while(P != NULL && info(P) != input){
		P = next(P);
	}
	vAddress Q = child(P);
	int count = 1;
	while(Q != NULL){
		printf("%d. ", count);
		writeBuildingCoord(*Elmt(bangunan,info(Q)));
		Q = nextChild(Q);
		printf("\n");
		count++;
	}
}

void printBuildings(int turn, linkedList P1, linkedList P2, buildingsArray bangunan){
	printf("Daftar Bangunan: \n");
	int count = 1;
	if(turn == 1){
		address P1_ = firstList(P1);
		while(P1_ != NULL){
			printf("%d. ", count);
			writeBuildingCoord(*Elmt(bangunan,Info(P1_)));
			printf("%d ", troops(*Build(bangunan,Info(P1_))));
			printf("lv. %d\n", level(*Build(bangunan,Info(P1_))));
			P1_ = Next(P1_);
			count++;
		}
	}
	else{
		address P2_ = firstList(P2);
		while(P2_ != NULL){
			printf("%d.", count);
			writeBuildingCoord(*Elmt(bangunan,Info(P2_)));
			printf("%d ", troops(*Build(bangunan,Info(P2_))));
			printf("lv. %d\n", level(*Build(bangunan,Info(P2_))));
			P2_ = Next(P2_);
			count++;
		}
	}
}

void printEnemyBuildings(int turn, linkedList P1, linkedList P2, buildingsArray bangunan){
	printf("Daftar Bangunan: \n");
	int count = 1;
	if(turn == 2){
		address P1_ = firstList(P1);
		while(P1_ != NULL){
			printf("%d. ", count);
			writeBuildingCoord(*Elmt(bangunan,Info(P1_)));
			printf("%d ", troops(*Build(bangunan,Info(P1_))));
			printf("lv. %d\n", level(*Build(bangunan,Info(P1_))));
			P1_ = Next(P1_);
			count++;
		}
	}
	else{
		address P2_ = firstList(P2);
		while(P2_ != NULL){
			printf("%d.", count);
			writeBuildingCoord(*Elmt(bangunan,Info(P2_)));
			printf("%d ", troops(*Build(bangunan,Info(P2_))));
			printf("lv. %d\n", level(*Build(bangunan,Info(P2_))));
			P2_ = Next(P2_);
			count++;
		}
	}
}

int inputToIndex(int turn, int input, linkedList P1, linkedList P2){
	if(turn == 1){
		address P1_ = firstList(P1);
		for(int i = 0; i < input-1; i++){
			P1_ = Next(P1_);
		}
		return Info(P1_);
	}
	else{
		address P2_ = firstList(P2);
		for(int i = 0; i < input-1; i++){
			P2_ = Next(P2_);
		}
		return Info(P2_);
	}
}

int inputToIndexEnemy(graph G, int input1, int input2, buildingsArray bangunan){
	uAddress P = first(G);
	while(P != NULL && info(P) != input1){
		P = next(P);
	}
	vAddress Q = child(P);
	for(int i = 1; i <=input2-1; i++){
		Q = nextChild(Q);
	}
	return info(Q);
}

void printNearbyMyBuildings(graph G, int turn, int input, buildingsArray bangunan, int * count){
	uAddress P = first(G);
	while(P != NULL && info(P) != input){
		P = next(P);
	}
	vAddress Q = child(P);
	int counts = 1;
	while(Q != NULL){
		if(owner(*Build(bangunan,info(Q))) == turn){
			printf("%d. ", counts);
			writeBuildingCoord(*Elmt(bangunan,info(Q)));
			printf("\n");
			counts++;
		}
		Q = nextChild(Q);
	}
	if(counts == 1){
		printf("Tidak ada bangunan terdekat\n");
	}
	*count = counts;
}