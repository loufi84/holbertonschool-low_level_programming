#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i = 0;

	for (; i < 10; i++)
	{
		putchar(i + '0');
	}

	printf("\n");

	return (0);
}
