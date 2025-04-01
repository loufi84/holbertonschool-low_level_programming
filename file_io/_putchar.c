#include <stdlib.h>

/**
 * _putchar - Prints a single character on stdout
 *
 * @c: The character to print
 *
 * Return: The printed character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
