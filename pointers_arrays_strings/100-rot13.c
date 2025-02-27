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
	int i, j;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (str[i] == alpha[j])
			{
				str[i] = rot[j];
				break;
			}
		}
	}

	return (str);
}
