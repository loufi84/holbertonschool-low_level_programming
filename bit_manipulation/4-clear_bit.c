#include "main.h"

/**
 * clear_bit - A function that set the bit at n position to 0
 *
 * @n: The number to check
 * @index: The position of the bit
 *
 * Return: 1 for success, -1 for failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned int) * 8)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
