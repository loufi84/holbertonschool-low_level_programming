#include "main.h"

/**
 * get_endianness - A function that check for Big and Little Endian
 *
 * Return: 1 for Little Endian, 0 for Big Endian
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *) &x;

	return (*c);
}
