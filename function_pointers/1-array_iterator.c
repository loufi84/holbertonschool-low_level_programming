#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_iterator - Executes a given function on each element of an array
 * @array: The array to print
 * @size: The size of the array
 * @action: The function we need to use
 * Return: Nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned long i = 0;

	if (array == NULL)
		return;

	if (size == 0)
		return;

	if (action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
