#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Return the sum of all parameters
 * @n: The numbers to add
 * Return: The sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum;

	va_start(ap, n);


	if (n == 0)
		return (0);

	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);

	va_end(ap);
	return (sum);

}
