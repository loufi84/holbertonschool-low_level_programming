#include <stdio.h>

/**
 * main - Entry point
 * Return: every two digits characters
 */

int main(void)
{
	int i = 1;
	int first_digit = 0;
	int last_digit = 0;

	for (; i < 100; i++)
	{
		first_digit = i / 10;
		last_digit = i % 10;

		if (first_digit < last_digit)
		{
			putchar(48 + first_digit);
			putchar(48 + last_digit);
		}

		if (first_digit != 8 || last_digit != 9)
		{
			putchar(',');
			putchar(' ');
		}

	}

	putchar('\n');

	return (0);
}
