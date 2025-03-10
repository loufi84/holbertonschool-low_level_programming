#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - Create an array of int
 * @min: Minimal values
 * @max: Maxiaml values
 * Return: A pointer to the new array
 */

int *array_range(int min, int max)
{
	int *ptr;
	int size = max - min + 1, i;

	if (min > max)
	{
		return (NULL);
	}

	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		ptr[i] = min;
		min++;
	}

	return (ptr);
}
