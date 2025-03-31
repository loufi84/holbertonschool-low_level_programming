#include "main.h"

int get_bit(unsigned long int n, unsigned int index)
{
	int res, val;

	if (index > sizeof(unsigned int) * 8)
		return (-1);

	res = n >> index;
	val = res & 1;

	return (val);
}
