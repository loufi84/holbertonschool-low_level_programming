#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	char char_var = 'z';

	for (; char_var >= 'a'; char_var--)
	{
		putchar(char_var);
	}

	putchar('\n');

	return (0);
}
