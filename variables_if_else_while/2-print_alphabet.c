#include <stdio.h>

/**
 * main - Entry point
 * Description: This program displays the alphabet using putchar
 * Return: Always 0 (Success)
 */

int main(void)
{
	char char_var = 'a';

	for (; char_var <= 'z'; char_var++)
	{
		putchar(char_var);
	}

	printf("\n");

	return (0);
}
