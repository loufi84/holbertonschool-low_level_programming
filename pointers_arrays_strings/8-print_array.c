#include "main.h"
#include <stdio.h>

/**
 * print_array - print an array
 * @a: array of origin
 * @n: number of elemebts to be printed
 * Return: void
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
	}

	printf("\n");
}
