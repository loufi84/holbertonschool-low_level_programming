#include <stdio.h>

#define SPLIT 10000000000

/**
 * print_fib - print the Fibonacci number split
 * Return: void
 * @first: First part of Fibonacci numbers to avoid int overflow
 * @second: Second part of Fibonacci numbers to avoid int overflow
 */

void print_fib(unsigned long first, unsigned long second)
{
	if (first > 0)
		printf(", %lu%010lu", first, second);
	else
		printf(", %lu", second);
}

/**
 * main - Entry point
 * Description: This program will print the first
 * 98 numbers of Fibonacci
 * Return: 0
 */

int main(void)
{
	int i;
	unsigned long fib1_first = 0;
	unsigned long fib1_second = 1;
	unsigned long fib2_first = 0;
	unsigned long fib2_second = 2;
	unsigned long next_first;
	unsigned long next_second;

	printf("%lu, %lu", fib1_second, fib2_second);

	for (i = 2; i < 98; i++)
	{

	next_second = fib1_second + fib2_second;
	next_first = fib1_first + fib2_first;

	if (next_second >= SPLIT)
	{
		next_first += next_second / SPLIT;
		next_second %= SPLIT;
	}

	print_fib(next_first, next_second);

	fib1_first = fib2_first;
	fib1_second = fib2_second;
	fib2_first = next_first;
	fib2_second = next_second;

	}

	printf("\n");

	return (0);
}
