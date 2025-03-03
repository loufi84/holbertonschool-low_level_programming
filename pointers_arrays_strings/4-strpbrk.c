#include "main.h"
#define NULL ((void *) 0)

/**
 * _strpbrk - searh a string for a set of bytes
 * @s: string to search
 * @accept: chars to match
 * Return: pointer to s
 */

char *_strpbrk(char *s, char *accept)
{
	int index = 0;
	int check = 0;

	for (index = 0; s[index] != '\0'; index++)
	{
		for (check = 0; accept[check] != '\0'; check++)
		{
			if (s[index] == accept[check])
			{
				return (s + index);
			}
		}
	}

	return (NULL);
}
