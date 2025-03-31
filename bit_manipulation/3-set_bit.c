#include "main.h"

/**
 * set_bit - A function that sets the bit at n position to 1
 *
 * @n: The number to check
 * @index: The position of the bit
 *
 * Return: 1 for success, -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned int) * 8)
		return (-1);

	*n |= (1UL << index);
	return (1);
}
