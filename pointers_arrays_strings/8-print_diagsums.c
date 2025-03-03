#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - print the sum of 2 diagonals
 * @a: pointer to arrays
 * @size: size of diagonal
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	int index = 0;
	int sum1 = 0;
	int sum2 = 0;

	for (index = 0; index < size; index++)
	{
		sum1 += a[index * size + index];

		sum2 += a[index * size + (size - 1 - index)];
	}

	printf("%d, %d\n", sum1, sum2);
}
