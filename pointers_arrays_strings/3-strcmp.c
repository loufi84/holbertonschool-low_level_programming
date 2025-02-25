#include "main.h"

/**
 * _strcmp - compare 2 strings
 * @s1: 1st string to compare
 * @s2: 2nd string to compare
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	i++;
	}

	return (s1[i] - s2[i]);
}
