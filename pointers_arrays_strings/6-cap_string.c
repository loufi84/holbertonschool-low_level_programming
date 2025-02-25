#include "main.h"

/**
 * cap_string - capitalize a string
 * @str: The string that needs capitalization
 * Description: This function will capitalize all
 * words of a string using certain separators
 * Return: a pointer to the capitalized string
 */

char *cap_string(char *str)
{
	int i = 0;
	int j = 0;
	char sep[] = " \t\n,;.!?\"(){}";

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	for (; str[i] != '\0'; i++)
	{
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i] == sep[j])
			{
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				{
					str[i + 1] -= 32;
				}
				break;
			}
		}
	}

	return (str);
}
