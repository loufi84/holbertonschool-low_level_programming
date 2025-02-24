#include "main.h"

/**
 * _strlen - return the lengthbof a string
 * @s: string
 * Return: int
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);

}
