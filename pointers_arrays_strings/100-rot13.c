#include "main.h"

/**
 * rot13 - encode s string
 * @str: The string to encode
 * Description: This function will encode a string
 * of characters, rotating them to 13 places
 * Return: A pointer to the string
 */

char *rot13(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
		{
			str[i] += 13;
		}

		for (; (str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z');)
		{
			str[i] -= 13;
			break;
		}
		i++;
	}

	return (str);
}
