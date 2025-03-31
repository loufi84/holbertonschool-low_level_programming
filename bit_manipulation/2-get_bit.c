#include "main.h"

/**
 * get_bit - A function that returns the value of a bit at index position
 *
 * @n: The number to check
 * @index: The position asked
 *
 * Return: The value of the bit (-1 if fail)
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int res, val;

	if (index > sizeof(unsigned int) * 8)
		return (-1);

	res = n >> index;
	val = res & 1;

	return (val);
}
