#include "../include/game.h"

void changeTurn(int* turn)
{
	*turn = *turn==1 ? 2 : 1;
}

void printEnemyBuildingConnected(graph G, int turn, int input, buildingsArray bangunan, int * output){
	uAddress P = first(G);
	while(P != NULL && info(P) != input){
		P = next(P);
	}
	vAddress Q = child(P);
	int number = 1;
	while(Q != NULL){
		if(turn == 1){
			if(owner(*Build(bangunan,info(Q))) != 1){
				printf("%d. ", number);
				writeBuildingCoord(*Elmt(bangunan,info(Q)));
				printf(" %d lv. %d", troops(*Build(bangunan,info(Q))), level(*Build(bangunan,info(Q))));
				printf("\n");
				number++;
			}
		}
		else{
			if(owner(*Build(bangunan,info(Q))) != 2){
				printf("%d. ", number);
				writeBuildingCoord(*Elmt(bangunan,info(Q)));
				printf(" %d lv. %d", troops(*Build(bangunan,info(Q))), level(*Build(bangunan,info(Q))));
				printf("\n");
				number++;
			}
		}
		// printf("%d. owner = %d\n",count,owner(*Build(bangunan,count)));
		Q = nextChild(Q);
	}
	*output = number;
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

int inputToIndexMine(graph G, int turn, int input1, int input2, buildingsArray bangunan){
	uAddress P = first(G);
	vAddress prec ;
	int i = 1;
	int count = 1;
	while(P != NULL && info(P) != input1){
		P = next(P);
	}
	vAddress Q = child(P);
		do{
		if(owner(*Build(bangunan,info(Q))) == turn){
			i++;
		}
		prec = Q;
		Q = nextChild(Q);
	}while(Q != NULL && i < input2);
	return info(prec);
}

int inputToIndexEnemy(graph G, int turn, int input1, int input2, buildingsArray bangunan){
	uAddress P = first(G);
	vAddress prec;
	int i = 0;
	while(P != NULL && info(P) != input1){
		P = next(P);
	}
	vAddress Q = child(P);
	do{
		if(owner(*Build(bangunan,info(Q))) != turn){
			i++;
		}
		prec = Q;
		Q = nextChild(Q);
	}while(Q != NULL && i < input2);
	return info(prec);
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
			printf("%d ", troops(*Build(bangunan,info(Q))));
			printf("lv. %d\n", level(*Build(bangunan,info(Q))));
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

void firstInterface(queue skill1, queue skill2, int turn){
	colorPrint("Current skill : ", CYAN);

	int skillId;

	if(turn==1)
	{
		if(isEmptyQueue(skill1)) skillId = -1;
		else skillId = InfoHead(skill1);
	}
	else if(turn==2)
	{
		if(isEmptyQueue(skill2)) skillId = -1;
		else skillId = InfoHead(skill2);
	}

	if(skillId == 1)
		printf("Instant Upgrade\n");
	else if(skillId == 2)
		printf("Shield\n");
	else if(skillId == 3)
		printf("Extra Turn\n");
	else if(skillId == 4)
		printf("Attack Up\n");
	else if(skillId == 5)
		printf("Critical Hit\n");
	else if(skillId == 6)
		printf("Instant Reinforcement\n");
	else if(skillId == 7)
		printf("Barrage\n");
}

void interfaceInsideAttack(int turn, linkedList P1, linkedList P2, buildingsArray bangunan){
	printf("Bangunan yang dipilih sudah digunakan untuk menyerang...\nPilihlah bangunan yang lain\n");
	printBuildings(turn, P1, P2, bangunan);
	printf("Pilih bangunan: ");
}

void levelUpInterface(int turn, linkedList P1, linkedList P2, buildingsArray bangunan){
	printf("Daftar Bangunan: \n");
	printBuildings(turn, P1, P2, bangunan);
	printf("Bangunan yang akan dilevel-Up: ");
}

void searchBInterface(int turn, linkedList P1, linkedList P2, buildingsArray bangunan){
	printf("Bangunan yang dipilih sudah digunakan ...\nPilihlah bangunan yang lain\n");
	printBuildings(turn, P1, P2, bangunan);
	printf("Pilih bangunan: ");
}

void deleteAllStack(stack * S, stack * level, stack * before, stack * troops1, stack * troops2, stack * crit){
	deleteAll(S);
	deleteAll(level);
	deleteAll(before);
	deleteAll(troops1);
	deleteAll(troops2);
	deleteAll(crit);
}

void createAllStack(stack * S, stack * level, stack * before, stack * troops1, stack * troops2, stack * crit){
	createStack(S);
	createStack(level);
	createStack(before);
	createStack(troops1);
	createStack(troops2);
	createStack(crit);
}

void mainMenu(){
	printf("    ___ _    _____  _________    ____     _       ______  ____  __    ____     _       _____    ____ \n");
	printf("   /   | |  / /   |/_  __/   |  / __ \\   | |     / / __ \\/ __ \\/ /   / __ \\   | |     / /   |  / __ \\ \n");
	printf("  / /| | | / / /| | / / / /| | / /_/ /   | | /| / / / / / /_/ / /   / / / /   | | /| / / /| | / /_/ /\n");
	printf(" / ___ | |/ / ___ |/ / / ___ |/ _, _/    | |/ |/ / /_/ / _, _/ /___/ /_/ /    | |/ |/ / ___ |/ _, _/ \n");
	printf("/_/  |_|___/_/  |_/_/ /_/  |_/_/ |_|     |__/|__/\\____/_/ |_/_____/_____/     |__/|__/_/  |_/_/ |_|  \n");
	printf("\n");
	printf("1. Start New Game\n");
	printf("2. Load game\n");
	printf("Masukkan input: ");
}

void commandInterface(){
	printf("Command yang tersedia:\n");
	printf("1. ATTACK\n");
	printf("2. LEVEL_UP\n");
	printf("3. MOVE\n");
	printf("4. SAVE\n");
	printf("4. UNDO\n");
	printf("5. SKILL\n");
	printf("6. END_TURN\n");
	printf("7. EXIT (Jika anda bosan atau terlalu gampang)\n");
}

void buildingStatusInterface(buildingsArray bangunan)
{
	printf(" ID. TYPE LVL | (ROW,COL) | TROOP | REGEN | DEFENSE\n");
	for(int i=1;i<=Neff(bangunan);i++)
	{
		// Building ID print
		printf(" %d. ", i);

		buildingCoord currentBuildingCoord = *Elmt(bangunan, i);
		buildings currentBuilding = *build(currentBuildingCoord);
		
		// Building type print
		if(owner(currentBuilding)==1) printf(RED);
		else if(owner(currentBuilding)==2) printf(BLUE);

		if(type(currentBuilding)==1) printf("Castle");
		else if(type(currentBuilding)==2) printf("Tower");
		else if(type(currentBuilding)==3) printf("Fort");
		else if(type(currentBuilding)==4) printf("Village");

		printf(NORMAL);

		printf(" Lv. %d", level(currentBuilding));

		printf(" | ");

		// Position
		printf("(%d,%d)", row(currentBuildingCoord), col(currentBuildingCoord));
		printf(" | ");

		// Troops count
		printf("T:%d", troops(currentBuilding));
		printf(" | ");

		// Regen rate
		printf("R:%d", troopsRegen(currentBuilding));
		printf(" | ");

		// Defense
		if(defense(currentBuilding)) printf(CYAN);
		printf("D");
		printf(NORMAL);

		printf("\n");
	}
}