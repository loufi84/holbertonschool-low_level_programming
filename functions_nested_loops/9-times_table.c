#include "main.h"

/**
 * time_tables - print 9 times tables
 * Return: all time tables
 */

void time_tables(void)
{
	int i = 0;
	int table = 0;
	int result = 0;
	int last_digit = 0;
	int first_digit = 0;

	for (; i < 10; i++)
	{
		for (table = 0; table < 10; table++)
		{
			result = i * table;
			if (result > 9)
			{
				first_digit = result / 10;
				last_digit = result % 10;
				_putchar('0' + first_digit);
				_putchar('0' + last_digit);
			}
			else
			{
				if (table != 0)
				{
					_putchar(' ');
				}

				_putchar('0' + result);
			}

			if (table != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
