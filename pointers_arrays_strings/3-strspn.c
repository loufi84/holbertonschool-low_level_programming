#include "main.h"

/**
 * _strspn - get the length of prefix substring
 * @s: initial segment
 * @accept: comparison
 * Return: Always 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int index = 0;
	unsigned int check = 0;
	unsigned int count = 0;

	for (index = 0; s[index] != '\0'; index++)
	{
		int match = 0;

		for (check = 0; accept[check] != '\0'; check++)
		{
			if (s[index] == accept[check])
			{
				match = 1;
				break;
			}
		}

		if (match)
		{
			count++;
		}
		else
		{
			break;
		}
	}

	return (count);
}
