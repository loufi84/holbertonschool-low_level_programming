#include "main.h"

/**
 * print_alphabet_x10 - Entry point
 * Return: Always 0 (Success)
 */

void print_alphabet_x10(void)
{
	char c;
	int i = 0;

	do {
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}

		_putchar('\n');
		i++;
	} while (i < 10);
}
