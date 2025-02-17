#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i = 0;
	char char_var = 'a';

	for (; i < 10; i++)
	{
		putchar(i + '0');
	}


	for (; char_var <= 'f'; char_var++)
	{
		putchar(char_var);
	}

	putchar('\n');

	return (0);
}
