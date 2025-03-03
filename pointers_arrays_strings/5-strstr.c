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
	int i;
	int match_i;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			match_i = 1;
			while (needle[match_i] != '\0' && haystack[i + match_i] == needle[match_i])
			{
				match_i++;
			}

			if (needle[match_i] == '\0')
			{
				return (haystack + i);
			}
		}
	}

	return (NULL);
}
