#include <unistd.h>

/**
 * _putchar - Prints a character to the stdout
 * @c: The character to print
 * Return: On success 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
