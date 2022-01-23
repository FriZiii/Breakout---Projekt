#include "Main.h"
float score(int bricksUnoCount[], int bricksDosCount[], int bricksTresCount[], int bricksCuatroCount[])
{
	float score = 0;
	for (int i = 0; i < 8; i++)
	{
		if (bricksUnoCount[i] == -1)
			score += 10000;
		if (bricksDosCount[i] == -1)
			score += 1000;
		if (bricksTresCount[i] == -1)
			score += 100;
		if (bricksCuatroCount[i] == -1)
			score += 10;
	}
	return score;
}