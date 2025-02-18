#include "main.h"

/**
 * print_to_98 - print all natural numbers from n to 98
 * Return: all int from n to 98
 * @n: your first number
 */

void print_to_98(int n)
{
	for (; n <= 98; n++)
	{
		_putchar(n + '0');
		_putchar(',');
		_putchar(' ');
	}
}

