#include "main.h"

/**
 * puts_half - print 2nd half of string
 * @str: input string
 * Return: void
 */

void puts_half(char *str)
{
	int i;
	int start = 0;

	for (i = 0; str[i] != '\0'; i++)

	if (i / 2 != 0)
	{
		start = (i - 1) / 2;
	}
	else
	{
		start = i / 2;
	}

	for (i = start; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
