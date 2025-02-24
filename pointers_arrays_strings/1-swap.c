#include "main.h"

/**
 * swap_int - swap 2 int using pointers
 * @a: 1st int
 * @b: 2sd int
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
