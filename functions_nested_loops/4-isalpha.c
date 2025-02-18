#include "main.h"

/**
 * _isalpha - check if a character is alphanumerical
 * @c: entry character from main
 * Return: 1 if alphanumerical, else 0
 */

int _isalpha(int c)
{

	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}

	return (0);
}
