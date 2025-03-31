#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - A function that prints all elements of a list
 *
 * @h: The beginning of the list
 *
 * Return: The number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *curr = h;

	while (curr)
	{
		printf("%d\n", curr->n);
		count++;
		curr = curr->next;
	}

	return (count);
}
