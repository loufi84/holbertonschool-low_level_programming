#include "main.h"

/**
 * print_number - print an int
 * @n: int to print
 * Return: void
 */

void print_number(int n)
{
	int num;
	int divisor = 1;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num / divisor >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		_putchar((num / divisor) + '0');
		num %= divisor;
		divisor /= 10;
	}
}
