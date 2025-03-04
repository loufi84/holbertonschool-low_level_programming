#include "main.h"

/**
 * wildcmp - compares two string
 * Description: This function will compare 2 string,
 * and returns 1 if identical, 0 otherwise
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: 1 for identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		return (*s1 == '\0');
	}

	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	if (*s1 != '\0' && (*s1 == *s2))
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
