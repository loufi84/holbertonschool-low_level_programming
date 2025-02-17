#include "main.h"

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	char str[] = "abcdefghijklmnopqrstuvwxyz\n";
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (0);
}
