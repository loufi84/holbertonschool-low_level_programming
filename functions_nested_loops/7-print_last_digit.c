#include "main.h"

/**
 * print_last_digit - print the last digit of an int
 * @n: the enter int
 * Return: last digit
 */

int print_last_digit(int n)
{
	if (n < 0)
	{
		n = -n;
	}

	_putchar('0' + (n % 10));
	return (n % 10);
}
