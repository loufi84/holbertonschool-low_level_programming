#include "main.h"

/**
 * add - add two integers together
 * Return: an int
 * @a: first number
 * @b: second number
 */

int add(int a, int b)
{
	int result = 0;

	result = a + b;

	if (result >= 10)
	{
		_putchar('0' + (result / 10));
		_putchar('0' + (result % 10));
	}

	return (result);
}
