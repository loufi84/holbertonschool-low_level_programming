#include "main.h"

/**
 * puts2 - print every other char of a string
 * @str: input string
 * Return: void
 */

void puts2(char *str)
{
	int len;
	int i = 0;

	for (len = 0; str[len] != '\0'; len++)
	{
		while (i < len)
		{
			_putchar(str[i]);
			i += 2;
		}
	}
	_putchar('\n');
}
