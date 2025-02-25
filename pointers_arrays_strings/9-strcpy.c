#include "main.h"

/**
 * _strcpy - copye a string
 * @dest: destination of the string
 * @src: source of the string
 * Description: This function will copy a string pointed by src including
 * the terminal null byte (\0) to a buffer pointed by dest
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}
