#include "main.h"

/**
 * print_alphabet - Entry point
 * Return: Always 0 (Success)
 */

int print_alphabet(void)
{
	char str[] = "abcdefghijklmnopqrstuvwxyz\n";
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (0);
}
