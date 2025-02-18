#include <stdio.h>

/**
 * main - Entry point
 * Return: every two digits characters
 */

int main(void)
{
	int first_digit;
	int last_digit;

	for (first_digit = 0; first_digit < 9; first_digit++)
	{
		for (last_digit = first_digit + 1; last_digit < 10; last_digit++)
		{
			putchar(48 + first_digit);
			putchar(48 + last_digit);

			if (first_digit != 8 || last_digit != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
