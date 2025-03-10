#include "main.h"
#include <stdlib.h>

/**
 * free_grid - free the memory for the 2D grid
 * @grid: the grid to free
 * @height: The height of the grid
 * Return: void
 */

void free_grid(int **grid, int height)
{
	int index;

	for (index = 0; index < height; index++)
	{
		free(grid[index]);
	}

	free(grid);
}
