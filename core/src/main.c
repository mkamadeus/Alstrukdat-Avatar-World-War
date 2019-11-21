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
	stack S,level,before,troops1,troops2,crit;
	queue skill1, skill2;
	int penyerang_, diserang_, troopsUsed_, count;
	readConfigFile(&m, &bangunan, &g);
	boolean isSuccess;
	boolean isCaptured = false;
	boolean critical = false;
	boolean ignore = false;
	boolean isExtraTurn = false;
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
	owner(*Build(bangunan,1)) = 1;
	owner(*Build(bangunan,2)) = 1;
	owner(*Build(bangunan,3)) = 2;
	owner(*Build(bangunan,4)) = 2;
	for(int i = 1; i < 5; i++){
		if(owner(*Build(bangunan,i)) == 1){
			insertValueLast(&P1,i);
		}
		else{
			insertValueLast(&P2,i);
		}
	}

	while(length(P1) != 0 && length(P2) != 0){
		do{
			printf("Masukkan Command: ");
			readSTDIN(&input);
			if(wordCompare(input, ATTACK)){
				if(turn == 1){
					if(length(flagAttack) == length(P1)){
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
					readSTDIN(&penyerang);
					int temp = intConverter(penyerang);
					int temp2 = inputToIndex(turn, temp, P1, P2);
					penyerang_ = temp2;
				}

				printBuildingConnected(g, penyerang_, bangunan);
				printf("Bangunan yang diserang: ");

				/* Input from User */
				readSTDIN(&diserang);
				int temp3 = intConverter(diserang);

				int temp4 = inputToIndexEnemy(g, penyerang_, temp3, bangunan);
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
				attack(Build(bangunan,penyerang_), Build(bangunan,diserang_), &isCaptured, troopsUsed_, &critical, ignore, turn, &level, &before, &troops1, &troops2, &S, &crit);

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
						deleteValue(&P2,temp4);
					}
					else{
						insertValueLast(&P2, temp4);
						deleteValue(&P2,temp4);
					}
				}
				else{
					printf("Bangunan gagal direbut\n");
				}
			}
			else if(wordCompare(input, LEVEL_UP)){
				printf("Daftar Bangunan: \n");
				printBuildings(turn, P1, P2, bangunan);
				printf("Bangunan yang akan dilevel-Up: ");
				readSTDIN(&leveledUp);
				int leveledUp_ = intConverter(leveledUp);
				leveledUp_ = inputToIndex(turn, leveledUp_, P1, P2);
				levelUp(Build(bangunan,leveledUp_), &S, &isSuccess);
				
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
				printf("Daftar Bangunan: \n");
				printBuildings(turn, P1, P2, bangunan);
				printf("Pilih Bangunan: ");
				readSTDIN(&moved);
				int moved_ = intConverter(moved);
				moved_ = inputToIndex(turn, moved_, P1, P2);

				/* Check if building have moved or not */
				while(searchB(flagMove,moved_)){
					printf("Bangunan yang dipilih sudah digunakan untuk menyerang...\nPilihlah bangunan yang lain\n");
					printBuildings(turn, P1, P2, bangunan);
					readSTDIN(&moved);
					int moved_ = intConverter(moved);
					moved_ = inputToIndex(turn, moved_, P1, P2);
				}
				
				printNearbyMyBuildings(g, turn, moved_, bangunan, &count);
				if(count == 1){
					continue;
				}
				printf("Pilih Bangunan: ");
				readSTDIN(&moved2);
				int moved2_ = inputToIndex(turn, moved2_, P1, P2);
				move(Build(bangunan,moved_),Build(bangunan,moved2_),&S, &troops1, &troops2);
				
				/* Put index building that have moved */
				insertValueFirst(&flagMove,moved2_);
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
					shield(&bangunan, turn, P1, P2);
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