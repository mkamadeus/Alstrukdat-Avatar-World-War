#include "../include/main.h"

#include <string.h>

int main()
{
	word input; 
	word penyerang;
	word diserang;
	word troopsUsed;
	word leveledUp;
	word moved;
	word moved2;

	buildingsArray bangunan;
	graph g;
	matrix m;
	
	linkedList P1;
	linkedList P2;
	linkedList flagAttack;
	linkedList flagMove;

	stack S;
	stack level;
	stack before;
	stack troops1;
	stack troops2;
	stack crit;
	stack buildings1;
	stack buildings2;

	queue skill1;
	queue skill2;

	int penyerang_;
	int diserang_;
	int troopsUsed_;
	int count;
	int countBuildingsAttack;
	int counterShieldP1 = 0;
	int counterShieldP2 = 0;
	int firstInput;
	int buildingCounter;
	
	int turn = 1;

	boolean isSuccess;
	boolean isCaptured = false;
	boolean critical = false;
	boolean ignore = false;
	boolean isExtraTurn = false;
	boolean isShieldActiveP1 = false;
	boolean shieldActivatedP1 = false;
	boolean isShieldActiveP2 = false;
	boolean shieldActivatedP2 = false;
	boolean criticalP1 = false;
	boolean criticalP2 = false;
	

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
	
	char ATTACK[20];
	char LEVEL_UP[20];
	char SKILL[20];
	char UNDO[20];
	char END_TURN[20];
	char SAVE[20];
	char MOVE[20];
	char EXIT[20];
	
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

	mainMenu();

	do{
		readNumberSTDIN(&firstInput);
		if(firstInput == 1){	
			readConfigFile(&m, &bangunan, &g, &buildingCounter);
			owner(*Build(bangunan,1)) = 1;
			owner(*Build(bangunan,2)) = 2;	
		}
		else if(firstInput == 2){
			loadFromFile(&m, &bangunan, &g, &turn, &ignore, &critical, &isExtraTurn, &skill1, &skill2, &buildingCounter, &criticalP1, &criticalP2, &isShieldActiveP1, &shieldActivatedP1, &isShieldActiveP2, &shieldActivatedP2, &counterShieldP1, &counterShieldP2);
		}
		else{
			printf("Masukkan inputan yang benar: ");
		}
	}while(firstInput != 1 && firstInput != 2);

	for(int i = 1; i < buildingCounter+1; i++){
		if(owner(*Build(bangunan,i)) == 1){
			insertValueLast(&P1,i);
		}
		else if(owner(*Build(bangunan,i)) == 2){
			insertValueLast(&P2,i);
		}
	}

	while(length(P1) != 0 && length(P2) != 0){
		do{
			// DEBUG
			printf("Flag Attack = ");
			printInfo(flagAttack);
			printf("\n");
			printf("Flag Move = ");
			printInfo(flagMove);
			printf("\n\n");
			printf("Bangunan 1 = ");
			printInfo(P1);
			printf("\n\n");
			printf("Bangunan 2 = ");
			printInfo(P2);
			printf("\n\n");

			if(criticalP1){
				printf("Critical P1 ada\n\n");
			}
			else{
				printf("Critical P1 tidak ada\n\n");
			}

			if(criticalP2){
				printf("Critical P2 ada\n\n");
			}
			else{
				printf("Critical P2 tidak ada\n\n");
			}

			if(ignore){
				printf("Attack Up Aktif\n\n");
			}
			else{
				printf("Attack Up Tidak Aktif\n\n");
			}

			if(critical){
				printf("Critical Aktif\n\n");
			}
			else{
				printf("Critical Tidak Aktif\n\n");
			}

			if(isShieldActiveP1){
				printf("Shield Player 1 Activated\n\n");
			}
			else{
				printf("Shield Player 1 not Activated\n\n");
			}

			if(isShieldActiveP2){
				printf("Shield Player 2 Activated\n\n");
			}
			else{
				printf("Shield Player 2 not Activated\n\n");
			}

			// Tampilan Default
			writeMatrix(m);
			firstInterface(skill1, skill2, turn);

			// Command
			printf("Masukkan Command: ");
			readSTDIN(&input);

			if(wordCompare(input, ATTACK)){

				for(int i = 1; i <= 17; i++){
					printf("owner[%d] = %d\n", i, owner(*Build(bangunan,i)));
				}
				
				// Checker if the building have attacked or not
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

				// State before
				int lengthMarkBefore = lengthTurnNow(turn, P1, P2);
				int fortMarkBefore = fortCounter(P1, P2, bangunan, turn);
				int towerMarkBefore = towerCounter(P1, P2, bangunan, turn);
				int lengthMineBefore = lengthTurnMine(turn, P1, P2);

				printBuildings(turn, P1, P2, bangunan);
				printf("Bangunan yang digunakan untuk menyerang: ");
				
				/* Input from User */
				readSTDIN(&penyerang);
				int temp = intConverter(penyerang);
				int temp2 = inputToIndex(turn, temp, P1, P2);
				penyerang_ = temp2;
				printf("Penyerang_ = %d\n", penyerang_);

				/* Check if building have attacked or not */
				while(searchB(flagAttack,penyerang_)){
					
					// Interface
					interfaceInsideAttack(turn, P1, P2, bangunan);
					readSTDIN(&penyerang);

					int temp = intConverter(penyerang);
					int temp2 = inputToIndex(turn, temp, P1, P2);
					penyerang_ = temp2;
				}

				printf("Penyerang_ setelah = %d\n", penyerang_);

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

				printf("diserang_ = %d\n", diserang_);

				printf("Masukkan berapa pasukan yang akan digunakan: ");

				/* Input from User */
				readSTDIN(&troopsUsed);
				int troopsUsed_ = intConverter(troopsUsed);
				while(troopsUsed_ > troops(*Build(bangunan,penyerang_))){
					// Interface
					printf("Masukkan troops <= %d\n", troops(*Build(bangunan,penyerang_)));
					readSTDIN(&troopsUsed);
					troopsUsed_ = intConverter(troopsUsed);
				}

				// Temporary state
				int ownerBefore = owner(*Build(bangunan,diserang_));

				attack(Build(bangunan,penyerang_), Build(bangunan,diserang_), &isCaptured, troopsUsed_, &critical, ignore, turn, &level, &before, &troops1, &troops2, &S, &crit);
				push(&buildings1, penyerang_);
				push(&buildings2, diserang_);

				/* Put Index Building into list that contains index building that have attacked */
				insertValueFirst(&flagAttack,penyerang_);

				/* Mark if the building captured */
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

				// Data after attacked
				int lengthMarkAfter = lengthTurnNow(turn, P1, P2);
				int fortMarkAfter = fortCounter(P1, P2, bangunan, turn);
				int towerMarkAfter = towerCounter(P1, P2, bangunan, turn);
				int lengthMineAfter = lengthTurnMine(turn, P1, P2);

				printf("lengthMineBefore = %d\n", lengthMineBefore);
				printf("lengthMineAfter = %d\n", lengthMineAfter);

				if(lengthMarkBefore == 3 && lengthMarkAfter == 2){
					shieldTriggered(&skill1, &skill2, turn);
				}
				if(fortMarkBefore > fortMarkAfter){
					extraTurnTriggered(&skill1, &skill2, turn);
				}
				if(towerMarkBefore < 3 && towerMarkAfter == 3){
					attackUpTriggered(&skill1, &skill2, turn);
				}
				if(lengthMineBefore < 10 && lengthMineAfter == 10){
					barrageTriggered(&skill1, &skill2, P1, P2, turn);
				}
			}

			else if(wordCompare(input, LEVEL_UP)){
				//Interface
				levelUpInterface(turn, P1, P2, bangunan);
				readSTDIN(&leveledUp);

				int leveledUp_ = intConverter(leveledUp);
				leveledUp_ = inputToIndex(turn, leveledUp_, P1, P2);
				
				//levelUp command
				levelUp(Build(bangunan,leveledUp_), &S, &isSuccess);
				push(&buildings1, leveledUp_);

				/* Skill Instant Reinforcement Triggered */
				if(isSuccess){
					instantReinforcementTriggered(&skill1, &skill2, bangunan, P1, P2, turn);
				}
			}

			else if(wordCompare(input, MOVE)){
				
				//Checker if the buildings have moved or not
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
				
				//Interface
				printBuildings(turn, P1, P2, bangunan);
				printf("Pilih Bangunan: ");

				// Input from User
				readSTDIN(&moved);
				int moved_ = intConverter(moved);
				moved_ = inputToIndex(turn, moved_, P1, P2);

				/* Check if building have moved or not */
				while(searchB(flagMove,moved_)){
					
					//Interface
					searchBInterface(turn, P1, P2, bangunan);

					//Input from User
					readSTDIN(&moved);
					moved_ = intConverter(moved);
					moved_ = inputToIndex(turn, moved_, P1, P2);
				}
				
				printNearbyMyBuildings(g, turn, moved_, bangunan, &count);
				// Checker if the building can move or not
				if(count == 1){
					printf("Tidak ada bangunanmu yang terdekat...\n");
					continue;
				}

				//Input from User
				printf("Pilih Bangunan: ");
				readSTDIN(&moved2);
				int moved2_ = intConverter(moved2); 
				moved2_ = inputToIndexMine(g, turn, moved_, moved2_, bangunan);

				//Move command
				move(Build(bangunan,moved_),Build(bangunan,moved2_),&S, &troops1, &troops2);
				push(&buildings1, moved_);
				push(&buildings2, moved2_);

				/* Put index building that have moved */
				insertValueFirst(&flagMove,moved_);
			}
			else if(wordCompare(input, SAVE)){
				saveToFile(&m, &bangunan, &g, turn, ignore, critical, isExtraTurn, &skill1, &skill2, criticalP1, criticalP2, isShieldActiveP1, shieldActivatedP1, isShieldActiveP2, shieldActivatedP2, counterShieldP1, counterShieldP2);
				printf("\n");
				printf("Save Succesfull\n");
			}
			else if(wordCompare(input, UNDO)){
				int undoCommand;
				int tempBuilding1;
				int tempBuilding2;

				// Pop the inverse command
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

					//Change ownership in list
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

					///flagAttack delete
					deleteValue(&flagAttack,tempBuilding1);

					//inverseAttack command
					inverseAttack(Build(bangunan,tempBuilding1), Build(bangunan,tempBuilding2), &critical, &level, &before, &troops1, &troops2, &crit);
					
				}
				else if(undoCommand == 3){
					pop(&buildings1, &tempBuilding1);
					pop(&buildings2, &tempBuilding2);

					//inverseMove command
					inverseMove(Build(bangunan,tempBuilding1),Build(bangunan,tempBuilding2),&troops1,&troops2);
					
					//delete Value of Flag Move
					deleteValue(&flagMove,tempBuilding1);
				}
				undoCommand = 0;
			}
			else if(wordCompare(input, SKILL)){
				
				//dealocate all stack
				deleteAllStack(&S,&level,&before,&troops1,&troops2,&crit);
				
				//create all stack
				createAllStack(&S,&level,&before,&troops1,&troops2,&crit);
				
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
					shield(&bangunan, turn, P1, P2, &isShieldActiveP1, &shieldActivatedP1, &isShieldActiveP2, &shieldActivatedP2);
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

				// make skill to default form
				if(ignore == true){
					ignore = false;
				}

				// critical mark
				if(critical){
					if(turn == 1){
						criticalP1 = true;
					}
					else{
						criticalP2 = true;
					}
					critical = false;
				}

				if(criticalP1){
					if(turn == 2){
						critical = true;
					}
					else{
						critical = false;
					}
				}

				if(criticalP2){
					if(turn == 1){
						critical = false;
					}
					else{
						critical = true;
					}
				}

				if(criticalP1 && criticalP2){
					critical = true;
				}

				//When triggered extra turn
				if(isExtraTurn){
					printf("Sekarang giliranmu lagi\n");
					isExtraTurn = false;
				}

				else{
					changeTurn(&turn);
					printf("Sekarang giliran player %d\n", turn);
				}

				printf("counterShieldP1 = %d\n", counterShieldP1);
				printf("counterShieldP2 = %d\n", counterShieldP2);
				// Mark shield skill activated
				if(shieldActivatedP1){
					counterShieldP1 = 0;
					shieldActivatedP1 = false;
				}
				
				if(shieldActivatedP2){
					counterShieldP2 = 0;
					shieldActivatedP2 = false;
				}
				// shield turn counter
				if(isShieldActiveP1){
					counterShieldP1++;
				}
				
				if(isShieldActiveP2){
					counterShieldP2++;
				}

				if(counterShieldP1 == 4){
					unshield(&bangunan,turn,P1,P2);
					counterShieldP1 = 0;
					isShieldActiveP1 = false;
				}

				if(counterShieldP2 == 4){
					unshield(&bangunan, turn, P1, P2);
					counterShieldP2 = 0;
					isShieldActiveP2 = false;
				}
				// Troops increase every turn
				if(turn == 1){
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

				deleteAllStack(&S, &level, &before, &troops1, &troops2, &crit);
				createAllStack(&S, &level, &before, &troops1, &troops2, &crit);
				deleteEverything(&flagAttack);
				deleteEverything(&flagMove);
				createEmpty(&flagAttack);
				createEmpty(&flagMove);
			}
			else if(wordCompare(input, EXIT)){
				printf("Terima Kasih Telah Bermain\n");
				exit(0);
			}
			else{
				printf("Inputan Tidak Valid\n");
			}
		}while(!wordCompare(input, END_TURN));
	}
}