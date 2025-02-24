#include "main.h"

/**
 * _isdigit - check if a char is a digit
 * Description: This function will check if a given c char
 * is a digit
 * @c: char to check
 * Return: 1 if char is a digit
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}

	return (0);
}
