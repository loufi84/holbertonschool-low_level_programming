#include <unistd.h>
#include "lists.h"

/**
 * _putchar - A function to print a character to stdout
 *
 * @c: The character to print
 *
 * Return: A character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
