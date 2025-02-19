#include <stdio.h>

/**
 * main - Entry point
 * Description: print all combinations of two two digits numbers
 * separated by a space, all combinations are separated by commas
 * Return: digits combinations
 */


int main(void)
{
	int first_number;
	int second_number;

	for (first_number = 0; first_number < 99; first_number++)
	{

		for (second_number = first_number + 1; second_number < 100; second_number++)
		{
			putchar(48 + (first_number / 10));
			putchar(48 + (first_number % 10));
			putchar(' ');
			putchar(48 + (second_number / 10));
			putchar(48 + (second_number % 10));

			if (first_number != 98 || second_number != 99)
			{
				putchar(',');
				putchar(' ');
			}
		}


	}

	putchar('\n');

	return (0);
}
