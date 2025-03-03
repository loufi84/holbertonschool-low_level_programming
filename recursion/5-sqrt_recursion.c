#include "main.h"

/**
 * _sqrt_compute - find the sqrt
 * @n: number to find sqrt
 * @g: Current guess for sqrt
 * Return: int sqrt
 */

int _sqrt_compute(int n, int g)
{
	if (g * g == n)
	{
		return (g);
	}
	if (g * g > n)
	{
		return (-1);
	}

	return (_sqrt_compute(n, g + 1));
}

/**
 * _sqrt_recursion - returns natural square root
 * @n: number to check
 * Return: int sqrt
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (_sqrt_compute(n, 1));
}
