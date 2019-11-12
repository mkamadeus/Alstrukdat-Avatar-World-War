#include "../include/menu.h"

void menu()
{
	printf("Avatar World War Splash Screen\n");
	printf("\n");
	printf("Press ENTER to continue...\n");

	// Enter confirmation
	char enter = 0;
	while (enter != '\r' && enter != '\n') { enter = getchar(); }

	printf("Game start.\n");	
}

void mapSelection(char* mapName)
{
	printf("Input map filename: ");
	scanf("%s", mapName);
}