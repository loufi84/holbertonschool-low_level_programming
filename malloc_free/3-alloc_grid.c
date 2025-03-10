#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * alloc_grid - Allocate a memory for a 2D grid
 * @width: The width of the grid
 * @height: Hte width
 * Return: A pointer to 2D grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int index;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
	{
		return (NULL);
	}

	for (index = 0; index < height; index++)
	{
		grid[index] = malloc(width * sizeof(int));
		if (grid[index] == NULL)
		{
			return (NULL);
		}

		memset(grid[index], 0, width * sizeof(int));
	}

	return (grid);
}
