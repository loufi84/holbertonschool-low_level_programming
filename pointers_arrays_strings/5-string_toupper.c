#include "main.h"

/**
 * string_toupper - changes lowercase to uppercase
 * Description: Takes a pointer to a string
 * and modifies it in place
 * @str: string to modify
 * Return: pointer to the modified string
 */

char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}

	return (str);
}
