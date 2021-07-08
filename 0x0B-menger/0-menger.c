#include <math.h>
#include "menger.h"

/**
 * empty - Checks if square is blank
 *
 * @i: row idx
 * @j: column idx
 *
 * Return: 1 if # 0 if blank
 */

int empty(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);
		i /= 3;
		j /= 3;
	}
	return (1);
}

/**
 * menger - Draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 */

void menger(int level)
{
	int i, j, max;

	if (level < 0)
		return;

	for (i = 0, max = pow(3, level); i < max; i++)
	{
		for (j = 0; j < max; j++)
			if (empty(i, j) == 1)
				printf("#");
			else
				printf(" ");
		printf("\n");
	}
}
