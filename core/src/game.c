#include "../include/game.h"

void changeTurn(int* turn)
{
	*turn = *turn==1 ? 2 : 1;
}