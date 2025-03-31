#include "main.h"
#include <stdlib.h>

/**
 * binary_to_uint - A function to convert binary to unsigned int
 *
 * @b: The string of binaries to convert
 *
 * Return: The result in base 10 (or 0 if fail)
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = (result << 1) | (*b - '0');
		b++;
	}
	return (result);
}
