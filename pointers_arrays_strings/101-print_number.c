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

	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		n = 147483648;
	}

	else if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	num = n;

	while (num > 9)
	{
		divisor *= 10;
		num /= 10;
	}

	while (divisor > 0)
	{
		_putchar((n / divisor) + '0');
		n %= divisor;
		divisor /= 10;

	}
}
