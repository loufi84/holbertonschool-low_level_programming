#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - Search for an int
 * @array: The array to search in
 * @size: The number of element in the array
 * @cmp: The function to call
 * Return: O for success, -1 if no element match
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		cmp(array[i]);
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	return (-1);
}
