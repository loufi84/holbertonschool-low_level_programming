#include "main.h"

/**
 * _isupper - check uppercase
 * Description : This function checks if a char is uppercase
 * @c: char to check
 * Return: 1 if char is uppercase
 */

int _isupper(int c)
{

	if (c >= 65 && c <= 90)
	{
		return (1);
	}

	return (0);
}
