#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_list - A function that prints the nodes of a list
 *
 * @h: The beginning of the list
 *
 * Return: The number of elements in the list
 */

size_t print_list(const list_t *h)
{
	int count = 0;

	const list_t *curr = h;

	while (curr)
	{
		if (curr->str)
			printf("[%u] %s\n", curr->len, curr->str);

		else
			printf("[0] (nil)\n");

		count++;
		curr = curr->next;
	}
	return (count);
}
