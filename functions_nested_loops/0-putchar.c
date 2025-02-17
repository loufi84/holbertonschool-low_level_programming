#include "main.h"

/**
 * main - Entrt point
 * Return: Always 0 (Success)
 */

int main(void)
{
	char str[] = "_putchar\n";
	int i = 0;

	for (; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (0);
}
