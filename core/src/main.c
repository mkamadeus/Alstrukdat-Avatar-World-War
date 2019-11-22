#include "../include/main.h"

#include <string.h>

int main()
{
	menu();

	// char mapName[50];
	// mapSelection(mapName);

	// printf("You're now playing on %s.\n", mapName);
	word input, penyerang, diserang, troopsUsed, leveledUp, moved, moved2;
	buildingsArray bangunan;
	graph g;
	matrix m;
	linkedList P1,P2,flagAttack,flagMove;
	stack S,level,before,troops1,troops2,crit, buildings1, buildings2;
	queue skill1, skill2;
	int penyerang_, diserang_, troopsUsed_, count, countBuildingsAttack, counterShield;
	readConfigFile(&m, &bangunan, &g);
	boolean isSuccess;
	boolean isCaptured = false;
	boolean critical = false;
	boolean ignore = false;
	boolean isExtraTurn = false;
	boolean isShieldActive = false;
	int turn = 1;

    createStack(&S);
    createStack(&level);
    createStack(&before);
    createStack(&troops1);
    createStack(&troops2);
    createStack(&crit);

	createQueue(&skill1,10);
	createQueue(&skill2,10);
	Add(&skill1,1);
	Add(&skill2,1);
	
	char ATTACK[100];
	char LEVEL_UP[100];
	char SKILL[100];
	char UNDO[100];
	char END_TURN[100];
	char SAVE[100];
	char MOVE[100];
	char EXIT[100];
	
	strcpy(ATTACK,"ATTACK");
	strcpy(LEVEL_UP,"LEVEL_UP");
	strcpy(SKILL,"SKILL");
	strcpy(UNDO,"UNDO");
	strcpy(END_TURN,"END_TURN");
	strcpy(SAVE,"SAVE");
	strcpy(MOVE,"MOVE");
	strcpy(EXIT,"EXIT");

	createEmpty(&P1);
	createEmpty(&P2);
	createEmpty(&flagAttack);
	createEmpty(&flagMove);
	printGraph(g);

	owner(*Build(bangunan,1)) = 1;
	owner(*Build(bangunan,2)) = 1;
	owner(*Build(bangunan,3)) = 1;
	owner(*Build(bangunan,4)) = 1;
	owner(*Build(bangunan,5)) = 1;
	owner(*Build(bangunan,6)) = 1;
	owner(*Build(bangunan,7)) = 1;
	owner(*Build(bangunan,8)) = 1;
	owner(*Build(bangunan,9)) = 1;
	owner(*Build(bangunan,10)) = 1;
	owner(*Build(bangunan,11)) = 1;
	owner(*Build(bangunan,12)) = 1;
	owner(*Build(bangunan,13)) = 2;
	owner(*Build(bangunan,14)) = 1;
	owner(*Build(bangunan,15)) = 1;
	owner(*Build(bangunan,16)) = 1;
	owner(*Build(bangunan,17)) = 2;

	for(int i = 1; i <= 17; i++){
		printf("owner[%d] = %d\n", i, owner(*Build(bangunan,i)));
	}

	for(int i = 1; i < 18; i++){
		if(owner(*Build(bangunan,i)) == 1){
			insertValueLast(&P1,i);
		}
		else{
			insertValueLast(&P2,i);
		}
	}

<<<<<<< HEAD
=======
	printInfo(P1);
	printf("\n");
	printInfo(P2);
	printf("\n");

	while(length(P1) != 0 && length(P2) != 0){
		do{
			printf("Masukkan Command: ");
			readSTDIN(&input);
			if(wordCompare(input, ATTACK)){
				if(turn == 1){
						printf("Semua bangunan telah digunakan untuk menyerang\n");
						continue;
					}
				}
				else{
					if(length(flagAttack) == length(P2)){
						printf("Semua bangunan telah digunakan untuk menyerang\n");
						continue;
					}
				}
				int lengthMarkBefore = lengthTurnNow(turn, P1, P2);
				int fortMarkBefore = fortCounter(P1, P2, bangunan, turn);
				int towerMarkBefore = towerCounter(P1, P2, bangunan, turn);

				printBuildings(turn, P1, P2, bangunan);
				printf("Bangunan yang digunakan untuk menyerang: ");
				
				/* Input from User */
				readSTDIN(&penyerang);
				int temp = intConverter(penyerang);
				int temp2 = inputToIndex(turn, temp, P1, P2);
				penyerang_ = temp2;

				/* Check if building have attacked or not */
				while(searchB(flagAttack,penyerang_)){
					printf("Bangunan yang dipilih sudah digunakan untuk menyerang...\nPilihlah bangunan yang lain\n");
					printBuildings(turn, P1, P2, bangunan);
					printf("Pilih bangunan: ");
					readSTDIN(&penyerang);
					int temp = intConverter(penyerang);
					int temp2 = inputToIndex(turn, temp, P1, P2);
					penyerang_ = temp2;
				}

				printEnemyBuildingConnected(g, turn, penyerang_, bangunan, &countBuildingsAttack);
				if(countBuildingsAttack == 1){
					printf("Tidak ada bangunan yang dapat diserang\n");
					continue;
				}
				printf("Bangunan yang diserang: ");

				/* Input from User */
				readSTDIN(&diserang);
				int temp3 = intConverter(diserang);

				int temp4 = inputToIndexEnemy(g, turn, penyerang_, temp3, bangunan);
				diserang_ = temp4;

				printf("Masukkan berapa pasukan yang akan digunakan: ");

				/* Input from User */
				readSTDIN(&troopsUsed);
				int troopsUsed_ = intConverter(troopsUsed);
				while(troopsUsed_ > troops(*Build(bangunan,penyerang_))){
					printf("Masukkan troops <= %d\n", troops(*Build(bangunan,penyerang_)));
					readSTDIN(&troopsUsed);
					troopsUsed_ = intConverter(troopsUsed);
					printf("tU = %d\n", troopsUsed_);
				}
				printf("penyerang = %d\n", penyerang_);
				printf("diserang = %d\n", diserang_);
				int ownerBefore = owner(*Build(bangunan,diserang_));

				attack(Build(bangunan,penyerang_), Build(bangunan,diserang_), &isCaptured, troopsUsed_, &critical, ignore, turn, &level, &before, &troops1, &troops2, &S, &crit);
				push(&buildings1, penyerang_);
				push(&buildings2, diserang_);

				/* Put Index Building into list that contains index building that have attacked */
				insertValueFirst(&flagAttack,penyerang_);

				int lengthMarkAfter = lengthTurnNow(turn, P1, P2);
				int fortMarkAfter = fortCounter(P1, P2, bangunan, turn);
				int towerMarkAfter = towerCounter(P1, P2, bangunan, turn);

				if(lengthMarkBefore == 3 && lengthMarkAfter == 2){
					shieldTriggered(&skill1, &skill2, turn);
				}
				if(fortMarkBefore > fortMarkAfter){
					extraTurnTriggered(&skill1, &skill2, turn);
				}
				if(towerMarkBefore < 3 && towerMarkAfter == 3){
					attackUpTriggered(&skill1, &skill2, turn);
				}
				if(lengthMarkBefore < 10 && lengthMarkAfter == 10){
					barrageTriggered(&skill1, &skill2, P1, P2, turn);
				}

				if(isCaptured){
					printf("Bangunan berhasil direbut\n");
					if(turn == 1){
						insertValueLast(&P1, temp4);
						if(ownerBefore == 2){
							deleteValue(&P2,temp4);
						}
					}
					else{
						insertValueLast(&P2, temp4);
						if(ownerBefore == 1){
							deleteValue(&P1,temp4);
						}
					}
				}
				else{
					printf("Bangunan gagal direbut\n");
				}
				printInfo(P1);
				printf("\n");
				printInfo(P2);
				printf("\n");
			}
			else if(wordCompare(input, LEVEL_UP)){
				printf("Daftar Bangunan: \n");
				printBuildings(turn, P1, P2, bangunan);
				printf("Bangunan yang akan dilevel-Up: ");
				readSTDIN(&leveledUp);
				int leveledUp_ = intConverter(leveledUp);
				leveledUp_ = inputToIndex(turn, leveledUp_, P1, P2);
				levelUp(Build(bangunan,leveledUp_), &S, &isSuccess);
				push(&buildings1, leveledUp_);
				/* Skill Instant Reinforcement Triggered */
				if(isSuccess){
					instantReinforcementTriggered(&skill1, &skill2, bangunan, P1, P2, turn);
				}
			}
			else if(wordCompare(input, MOVE)){
				if(turn == 1){
					if(length(flagMove) == length(P1)){
						printf("Semua bangunan telah digunakan untuk moved\n");
						continue;
					}
				}
				else{
					if(length(flagMove) == length(P2)){
						printf("Semua bangunan telah digunakan untuk moved\n");
						continue;
					}
				}
				printInfo(flagMove);
				printBuildings(turn, P1, P2, bangunan);
				printf("Pilih Bangunan: ");
				readSTDIN(&moved);
				int moved_ = intConverter(moved);
				moved_ = inputToIndex(turn, moved_, P1, P2);

				/* Check if building have moved or not */
				while(searchB(flagMove,moved_)){
					printf("Bangunan yang dipilih sudah digunakan ...\nPilihlah bangunan yang lain\n");
					printBuildings(turn, P1, P2, bangunan);
					printf("Pilih bangunan: ");
					readSTDIN(&moved);
					moved_ = intConverter(moved);
					moved_ = inputToIndex(turn, moved_, P1, P2);
				}
				
				printNearbyMyBuildings(g, turn, moved_, bangunan, &count);
				if(count == 1){
					printf("Tidak ada bangunanmu yang terdekat...\n");
					continue;
				}
				printf("Pilih Bangunan: ");
				readSTDIN(&moved2);
				int moved2_ = intConverter(moved2); 
				moved2_ = inputToIndexMine(g, turn, moved_, moved2_, bangunan);
				move(Build(bangunan,moved_),Build(bangunan,moved2_),&S, &troops1, &troops2);
				push(&buildings1, moved_);
				push(&buildings2, moved2_);

				/* Put index building that have moved */
				insertValueFirst(&flagMove,moved_);
			}
			else if(wordCompare(input, UNDO)){
				int undoCommand;
				int tempBuilding1;
				int tempBuilding2;
				pop(&S, &undoCommand);
				if(undoCommand == 1){
					pop(&buildings1, &tempBuilding1);
					inverseLevelUp(Build(bangunan,tempBuilding1));
				}
				else if(undoCommand == 2){
					pop(&buildings1, &tempBuilding1);
					pop(&buildings2, &tempBuilding2);
					int ownerAwal = owner(*Build(bangunan,tempBuilding2));
					int ownerAkhir = peek(&before);
					if(ownerAwal != ownerAkhir){
						if(ownerAwal == 1){
							insertValueLast(&P2,tempBuilding2);
							deleteValue(&P1,tempBuilding2);
						}
						else if(ownerAwal == 2){
							insertValueLast(&P1,tempBuilding2);
							deleteValue(&P2,tempBuilding2);
						}
						else{
							if(turn == 1){
								deleteValue(&P1, tempBuilding2);
							}
							else{
								deleteValue(&P2, tempBuilding2);
							}
						}
					}
					deleteValue(&flagAttack,tempBuilding1);
					inverseAttack(Build(bangunan,tempBuilding1), Build(bangunan,tempBuilding2), &critical, &level, &before, &troops1, &troops2, &crit);
					
				}
				else if(undoCommand == 3){
					int a = peek(&buildings1);
					int b = peek(&buildings2);
					int c = peek(&troops1);
					int d = peek(&troops2);
					pop(&buildings1, &tempBuilding1);
					pop(&buildings2, &tempBuilding2);
					inverseMove(Build(bangunan,tempBuilding1),Build(bangunan,tempBuilding2),&troops1,&troops2);
					deleteValue(&flagMove,tempBuilding1);
				}
			}
			else if(wordCompare(input, SKILL)){
				deleteAll(&S);
				deleteAll(&level);
				deleteAll(&before);
				deleteAll(&troops1);
				deleteAll(&troops2);
				deleteAll(&crit);
				createStack(&S);
				createStack(&level);
				createStack(&before);
				createStack(&troops1);
				createStack(&troops2);
				createStack(&crit);
				int skillUsed;
				if(turn == 1){
					Del(&skill1, &skillUsed);
					if(skillUsed == 3){
						criticalHitTriggered(&skill1, &skill2, turn);
					}
				}
				else{
					Del(&skill2, &skillUsed);
					if(skillUsed == 3){
						criticalHitTriggered(&skill1, &skill2, turn);
					}
				}
				if(skillUsed == 1){
					instantUpgrade(&bangunan, turn, P1, P2);
				}
				else if(skillUsed == 2){
					shield(&bangunan, turn, P1, P2, &isShieldActive);
				}
				else if(skillUsed == 3){
					extraTurn(&isExtraTurn);
				}
				else if(skillUsed == 4){
					attackUp(&ignore);
				}
				else if(skillUsed == 5){
					criticalHit(&critical);
				}
				else if(skillUsed == 6){
					instantReinforcement(&bangunan, turn, P1, P2);
				}
				else{
					barrage(&bangunan, turn, P1, P2);
				}
			}
			else if(wordCompare(input, END_TURN)){
				if(isExtraTurn){
					printf("Sekarang giliranmu lagi");
					isExtraTurn = false;
				}
				else{
					changeTurn(&turn);
					printf("Sekarang giliran player %d\n", turn);
				}
				if(ignore == true){
					ignore = false;
				}
				if(counterShield == 4){
					unshield(&bangunan,turn,P1,P2);
					counterShield = 0;
					isShieldActive = false;
				}
				if(isShieldActive){
					counterShield++;
				}
				if(turn == 2){
					address P = first(P1);
					while(P != NULL){
						increaseTroops(Build(bangunan,info(P)));
						P = next(P);
					}
				}
				else{
					address P = first(P2);
					while(P != NULL){
						increaseTroops(Build(bangunan,info(P)));
						P = next(P);
					}
				}
				deleteAll(&S);
				deleteAll(&level);
				deleteAll(&before);
				deleteAll(&troops1);
				deleteAll(&troops2);
				deleteAll(&crit);
				createStack(&S);
				createStack(&level);
				createStack(&before);
				createStack(&troops1);
				createStack(&troops2);
				createStack(&crit);
				deleteEverything(&flagAttack);
				deleteEverything(&flagMove);
				createEmpty(&flagAttack);
				createEmpty(&flagMove);
			}
		}while(wordCompare(input, EXIT));
	}
}