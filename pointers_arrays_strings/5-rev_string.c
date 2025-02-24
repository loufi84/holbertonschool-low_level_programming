#include "main.h"

/**
 * rev_string - reverse a string
 * @s: string to reverse
 * Return: void
 */

void rev_string(char *s)
{
	int i;
	int j;
	int len = 0;
	char tmp;

	while (s[len] != '\0')
		len++;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
