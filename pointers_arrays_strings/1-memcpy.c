#include "main.h"

/**
 * _memcpy - copy n bytes from src to dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index = 0;

	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}

	return (dest);
}
