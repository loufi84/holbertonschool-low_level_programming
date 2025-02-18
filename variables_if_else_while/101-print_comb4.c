#include <stdio.h>

/**
 * main - Entry point
 * Return: digits
 */

int main(void)
{
	int first_digit;
	int second_digit;
	int last_digit;

	for (first_digit = 0; first_digit < 9; first_digit++)
	{
		for (second_digit = first_digit + 1; second_digit < 10; second_digit++)
		{
			for (last_digit = second_digit + 1; last_digit < 10; last_digit++)
			{
				putchar(48 + first_digit);
				putchar(48 + second_digit);
				putchar(48 + last_digit);

				if (first_digit != 7 || second_digit != 8 || last_digit != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
