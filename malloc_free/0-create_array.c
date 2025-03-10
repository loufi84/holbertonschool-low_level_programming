#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of char
 * @size: The size of the array
 * @c: The char to print
 * Return: a pointer to the array
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int index;

	if (size == 0)
	{
		return (NULL);
	}

	array = (char *)malloc((sizeof(char) * size));
	if (array == NULL)
	{
		return (NULL);
	}

	for (index = 0; index < size; index++)
	{
		array[index] = c;
	}


	return (array);
}
