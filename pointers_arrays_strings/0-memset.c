#include "main.h"

/**
 * _memset - fills n bytes
 * @s: memory area
 * @b: constant byte
 * @n: n bytes of memory
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index = 0;

	while (index < n)
	{
		s[index] = b;
		index++;
	}

	return (s);
}
