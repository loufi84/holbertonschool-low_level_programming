#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the args of the program
 * @ac: Arguments count
 * @av: Arguments values
 * Return: Pointer to new str
 */

char *argstostr(int ac, char *av[])
{
	char *str;
	int index, copi, copj;
	int len = 0;
	int tot_len = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (index = 0; index < ac; index++)
	{
		for (; av[index][len] != '\0'; len++)
		{}
		tot_len += len + 1;
	}

	str = (char *)malloc(sizeof(char) * tot_len);
	if (str == NULL)
	{
		return (NULL);
	}

	copj = 0;
	for (copi = 0; copi < ac; copi++)
	{
		for (len = 0; av[copi][len] != '\0'; len++)
		{
			str[copj++] = av[copi][len];
		}
		str[copj++] = '\n';
	}

	str[copj] = '\0';

	return (str);
}
