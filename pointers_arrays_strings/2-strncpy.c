#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination buffer
 * @src: string source
 * @n: number of bytes
 * Return: char
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; src[i] != '\0' && i < n; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
