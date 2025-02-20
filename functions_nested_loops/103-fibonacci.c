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


	while (fib2 < 4000000)
	{

		if (fib2 % 2 == 0)
		{
			sum += fib2;
		}

		next = fib1 + fib2;

		fib1 = fib2;
		fib2 = next;
	}

	printf("%lu\n", sum);

	return (0);
}
