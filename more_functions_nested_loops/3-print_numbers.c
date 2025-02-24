#include "main.h"

/**
 * print_numbers - print numbers
 * Description: This function print numbers from
 * 0 to 9
 * Return: void
 */

void print_numbers(void)
{
	int i = 0;

	for (; i < 10; i++)
	{
		_putchar('0' + i);
	}

	_putchar('\n');
}
