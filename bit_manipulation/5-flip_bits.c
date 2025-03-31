#include "main.h"

/**
 * flip_bits - A function that count the number of bits differing from 2 int
 *
 * @n: The 1st number
 * @m: The 2nd number
 *
 * Return: The number of bits different
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int res = n ^ m;
	unsigned int count = 0;

	while (res != 0)
	{
		res &= (res - 1);
		count++;
	}
	return (count);
}
