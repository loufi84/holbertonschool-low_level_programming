#include <stdio.h>

/**
 * main - Entry point
 * Description: print the alphabet excluding q and e
 * Return: Always 0 (Success)
 */

int main(void)
{
	char char_var = 'a';

	for (; char_var <= 'z'; char_var++)
	{
		if (char_var != 'e' && char_var != 'q')
		{
			putchar(char_var);
		}
	}

	printf("\n");

	return (0);
}
