#include "3-calc.h"
#include <stdio.h>

/**
 * op_add - Addition operator
 * @a: 1st element
 * @b: 2nd element
 * Return: The sum of a + b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Substraction operator
 * @a: 1st element
 * @b: 2nd element
 * Return: The result of a - b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplication operator
 * @a: 1st element
 * @b: 2nd element
 * Return: The result of a * b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Division operator
 * @a: 1st element
 * @b: 2nd element
 * Return: The result of a / b
 */

int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Modulus operator
 * @a: 1st element
 * @b: 2nd element
 * Return: The result of a % b
 */

int op_mod(int a, int b)
{
	return (a % b);
}
