#include "main.h"

/**
 * print_alphabet_x10 - Entry point
 * Return: Always 0 (Success)
 */

void print_alphabet_x10(void)
{
	char c = 'a';
	int i = 0;

	do {
		for (; c <= 'z'; c++)
		{
			_putchar(c);
		}

		_putchar('\n');
	} while (i < 10);
}
