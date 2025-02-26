#include "main.h"

/**
 * leet - replaces some char by int
 * @str: string to modify
 * Return: A pointer to the modified string
 */

char *leet(char *str)
{
	int i;
	int j;
	char leetn[] = "aAeEoOtTlL";
	char rep[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leetn[j] != '\0'; j++)
		{
			if (str[i] == leetn[j])
			{
				str[i] = rep[j];
			}
		}
	}

	return (str);
}
