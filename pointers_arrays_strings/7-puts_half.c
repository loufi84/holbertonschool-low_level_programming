#include "main.h"

/**
 * puts_half - print 2nd half of string
 * @str: input string
 * Return: void
 */

void puts_half(char *str)
{
	int i;
	int len = 0;
	int start;

	while (str[len] != '\0')
	{
		len++;
	}

	start = (len % 2 == 0) ? len / 2 : (len - 1) / 2;

	for (i = start; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
