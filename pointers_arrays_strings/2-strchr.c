#include "main.h"
#define NULL ((void *)0)

/**
 * _strchr - locate a character in a string
 * @s: string to search in
 * @c: character to locate
 * Return: pointer to s
 */

char *_strchr(char *s, char c)
{
	int index = 0;

	for (index = 0; s[index] != '\0'; index++)
	{

		if (s[index] == c)
		{
			return (&s[index]);
		}

	}

	if (c == '\0')
	{
		return (&s[index]);
	}

	return (NULL);
}
