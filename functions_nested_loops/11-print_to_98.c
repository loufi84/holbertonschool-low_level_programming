#include "main.h"

/**
 * print_to_98 - print all natural numbers from n to 98
 * Return: all int from n to 98
 * @n: your first number
 */

void print_to_98(int n)
{

	int first_digit = 0;
	int last_digit = 0;

	for (; n <= 98; n++)
	{
		_putchar('0' + n);

		if (n > 10)
		{
			first_digit = n / 10;
			last_digit = n % 10;
			_putchar(first_digit);
			_putchar(last_digit);
		}

		if (n != 98)
		{
			_putchar(',');
			_putchar(' ');
		}
	}
}
