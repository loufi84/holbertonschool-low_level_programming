#include "main.h"

/**
 * _strncat - concatenates n char of 2 strings
 * @dest: The destination string
 * @src: The string that we concatenate
 * @n: Numbers of char from 2nd string
 * Return: char
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	if (src[j] < n)
		dest[i] = '\0';

	return (dest);
}
