#include <stdio.h>

/**
 * main - Entry point
 * Description: This program will print the sum of all even numbers
 * of a Fibonacci sequence without exceeding 4,000,000
 * Return: int
 */

int main(void)
{
	unsigned long fib1 = 1;
	unsigned long fib2 = 2;
	unsigned long next = 0;
	unsigned long sum = 0;

	printf("%lu", fib2);

	while (next < 4000000)
	{

		next = fib1 + fib2;

		if (next % 2 == 0)
		{
			sum += next;
		}

		fib1 = fib2;
		fib2 = next;
	}

	printf("%lu", sum);
	printf("\n");

	return (0);
}
