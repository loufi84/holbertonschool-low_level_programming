#include <stdio.h>

/**
 * main - Entry point
 * Description: This program will print the 50 first
 * Fibonacci's numbers starting with 1 and 2
 * Return: int
 */

int main(void)
{
	int i;
	unsigned long fib1 = 1, fib2 = 2, next;

	printf("%lu, %lu", fib1, fib2);

	for (i = 2; i < 50; i++)
	{
		next = fib1 + fib2;
		printf(", %lu", next);
		fib1 = fib2;
		fib2 = next;
	}

	printf("\n");

	return (0);
}
