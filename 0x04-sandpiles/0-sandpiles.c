#include "sandpiles.h"

/**
 * _print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void _print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * basic_sum - sum two 3x3 grids
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void basic_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * stable - check if sandpile is stable
 * @grid: 3x3 grid
 *
 * Return: true or false
 */
int stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * topple - caclulate
 * @grid: 3x3 grid
 *
 */
void topple(int grid[3][3])
{
	int i, j, limit = 2;

	int auxg[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				(i - 1) >= 0 ? auxg[i - 1][j]++ : 0;
				(i + 1) <= limit ? auxg[i + 1][j]++ : 0;
				(j - 1) >= 0 ? auxg[i][j - 1]++ : 0;
				(j + 1) <= limit ? auxg[i][j + 1]++ : 0;
				grid[i][j] -= 4;
			}
		}
	}
	basic_sum(grid, auxg);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 *
 * @grid1: int matrix 1
 * @grid2: int matrix 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	basic_sum(grid1, grid2);
	while (!stable(grid1))
	{
		printf("=\n");
		_print_grid(grid1);
		topple(grid1);
	}
}
