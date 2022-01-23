#include "Main.h"


int Maxscore(int bricksUnoCount[], int bricksDosCount[], int bricksTresCount[], int bricksCuatroCount[])
{
	int maxscore = 0;
	for (int i = 0; i < 8; i++)
	{
		if (bricksUnoCount[i] == 1)
			maxscore++;
		if (bricksDosCount[i] == 1)
			maxscore++;
		if (bricksTresCount[i] == 1)
			maxscore++;
		if (bricksCuatroCount[i] == 1)
			maxscore++;
	}
	return maxscore;
}