#include "lists.h"

/**
 * dlistint_len - A function that return the length of a list
 *
 * @h: The beginning of the list
 *
 * Return: The elements of the list
 */

size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *curr = h;

	while (curr)
	{
		count++;
		curr = curr->next;
	}

	return (count);
}
