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
	char *ptr = str;
	char *orig = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	int i;

	while (*ptr)
	{
		for (i = 0; orig[i]; i++)
		{
			if (*ptr == orig[i])
			{
				*ptr = rot[i];
				break;
			}
		}

		ptr++;
	}

	return (ptr);
}
