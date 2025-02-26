#include "main.h"

/**
 * print_number - print an int
 * @n: int to print
 * Return: void
 */

void print_number(int n)
{
	int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num == 0)
	{
		_putchar('0');
	}

	else
	{
		if (num / 10 != 0)
		{
			print_number(num / 10);
		}
		_putchar(num % 10 + '0');
	}
}
