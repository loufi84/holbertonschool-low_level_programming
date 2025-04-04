#include "main.h"

/**
 * print_line - print a line
 * Description: This function will print a line using
 * _ char n time
 * @n: numbers of time _ must be printed
 * Return: void
 */

void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	}

	while (n > 0)
	{
		_putchar('_');
		n--;
		if (n == 0)
		{
			_putchar('\n');
		}
	}
}
