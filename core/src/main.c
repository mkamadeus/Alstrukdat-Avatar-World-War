#include "../include/main.h"

int main()
{
	menu();

	char mapName[50];
	mapSelection(mapName);

	printf("You're now playing on %s.\n", mapName);

	
}