#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 * Return: 0 for success
 */

int main(void)
{
	unsigned long num = 612852475143;
	unsigned long factor = 0;
	unsigned long index = 0;

	while (num % 2 == 0)
	{
		num = num / 2;
		factor = 2;
	}

	for (index = 3; index <= sqrt(num); index += 2)
	{
		if (num % index == 0)
		{
			num = num / index;
			factor = index;
		}
	}

	if (num > 1)
	{
		factor = num;
	}

	printf("%lu\n", factor);

	return (0);
}
