#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates 2 strings
 * @s1: The first string to concatenate
 * @s2: The second string to concatenate
 * Return: a pointer to the concatenated str
 */

char *str_concat(char *s1, char *s2)
{
	char *new_str;
	int index1;
	int index2;
	int size1;
	int size2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	for (size1 = 0; s1[size1] != '\0'; size1++)
	{
	}
	for (size2 = 0; s2[size2] != '\0'; size2++)
	{
	}
	new_str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (new_str == NULL)
	{
		return (NULL);
	}

	for (index1 = 0; s1[index1] != '\0'; index1++)
	{
		new_str[index1] = s1[index1];
	}

	for (index2 = 0; s2[index2] != '\0'; index2++)
	{
		new_str[index1 + index2] = s2[index2];
	}

	new_str[size1 + size2] = '\0';

	return (new_str);
}
