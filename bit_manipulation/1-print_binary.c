#include "main.h"

/**
 * print_binary - A function that prints a binary number from an int
 *
 * @n: The int to converts and print
 *
 * Return: Nothing
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int found = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			found = 1;
		}
		else if (found)
			_putchar('0');

		mask >>= 1;
	}
}
