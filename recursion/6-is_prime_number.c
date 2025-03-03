#include "main.h"

/**
 * _check_prime - check if n is a prime
 * @n: Number to check
 * @i: Divisor to check
 * Return: 1 if prime, else 0
 */

int _check_prime(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}

	if (n % i == 0)
	{
		return (0);
	}

	return (_check_prime(n, i + 1));
}

/**
 * is_prime_number - check if an int is a prime num
 * @n: number to check
 * Return: 1 if true, otherwise 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (_check_prime(n, 2));
}
