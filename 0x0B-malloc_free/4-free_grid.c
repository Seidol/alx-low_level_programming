#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees memory of a 2D array.
 * @grid: Pointer to the 2D grid.
 * @height: Height dimension of the grid.
 *
 * Description: Frees the memory of the 2D grid.
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	while (i < height)
	{
		free(grid[i]);
		i++;
	}

	free(grid);
}
