#include "main.h"

/**
 * reverse_array - reverse the content of an array
 * @a: the array to be reversed
 * @n: the number of elements of the array
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i;
	int j;
	int tmp;


	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
