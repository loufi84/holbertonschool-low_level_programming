#include "main.h"

/**
 * _islower - returns 1 if a letter is lowercase, 0 if not
 * @c: entry parameter from main
 * Return: 1 for lowercase else 0
 */

int _islower(int c)
{

	if (c >= 97 && c <= 122)
	{
		return (1);
	}

	return (0);
}
