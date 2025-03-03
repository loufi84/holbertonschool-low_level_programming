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
	int match_index = 0;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (index = 0; haystack[index] != '\0'; index++)
	{
		if (haystack[index] == needle[match_index])
		{

			int match = 1;

			for (match_index = 1; needle[match_index] != '\0'; match_index++)
			{
				if (haystack[index + match_index] != needle[match_index])
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
