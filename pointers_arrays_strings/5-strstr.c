#include "main.h"
#define NULL ((void *) 0)

/**
 * _strstr - locates a substring
 * @haystack: string to check
 * @needle: string to search
 * Return: pointer
 */

char *_strstr(char *haystack, char *needle)
{
	int index = 0;
	int check = 0;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (index = 0; haystack[index] != '\0'; index++)
	{
		if (haystack[index] == needle[check])
		{
			int match = 1;

			for (check = 1; needle[check] != '\0'; check++)
			{
				if (haystack[index + check] != needle[check])
				{
					match = 0;
					break;
				}
			}
			if (match)
			{
				return (haystack + index);
			}

		}
	}

	return (NULL);
}
